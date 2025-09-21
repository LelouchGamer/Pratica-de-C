#include <stdio.h>

typedef struct {
    char nome[100];
    int matricula;
    float nota;
} Aluno;

int main() {
   
    Aluno aluno1 = {
        "Ana Silva",     
        12345,           
        9.5              
    };
    
    printf("Informacoes do Aluno:\n");
    printf("Nome: %s\n", aluno1.nome);
    printf("Matricula: %d\n", aluno1.matricula);
    printf("Nota: %.2f\n", aluno1.nota);

    return 0;
}
