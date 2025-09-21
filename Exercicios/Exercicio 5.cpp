#include <stdio.h>

// Definição da estrutura Aluno
typedef struct {
    char nome[100];
    int matricula;
    float nota;
} Aluno;

int main() {
    
    Aluno aluno1 = {
        "Carlos Souza", 
        67890,          
        8.7             
    };

    Aluno *ptrAluno = &aluno1;

    printf("Informacoes do Aluno:\n");
    printf("Nome: %s\n", ptrAluno->nome);
    printf("Matricula: %d\n", ptrAluno->matricula);
    printf("Nota: %.2f\n", ptrAluno->nota);

    return 0;
}
