#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM_MEMORIA 100
#define FIM_DO_PROGRAMA -99999
#define MAX_VALOR_WORD 9999
#define MIN_VALOR_WORD -9999

typedef enum {
    READ = 10, WRITE = 11,
    LOAD = 20, STORE = 21,
    ADD = 30, SUBTRACT = 31, DIVIDE = 32, MULTIPLY = 33,
    BRANCH = 40, BRANCHNEG = 41, BRANCHZERO = 42,
    HALT = 43,
    MODULO = 44,
    EXP = 45,
    READ_STRING = 46,
    WRITE_STRING = 47,
    NEWLINE = 48,
} Opcode;

typedef enum {
    ERR_NONE = 0,
    ERR_INPUT,
    ERR_DIVZERO,
    ERR_INTOVERFLOW,
    ERR_INVALID_OPCODE,
    ERR_INVALID_OPERAND,
    ERR_MEMORY_ACCESS
} ExitCode;

typedef struct {
    int memoria[TAM_MEMORIA];
    int acumulador;
    int contadorInstrucao;
    int instrucao;
    int operacao;
    int operando;
} Simpletron;

void inicializar(Simpletron *simp) {
    for (int i = 0; i < TAM_MEMORIA; i++) simp->memoria[i] = 4300; 
    simp->acumulador = 0;
    simp->contadorInstrucao = 0;
    simp->instrucao = 0;
    simp->operacao = 0;
    simp->operando = 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool operandoValido(int operando) {
    return operando >= 0 && operando < TAM_MEMORIA;
}

// Função para carregar programa (pode ser stdin ou arquivo)
int carregarPrograma(Simpletron *simp, FILE *entrada) {
    int local = 0, palavra;
    printf("*** Carregue seu programa no Simpletron ***\n");
    printf("*** Digite %d para encerrar o carregamento ***\n", FIM_DO_PROGRAMA);

    while (local < TAM_MEMORIA) {
        printf("%02d ? ", local);
        if (fscanf(entrada, "%d", &palavra) != 1) {
            fprintf(stderr, "Entrada invalida, tente novamente.\n");
            limparBuffer();
            continue;
        }
        if (palavra == FIM_DO_PROGRAMA) break;

        if (palavra < MIN_VALOR_WORD || palavra > MAX_VALOR_WORD) {
            printf("Numero invalido, deve estar entre %d e %d.\n", MIN_VALOR_WORD, MAX_VALOR_WORD);
            continue;
        }

        simp->memoria[local++] = palavra;
    }
    printf("*** Programa carregado com sucesso! ***\n");
    return local;
}

ExitCode fetch(Simpletron *simp) {
    if (simp->contadorInstrucao < 0 || simp->contadorInstrucao >= TAM_MEMORIA)
        return ERR_MEMORY_ACCESS;

    simp->instrucao = simp->memoria[simp->contadorInstrucao];
    simp->operacao = simp->instrucao / 100;
    simp->operando = simp->instrucao % 100;

    if (simp->operacao != HALT && !operandoValido(simp->operando))
        return ERR_INVALID_OPERAND;

    return ERR_NONE;
}

ExitCode executarInstrucao(Simpletron *simp) {
    switch (simp->operacao) {
        case READ: {
            int valor;
            printf("Entrada para posicao %02d: ", simp->operando);
            if (scanf("%d", &valor) != 1) {
                limparBuffer();
                return ERR_INPUT;
            }
            if (valor < MIN_VALOR_WORD || valor > MAX_VALOR_WORD)
                return ERR_INPUT;
            simp->memoria[simp->operando] = valor;
            simp->contadorInstrucao++;
            break;
        }
        case WRITE:
            printf("Saida da posicao %02d: %d\n", simp->operando, simp->memoria[simp->operando]);
            simp->contadorInstrucao++;
            break;
        case LOAD:
            simp->acumulador = simp->memoria[simp->operando];
            simp->contadorInstrucao++;
            break;
        case STORE:
            simp->memoria[simp->operando] = simp->acumulador;
            simp->contadorInstrucao++;
            break;
        case ADD: {
            long long resultado = (long long)simp->acumulador + simp->memoria[simp->operando];
            if (resultado > MAX_VALOR_WORD || resultado < MIN_VALOR_WORD)
                return ERR_INTOVERFLOW;
            simp->acumulador = (int)resultado;
            simp->contadorInstrucao++;
            break;
        }
        case SUBTRACT: {
            long long resultado = (long long)simp->acumulador - simp->memoria[simp->operando];
            if (resultado > MAX_VALOR_WORD || resultado < MIN_VALOR_WORD)
                return ERR_INTOVERFLOW;
            simp->acumulador = (int)resultado;
            simp->contadorInstrucao++;
            break;
        }
        case DIVIDE:
            if (simp->memoria[simp->operando] == 0) return ERR_DIVZERO;
            simp->acumulador /= simp->memoria[simp->operando];
            simp->contadorInstrucao++;
            break;
        case MULTIPLY: {
            long long resultado = (long long)simp->acumulador * simp->memoria[simp->operando];
            if (resultado > MAX_VALOR_WORD || resultado < MIN_VALOR_WORD)
                return ERR_INTOVERFLOW;
            simp->acumulador = (int)resultado;
            simp->contadorInstrucao++;
            break;
        }
        case BRANCH:
            simp->contadorInstrucao = simp->operando;
            break;
        case BRANCHNEG:
            if (simp->acumulador < 0)
                simp->contadorInstrucao = simp->operando;
            else
                simp->contadorInstrucao++;
            break;
        case BRANCHZERO:
            if (simp->acumulador == 0)
                simp->contadorInstrucao = simp->operando;
            else
                simp->contadorInstrucao++;
            break;
        case HALT:
            return ERR_NONE;
        case MODULO:
            if (simp->memoria[simp->operando] == 0) return ERR_DIVZERO;
            simp->acumulador %= simp->memoria[simp->operando];
            simp->contadorInstrucao++;
            break;
        case EXP: {
            int base = simp->acumulador;
            int expoente = simp->memoria[simp->operando];
            if (expoente < 0) return ERR_INVALID_OPCODE;
            long long resultado = 1;
            for (int i = 0; i < expoente; i++) {
                resultado *= base;
                if (resultado > MAX_VALOR_WORD || resultado < MIN_VALOR_WORD)
                    return ERR_INTOVERFLOW;
            }
            simp->acumulador = (int)resultado;
            simp->contadorInstrucao++;
            break;
        }
        case NEWLINE:
            printf("\n");
            simp->contadorInstrucao++;
            break;
        case READ_STRING: {
		    printf("Digite uma string para a posiçao inicial %02d (max 20 caracteres): ", simp->operando);
		    char buffer[21]; 
		    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
		        return ERR_INPUT;
		    }
		    size_t len = strlen(buffer);
		    if (len > 0 && buffer[len-1] == '\n') {
		        buffer[len-1] = '\0';
		        len--;
		    }
		    for (size_t i = 0; i <= len; i++) {
		        if (simp->operando + (int)i >= TAM_MEMORIA) {
		            return ERR_INVALID_OPERAND;
		        }
		        simp->memoria[simp->operando + i] = (int)buffer[i]; 
		    }
		    simp->contadorInstrucao++;
		    break;
		}

        case WRITE_STRING: {
            printf("Saida da string na posicao inicial %02d: ", simp->operando);
            int pos = simp->operando;
            while (pos < TAM_MEMORIA && simp->memoria[pos] != 0) {
                putchar((char)(simp->memoria[pos]));
                pos++;
            }
            printf("\n");
            simp->contadorInstrucao++;
            break;
        }
        default:
            return ERR_INVALID_OPCODE;
    }
    return ERR_NONE;
}

ExitCode executar(Simpletron *simp, bool trace) {
    ExitCode err;

    while (true) {
        err = fetch(simp);
        if (err != ERR_NONE) return err;

        if (trace) {
            fprintf(stderr, "%02d: %+05d (Op: %02d, Oper: %02d, Acc: %+05d)\n",
                    simp->contadorInstrucao, simp->instrucao, simp->operacao, simp->operando, simp->acumulador);
        }

        err = executarInstrucao(simp);
        if (err == ERR_NONE && simp->operacao == HALT)
            return ERR_NONE;
        if (err != ERR_NONE)
            return err;
    }
}

void dump(const Simpletron *simp) {
    printf("\n--- ESTADO FINAL DA MAQUINA ---\n");
    printf("Acumulador: %+05d\n", simp->acumulador);
    printf("Contador de instrucao: %02d\n", simp->contadorInstrucao);
    printf("Ultima instrucao: %+05d\n", simp->instrucao);
    printf("Operacao: %02d\n", simp->operacao);
    printf("Operando: %02d\n", simp->operando);
    printf("\nMemoria:\n     ");
    for (int i = 0; i < 10; i++) printf("%5d ", i);
    printf("\n");
    for (int i = 0; i < TAM_MEMORIA; i++) {
        if (i % 10 == 0) printf("%02d   ", i);
        printf("%+05d ", simp->memoria[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
}

const char* getErrorMessage(ExitCode err) {
    switch (err) {
        case ERR_NONE: return "Execucao concluida sem erros.";
        case ERR_INPUT: return "Erro na entrada: valor invalido.";
        case ERR_DIVZERO: return "Erro de execução: divisao por zero.";
        case ERR_INTOVERFLOW: return "Erro de execucao: overflow ou underflow.";
        case ERR_INVALID_OPCODE: return "Erro: codigo de operacao invalido.";
        case ERR_INVALID_OPERAND: return "Erro: operando invalido.";
        case ERR_MEMORY_ACCESS: return "Erro: acesso invalido a memoria.";
        default: return "Erro desconhecido.";
    }
}

int main() {
    Simpletron simp;
    inicializar(&simp);

    printf("Bem-vindo ao Simpletron!\n");
    printf("Deseja carregar o programa:\n1 - Manualmente\n2 - De arquivo\nEscolha: ");

    int escolha;
    if (scanf("%d", &escolha) != 1 || (escolha != 1 && escolha != 2)) {
        fprintf(stderr, "Entrada invalida.\n");
        return 1;
    }
    limparBuffer();

    FILE *entrada = stdin;
    char nomeArquivo[100];
    if (escolha == 2) {
        printf("Digite o nome do arquivo (Ex:teste.txt): ");
        if (scanf("%99s", nomeArquivo) != 1) {
            fprintf(stderr, "Erro na leitura do nome do arquivo.\n");
            return 1;
        }
        limparBuffer();
        entrada = fopen(nomeArquivo, "r");
        if (!entrada) {
            fprintf(stderr, "Erro ao abrir arquivo '%s'\n", nomeArquivo);
            return 1;
        }
    }

    carregarPrograma(&simp, entrada);

    if (entrada != stdin) fclose(entrada);

    printf("Ativar modo debug? (0 = nao, 1 = sim): ");
    int debug;
    if (scanf("%d", &debug) != 1) debug = 0;
    limparBuffer();

    ExitCode err = executar(&simp, debug == 1);

    if (err != ERR_NONE) {
        fprintf(stderr, "\nErro na execucao: %s\n", getErrorMessage(err));
    } else {
        printf("\nExecucao finalizada com sucesso.\n");
    }

    dump(&simp);

    return (int)err;
}

