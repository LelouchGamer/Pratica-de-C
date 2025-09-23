#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;     
    float altura;  
} Pessoa;

int main() {
   
    size_t tamanho = sizeof(Pessoa);

    printf("O tamanho da estrutura Pessoa eh: %zu bytes\n", tamanho);

    return 0;
}
