#include <stdio.h>


struct Livro {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
};

int main() {
    
    struct Livro livro = {
        "O Hobbit",         
        "J.R.R Tolkien",     
        1937                   
    };

    // Impressão dos valores da estrutura
    printf("Informacoes do Livro:\n");
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.ano_publicacao);

    return 0;
}
