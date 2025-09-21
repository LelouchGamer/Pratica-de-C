#include <stdio.h>


typedef struct {
    char marca[50];
    char modelo[50];
    int ano;
} Carro;

int main() {
   
    Carro meuCarro = {
        "Toyota",     
        "Corolla",   
        2020          
    };

   
    printf("Informacoes do Carro:\n");
    printf("Marca: %s\n", meuCarro.marca);
    printf("Modelo: %s\n", meuCarro.modelo);
    printf("Ano: %d\n", meuCarro.ano);

    return 0;
}
