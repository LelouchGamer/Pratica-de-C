#include <stdio.h>

typedef struct {
    char nome[100];
    int matricula;
    float nota;
} Aluno;

void imprimirAluno(Aluno aluno) {
    printf("Informacoes do Aluno:\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %d\n", aluno.matricula);
    printf("Nota: %.2f\n", aluno.nota);
}

int main() {
    Aluno aluno1 = {
        "Joao Pedro",
        12345,       
        8.5           
    };

    imprimirAluno(aluno1);

    return 0;
}
