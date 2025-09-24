#include <stdio.h>

typedef enum {
    DOMINGO,   
    SEGUNDA,    
    TERCA,    
    QUARTA,     
    QUINTA,    
    SEXTA,     
    SABADO     
} DiaDaSemana;

int main() {
    
    DiaDaSemana hoje = QUARTA;

    printf("Hoje eh o dia numero: %d\n", hoje);

    switch (hoje) {
        case DOMINGO:
            printf("Hoje eh Domingo.\n");
            break;
        case SEGUNDA:
            printf("Hoje eh Segunda-feira.\n");
            break;
        case TERCA:
            printf("Hoje eh Terça-feira.\n");
            break;
        case QUARTA:
            printf("Hoje eh Quarta-feira.\n");
            break;
        case QUINTA:
            printf("Hoje eh Quinta-feira.\n");
            break;
        case SEXTA:
            printf("Hoje eh Sexta-feira.\n");
            break;
        case SABADO:
            printf("Hoje eh Sábado.\n");
            break;
        default:
            printf("Dia inválido.\n");
            break;
    }

    return 0;
}
