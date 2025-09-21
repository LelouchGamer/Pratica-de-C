#include <stdio.h>


typedef struct {
    char marca[50];
    char modelo[50];
    int ano;
} Carro;

int main() {
    
    Carro carroOriginal = {
        "Ford",       
        "Mustang",    
        1967          
    };  
    Carro carroCopia;  
    carroCopia = carroOriginal;
    printf("Informacoes do Carro Copiado:\n");
    printf("Marca: %s\n", carroCopia.marca);
    printf("Modelo: %s\n", carroCopia.modelo);
    printf("Ano: %d\n", carroCopia.ano);

    return 0;
}
