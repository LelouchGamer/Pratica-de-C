#include <stdio.h>
#include <string.h>

#define MAX_JOGADORES 100
#define MAX_STRING 50

struct Jogador {
    char nome[50];
    char dataNascimento[11];
    char cpf[12];
    char genero[20];
    char estadoCivil[20];

    struct {
        char nome[50];
        char nicknameRedeSocial[50];
        int numeroSeguidores;
    } equipe;


        char patrocinadoraPrincipal[50];
        char nicknameRedeSocial[50];
        int numeroSeguidores;


    struct {
        char modelo[50];
        char processador[50];
        char placaVideo[50];
        int quantidadeMemoriaRAM;
    } equipamentoHardware;

    struct {
        int pontuacaoCampeonato;
        int quantidadeVitorias;
        int quantidadeDerrotas;
        int quantidadeEmpates;
    } dadosCampeonato;

    int quantidadeTitulos;
    int posicaoRankMundial;
};

// Função para escrever dados de um jogador em um arquivo
void escreverJogador(struct Jogador *jogador, FILE *arquivo) {
    fwrite(jogador, sizeof(struct Jogador), 1, arquivo);
}


// Função para ler dados de um jogador de um arquivo
void lerJogador(struct Jogador *jogador, FILE *arquivo) {
    fread(jogador, sizeof(struct Jogador), 1, arquivo);
}



// Função para exibir dados de um jogador
void exibirDadosJogador(struct Jogador *jogador) {
    printf("  Nome: %s\n", jogador->nome);
    printf("  Data de Nascimento: %s\n", jogador->dataNascimento);
    printf("  CPF: %s\n", jogador->cpf);
    printf("  Genero: %s\n", jogador->genero);
    printf("  Estado Civil: %s\n", jogador->estadoCivil);
    printf("  Nome da equipe: %s\n", jogador->equipe.nome);
    printf("  Nickname da equipe na Rede Social: %s\n", jogador->equipe.nicknameRedeSocial);
    printf("  Numero de Seguidores da equipe na Rede Social: %d\n", jogador->equipe.numeroSeguidores);
    printf("  Patrocinadora principal: %s\n", jogador->patrocinadoraPrincipal);
    printf("  Nickname do jogador na Rede Social: %s\n", jogador->nicknameRedeSocial);
    printf("  Numero de Seguidores do jogador em Redes Sociais: %d\n", jogador->numeroSeguidores);
    printf("  Modelo do Computador/Notebook: %s\n", jogador->equipamentoHardware.modelo);
    printf("  Processador: %s\n", jogador->equipamentoHardware.processador);
    printf("  Placa de Video: %s\n", jogador->equipamentoHardware.placaVideo);
    printf("  Quantidade de Memoria RAM em GB: %d\n", jogador->equipamentoHardware.quantidadeMemoriaRAM);
    printf("  pontuacao no Campeonato: %d\n", jogador->dadosCampeonato.pontuacaoCampeonato);
    printf("  Quantidade de Vitorias: %d\n", jogador->dadosCampeonato.quantidadeVitorias);
    printf("  Quantidade de Derrotas: %d\n", jogador->dadosCampeonato.quantidadeDerrotas);
    printf("  Quantidade de Empates: %d\n", jogador->dadosCampeonato.quantidadeEmpates);
    printf("  Quantidade de Titulos que o Jogador Ganhou: %d\n", jogador->quantidadeTitulos);
    printf("  posicao do Rank Mundial: %d\n", jogador->posicaoRankMundial);
    printf("\n");
}

// Função para alterar os dados de um jogador
void alterarDadosJogador(struct Jogador *jogador, FILE *arquivo) {
    int opcao;

    printf("Escolha o que deseja alterar:\n");
    printf("1.  Nome\n");
    printf("2.  Data de Nascimento\n");
    printf("3.  CPF\n");
    printf("4.  Genero\n");
    printf("5.  Estado Civil\n");
    printf("6.  Equipe - Nome\n");
    printf("7.  Equipe - Nickname da Rede Social\n");
    printf("8.  Equipe - Numero de Seguidores na Rede Social\n");
    printf("9.  Patrocinadora Principal - Nome\n");
    printf("10. Patrocinadora Principal - Nickname da Rede Social\n");
    printf("11. Patrocinadora Principal - Numero de Seguidores em Redes Sociais\n");
    printf("12. Equipamento de Hardware - Modelo do Computador/Notebook\n");
    printf("13. Equipamento de Hardware - Processador\n");
    printf("14. Equipamento de Hardware - Placa de Video\n");
    printf("15. Equipamento de Hardware - Quantidade de Memoria RAM\n");
    printf("16. Dados do Campeonato - pontuacao no Campeonato\n");
    printf("17. Dados do Campeonato - Quantidade de Vitorias\n");
    printf("18. Dados do Campeonato - Quantidade de Derrotas\n");
    printf("19. Dados do Campeonato - Quantidade de Empates\n");
    printf("20. Quantidade de Títulos que o Jogador Ganhou\n");
    printf("21. posicao do Rank Mundial\n");
    printf("0.  Sair\n");

    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o novo nome: ");
            scanf("%s", jogador->nome);
            break;
        case 2:
            printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
            scanf("%s", jogador->dataNascimento);
            break;
        case 3:
            printf("Digite o novo CPF, sem pontos e traços: ");
            scanf("%s", jogador->cpf);
            break;
        case 4:
            printf("Digite o novo genero: ");
            scanf("%s", jogador->genero);
            break;
        case 5:
            printf("Digite o novo estado civil: ");
            scanf("%s", jogador->estadoCivil);
            break;
        case 6:
            printf("Digite o novo nome da equipe: ");
            scanf("%s", jogador->equipe.nome);
            break;
        case 7:
            printf("Digite o novo nickname da equipe na rede social: ");
            scanf("%s", jogador->equipe.nicknameRedeSocial);
            break;
        case 8:
            printf("Digite o novo numero de seguidores da equipe na rede social: ");
            scanf("%d", &(jogador->equipe.numeroSeguidores));
            break;
        case 9:
            printf("Digite o novo nome da patrocinadora principal: ");
            scanf("%s", jogador->patrocinadoraPrincipal);
            break;
        case 10:
            printf("Digite o novo nickname do jogador na rede social: ");
            scanf("%s", jogador->nicknameRedeSocial);
            break;
        case 11:
            printf("Digite o novo numero de seguidores do jogador em redes sociais: ");
            scanf("%d", &(jogador->numeroSeguidores));
            break;
        case 12:
            printf("Digite o novo modelo do computador/notebook: ");
            scanf("%s", jogador->equipamentoHardware.modelo);
            break;
        case 13:
            printf("Digite o novo processador: ");
            scanf("%s", jogador->equipamentoHardware.processador);
            break;
        case 14:
            printf("Digite a nova placa de video: ");
            scanf("%s", jogador->equipamentoHardware.placaVideo);
            break;
        case 15:
            printf("Digite a nova quantidade de memoria RAM em GB: ");
            scanf("%d", &(jogador->equipamentoHardware.quantidadeMemoriaRAM));
            break;
        case 16:
            printf("Digite a nova pontuacao no campeonato: ");
            scanf("%d", &(jogador->dadosCampeonato.pontuacaoCampeonato));
            break;
        case 17:
            printf("Digite a nova quantidade de vitorias: ");
            scanf("%d", &(jogador->dadosCampeonato.quantidadeVitorias));
            break;
        case 18:
            printf("Digite a nova quantidade de derrotas: ");
            scanf("%d", &(jogador->dadosCampeonato.quantidadeDerrotas));
            break;
        case 19:
            printf("Digite a nova quantidade de empates: ");
            scanf("%d", &(jogador->dadosCampeonato.quantidadeEmpates));
            break;
        case 20:
            printf("Digite a nova quantidade de titulos: ");
            scanf("%d", &(jogador->quantidadeTitulos));
            break;
        case 21:
            printf("Digite a nova posicao no rank mundial: ");
            scanf("%d", &(jogador->posicaoRankMundial));
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            // Escrever as alterações no arquivo
    fseek(arquivo, -sizeof(struct Jogador), SEEK_CUR);
    fwrite(jogador, sizeof(struct Jogador), 1, arquivo);


    }
}

// Função para inserir resultado (vitória, derrota ou empate) e atualizar pontuacao
void inserirResultado(struct Jogador *jogador, int resultado, FILE *arquivo) {
    switch (resultado) {
        case 1:  // Vitória (+3 pontos)
            jogador->dadosCampeonato.pontuacaoCampeonato += 3;
            jogador->dadosCampeonato.quantidadeVitorias++;
            break;

        case 2:  // Derrota
            jogador->dadosCampeonato.quantidadeDerrotas++;
            break;

        case 3:  // Empate (+1 ponto)
            jogador->dadosCampeonato.pontuacaoCampeonato += 1;
            jogador->dadosCampeonato.quantidadeEmpates++;
            break;

        default:
            printf("Opção de resultado inválida.\n");
            return;
    }

    // Atualizar a pontuação no arquivo
    fseek(arquivo, -sizeof(struct Jogador), SEEK_CUR);
    fwrite(jogador, sizeof(struct Jogador), 1, arquivo);
}

// Função para listar todos os jogadores em ordem alfabetica por nome
void listarJogadoresOrdemAlfabetica(struct Jogador jogadores[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        for (int j = i + 1; j < quantidade; j++) {
            if (strcmp(jogadores[i].nome, jogadores[j].nome) > 0) {
                // Troca de posicao
                struct Jogador temp = jogadores[i];
                jogadores[i] = jogadores[j];
                jogadores[j] = temp;
            }
        }
    }

    // Exibir os jogadores ordenados
    printf("Lista de Jogadores em Ordem Alfabetica:\n");
    for (int i = 0; i < quantidade; i++) {
        exibirDadosJogador(&jogadores[i]);
    }
}

// Função para listar todos os jogadores por ordem de sua posicao no rank mundial
void listarJogadoresPorRankMundial(struct Jogador jogadores[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        for (int j = i + 1; j < quantidade; j++) {
            if (jogadores[i].posicaoRankMundial > jogadores[j].posicaoRankMundial) {
                // Troca de posicao
                struct Jogador temp = jogadores[i];
                jogadores[i] = jogadores[j];
                jogadores[j] = temp;
            }
        }
    }

    // Exibir os jogadores ordenados por rank mundial
    printf("Lista de Jogadores por Ordem de posicao no Rank Mundial:\n");
    for (int i = 0; i < quantidade; i++) {
        exibirDadosJogador(&jogadores[i]);
    }
}

// Função para listar jogadores com maior Numero de vitórias no campeonato
void listarJogadoresMaiorNumeroVitorias(struct Jogador jogadores[], int quantidade) {
    int maiorNumeroVitorias = 0;

    // Encontrar o maior Numero de vitórias
    for (int i = 0; i < quantidade; i++) {
        if (jogadores[i].dadosCampeonato.quantidadeVitorias > maiorNumeroVitorias) {
            maiorNumeroVitorias = jogadores[i].dadosCampeonato.quantidadeVitorias;
        }
    }

    // Exibir os jogadores com maior Numero de vitórias
    printf("Jogadores com Maior Numero de Vitorias:\n");
    for (int i = 0; i < quantidade; i++) {
        if (jogadores[i].dadosCampeonato.quantidadeVitorias == maiorNumeroVitorias) {
            exibirDadosJogador(&jogadores[i]);
        }
    }
}

// Função para mostrar a classificação do campeonato
void mostrarClassificacaoCampeonato(struct Jogador jogadores[], int quantidade) {
    // Ordenar jogadores por pontuacao
    for (int i = 0; i < quantidade; i++) {
        for (int j = i + 1; j < quantidade; j++) {
            if (jogadores[i].dadosCampeonato.pontuacaoCampeonato < jogadores[j].dadosCampeonato.pontuacaoCampeonato) {
                // Troca de posicao
                struct Jogador temp = jogadores[i];
                jogadores[i] = jogadores[j];
                jogadores[j] = temp;
            }
        }
    }

    // Exibir classificação do campeonato
    printf("Classificação do Campeonato:\n");
    printf("Posicao | Nome                | pontuacao | Vitorias | Derrotas | Empates\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%-8d%-22s%-11d%-10d%-10d%-8d\n", i + 1, jogadores[i].nome,
               jogadores[i].dadosCampeonato.pontuacaoCampeonato, jogadores[i].dadosCampeonato.quantidadeVitorias,
               jogadores[i].dadosCampeonato.quantidadeDerrotas, jogadores[i].dadosCampeonato.quantidadeEmpates);
    }
}

// Função para listar jogadores com pontuacao no campeonato maior que um certo valor
void listarJogadoresPontuacaoMaiorQue(struct Jogador jogadores[], int quantidade, int valor) {
    printf("Jogadores com pontuacao no Campeonato Maior que %d:\n", valor);
    for (int i = 0; i < quantidade; i++) {
        if (jogadores[i].dadosCampeonato.pontuacaoCampeonato > valor) {
            exibirDadosJogador(&jogadores[i]);
        }
    }
}

// Função para listar jogadores com pontuacao no campeonato menor que um certo valor
void listarJogadoresPontuacaoMenorQue(struct Jogador jogadores[], int quantidade, int valor) {
    printf("Jogadores com pontuacao no Campeonato Menor que %d:\n", valor);
    for (int i = 0; i < quantidade; i++) {
        if (jogadores[i].dadosCampeonato.pontuacaoCampeonato < valor) {
            exibirDadosJogador(&jogadores[i]);
        }
    }
}

// Função para buscar um jogador por nome
void buscarJogadorPorNome(struct Jogador jogadores[], int quantidade, char nomeBusca[]) {
    printf("Buscar jogador por nome: %s\n", nomeBusca);
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(jogadores[i].nome, nomeBusca) == 0) {
            exibirDadosJogador(&jogadores[i]);
            return;
        }
    }
    printf("Jogador nao encontrado.\n");
}

// Função para buscar um jogador por posicao no rank mundial
void buscarJogadorPorPosicaoRank(struct Jogador jogadores[], int quantidade, int posicaoRankBusca) {
    printf("Buscar jogador por posicao no rank mundial: %d\n", posicaoRankBusca);
    for (int i = 0; i < quantidade; i++) {
        if (jogadores[i].posicaoRankMundial == posicaoRankBusca) {
            exibirDadosJogador(&jogadores[i]);
            return;
        }
    }
    printf("Jogador nao encontrado.\n");
}
void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para mostrar a quantidade media de seguidores de um jogador do campeonato
float calcularMediaSeguidores(struct Jogador jogadores[], int quantidade) {
    int totalSeguidores = 0;
    for (int i = 0; i < quantidade; i++) {
        totalSeguidores += jogadores[i].numeroSeguidores;
    }
    return (float)totalSeguidores / quantidade;

}

// Função para cadastrar jogador
void cadastrarJogador(struct Jogador *novoJogador) {
    printf("Cadastro de Novo Jogador:\n");

    // Preencher os dados do novo jogador
    printf("Digite o nome do jogador: ");
     while ((getchar()) != '\n');
    fgets(novoJogador->nome, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->nome);

    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    fgets(novoJogador->dataNascimento, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->dataNascimento);

    printf("Digite o CPF do jogador: ");
    fgets(novoJogador->cpf, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->cpf);

    printf("Digite o genero do jogador: ");
    fgets(novoJogador->genero, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->genero);

    printf("Digite o estado civil do jogador: ");
    fgets(novoJogador->estadoCivil, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->estadoCivil);

    // Preencher os dados da equipe
    printf("Digite o nome da equipe do jogador: ");
    fgets(novoJogador->equipe.nome, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->equipe.nome);

    printf("Digite o nickname da equipe na rede social: ");
    fgets(novoJogador->equipe.nicknameRedeSocial, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->equipe.nicknameRedeSocial);

    printf("Digite o numero de seguidores da equipe na rede social: ");
    scanf("%d", &(novoJogador->equipe.numeroSeguidores));

    printf("Digite o nome da patrocinadora principal: ");
    while ((getchar()) != '\n');
    fgets(novoJogador->patrocinadoraPrincipal, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->patrocinadoraPrincipal);

    printf("Digite o nickname do jogador na rede social: ");
    fgets(novoJogador->nicknameRedeSocial, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->nicknameRedeSocial);

    printf("Digite o numero de seguidores do jogador na rede social: ");
    scanf("%d", &(novoJogador->numeroSeguidores));

    // Preencher os dados do equipamento de hardware
    printf("Digite o modelo do computador/notebook: ");
    while ((getchar()) != '\n');
    fgets(novoJogador->equipamentoHardware.modelo, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->equipamentoHardware.modelo);

    printf("Digite o nome do processador: ");

    fgets(novoJogador->equipamentoHardware.processador, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->equipamentoHardware.processador);

    printf("Digite o nome da placa de video: ");
    fgets(novoJogador->equipamentoHardware.placaVideo, MAX_STRING, stdin);
    removerNovaLinha(novoJogador->equipamentoHardware.placaVideo);

    printf("Digite a quantidade de memoria RAM: ");
    scanf("%d", &(novoJogador->equipamentoHardware.quantidadeMemoriaRAM));

    // Preencher os dados do campeonato
    printf("Digite a pontuacao no campeonato: ");
    while ((getchar()) != '\n');
    scanf("%d", &(novoJogador->dadosCampeonato.pontuacaoCampeonato));

    printf("Digite a quantidade de vitorias: ");
    while ((getchar()) != '\n');
    scanf("%d", &(novoJogador->dadosCampeonato.quantidadeVitorias));

    printf("Digite a quantidade de derrotas: ");
    while ((getchar()) != '\n');
    scanf("%d", &(novoJogador->dadosCampeonato.quantidadeDerrotas));

    printf("Digite a quantidade de empates: ");
    while ((getchar()) != '\n');
    scanf("%d", &(novoJogador->dadosCampeonato.quantidadeEmpates));

    // Preencher os dados adicionais
    printf("Digite a quantidade de titulos que o jogador ganhou: ");
    while ((getchar()) != '\n');
    scanf("%d", &(novoJogador->quantidadeTitulos));

    printf("Digite a posicao no rank mundial: ");
    while ((getchar()) != '\n');
    scanf("%d", &(novoJogador->posicaoRankMundial));

    char resposta;
    printf("Deseja cadastrar outro jogador? (S/N): ");
    while ((getchar()) != '\n');
    scanf(" %c", &resposta); // Note o espaço antes do %c para consumir a quebra de linha
    if (resposta == 'S' || resposta == 's') {
        cadastrarJogador(novoJogador);
    }


     FILE *arquivo = fopen("jogadores.bin", "ab");
    if (arquivo != NULL) {
        // Escrever o novo jogador no final do arquivo
        escreverJogador(novoJogador, arquivo);
        printf("Jogador salvo com sucesso.\n");
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
    }



int main() {
     struct Jogador jogadores[MAX_JOGADORES];
    int quantidadeJogadores = 0;

    // Exemplo de utilização
    FILE *arquivo = fopen("jogadores.bin", "rb");

    if (arquivo != NULL) {
        // Ler jogadores do arquivo
        while (quantidadeJogadores < MAX_JOGADORES && fread(&jogadores[quantidadeJogadores], sizeof(struct Jogador), 1, arquivo) == 1) {
            quantidadeJogadores++;
        }

        fclose(arquivo);
    }

    // Exibir menu
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Jogador\n");
        printf("2. Alterar Dados de Jogador\n");
        printf("3. Inserir Resultado (Vitoria, Derrota ou Empate)\n");
        printf("4. Listar Jogadores em Ordem Alfabetica por Nome\n");
        printf("5. Listar Jogadores por Ordem de posicao no Rank Mundial\n");
        printf("6. Listar Jogadores com Maior Numero de Vitorias\n");
        printf("7. Mostrar classificacao do Campeonato\n");
        printf("8. Listar Jogadores com pontuacao no Campeonato Maior que um Certo Valor\n");
        printf("9. Listar Jogadores com pontuacao no Campeonato Menor que um Certo Valor\n");
        printf("10. Buscar Jogador por Nome\n");
        printf("11. Buscar Jogador por posicao no Rank Mundial\n");
        printf("12. Mostrar Quantidade Media de Seguidores de um Jogador do Campeonato\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
                      case 1:
                if (quantidadeJogadores < MAX_JOGADORES) {
                    cadastrarJogador(&jogadores[quantidadeJogadores]);
                    quantidadeJogadores++;
                } else {
                    printf("Limite de jogadores atingido.\n");
                }
                break;

            case 2:  // Alterar Dados de Jogador
                  if (quantidadeJogadores > 0) {
                    printf("Digite o nome do jogador que deseja alterar: ");
                    char nomeBusca[MAX_STRING];
                    scanf("%s", nomeBusca);

                    int indiceJogador = -1;

                    // Procurar jogador pelo nome
                    for (int i = 0; i < quantidadeJogadores; i++) {
                        if (strcmp(jogadores[i].nome, nomeBusca) == 0) {
                            indiceJogador = i;
                            break;
                        }
                    }

                    if (indiceJogador != -1) {
                        // Exibir dados do jogador
                        exibirDadosJogador(&jogadores[indiceJogador]);
                        arquivo = fopen("jogadores.bin", "r+b");
                        if (arquivo == NULL) {
                        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
                        return;
                    }
                        // Alterar dados do jogador
                        alterarDadosJogador(&jogadores[indiceJogador], arquivo);
                        fseek(arquivo, 0, SEEK_SET);  // Posicionar no início do arquivo
                    for (int i = 0; i < quantidadeJogadores; i++) {
                    escreverJogador(&jogadores[i], arquivo);
                    }
                    fclose(arquivo);
                    } else {
                        printf("Jogador nao encontrado.\n");
                    }
                } else {
                    printf("Nenhum jogador cadastrado.\n");
                }
                break;

            case 3:  // Inserir Resultado (Vitória, Derrota ou Empate)
                printf("Digite o nome do jogador que teve o resultado: ");
                char nomeResultado[50];
                scanf("%s", nomeResultado);

                int indiceResultado = -1;

                // Procurar jogador pelo nome
                for (int i = 0; i < quantidadeJogadores; i++) {
                    if (strcmp(jogadores[i].nome, nomeResultado) == 0) {
                        indiceResultado = i;
                        break;
                    }
                }

                if (indiceResultado != -1) {
                    printf("Escolha o resultado:\n");
                    printf("1. Vitoria (+3 pontos)\n");
                    printf("2. Derrota\n");
                    printf("3. Empate (+1 ponto)\n");
                    int opcaoResultado;
                    printf("Opcao: ");
                    scanf("%d", &opcaoResultado);
                    arquivo = fopen("jogadores.bin", "r+b");
                        if (arquivo == NULL) {
                        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
                        return;
                    }

                    // Chamar a função para inserir resultado
                    inserirResultado(&jogadores[indiceResultado], opcaoResultado, arquivo);
                    }
                    fseek(arquivo, 0, SEEK_SET);  // Posicionar no início do arquivo
                    for (int i = 0; i < quantidadeJogadores; i++) {
                    escreverJogador(&jogadores[i], arquivo);
                    }

            fclose(arquivo);
                    printf("Resultado inserido para o jogador:\n");
                    exibirDadosJogador(&jogadores[indiceResultado]);
                    break;

            case 4:  // Listar Jogadores em Ordem Alfabetica por Nome
                listarJogadoresOrdemAlfabetica(jogadores, quantidadeJogadores);
                break;

            case 5:  // Listar Jogadores por Ordem de posicao no Rank Mundial
                listarJogadoresPorRankMundial(jogadores, quantidadeJogadores);
                break;

            case 6:  // Listar Jogadores com Maior Numero de Vitórias
                listarJogadoresMaiorNumeroVitorias(jogadores, quantidadeJogadores);
                break;

            case 7:  // Mostrar Classificação do Campeonato
                mostrarClassificacaoCampeonato(jogadores, quantidadeJogadores);
                break;

            case 8:  // Listar Jogadores com pontuacao no Campeonato Maior que um Certo Valor
                printf("Digite o valor de pontuacao desejado: ");
                int valorPontuacaoMaior;
                scanf("%d", &valorPontuacaoMaior);
                listarJogadoresPontuacaoMaiorQue(jogadores, quantidadeJogadores, valorPontuacaoMaior);
                break;

            case 9:  // Listar Jogadores com pontuacao no Campeonato Menor que um Certo Valor
                printf("Digite o valor de pontuacao desejado: ");
                int valorPontuacaoMenor;
                scanf("%d", &valorPontuacaoMenor);
                listarJogadoresPontuacaoMenorQue(jogadores, quantidadeJogadores, valorPontuacaoMenor);
                break;

            case 10:  // Buscar Jogador por Nome
                printf("Digite o nome do jogador que deseja buscar: ");
                char nomeBuscaJogador[50];
                scanf("%s", nomeBuscaJogador);
                buscarJogadorPorNome(jogadores, quantidadeJogadores, nomeBuscaJogador);
                break;

            case 11:  // Buscar Jogador por posicao no Rank Mundial
                printf("Digite a posicao no rank mundial do jogador que deseja buscar: ");
                int posicaoRankBuscaJogador;
                scanf("%d", &posicaoRankBuscaJogador);
                buscarJogadorPorPosicaoRank(jogadores, quantidadeJogadores, posicaoRankBuscaJogador);
                break;

            case 12:  // Mostrar Quantidade Media de Seguidores de um Jogador do Campeonato
                printf("A media de seguidores dos jogadores eh: %.2f\n", calcularMediaSeguidores(jogadores, quantidadeJogadores));
                break;

            case 0:  // Sair
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

