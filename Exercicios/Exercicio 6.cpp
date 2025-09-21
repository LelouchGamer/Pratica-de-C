#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char descricao[100];
    Data data; 
} Evento;

int main() {
   
    Evento evento = {
        "Lançamento de Projeto", 
        {15, 8, 2023}            
    };

    printf("Informacoes do Evento:\n");
    printf("Descricao: %s\n", evento.descricao);
    printf("Data: %02d/%02d/%04d\n", evento.data.dia, evento.data.mes, evento.data.ano);

    return 0;
}
