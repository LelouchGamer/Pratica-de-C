#include <stdio.h>

typedef struct {
    char nome[50];
    int codigo;
    float preco;
} Produto;

int main() {
    Produto produtos[5] = {
        {"Arroz", 101, 20.50},
        {"Feijao", 102, 8.99},
        {"Macarrao", 103, 4.75},
        {"Oleo", 104, 7.25},
        {"Acucar", 105, 5.80}
    };

    printf("Lista de Produtos:\n");
    for (int i = 0; i < 5; i++) {
        printf("Produto %d:\n", i + 1);
        printf("  Nome: %s\n", produtos[i].nome);
        printf("  Codigo: %d\n", produtos[i].codigo);
        printf("  Preço: R$ %.2f\n", produtos[i].preco);
        printf("\n");
    }

    return 0;
}
