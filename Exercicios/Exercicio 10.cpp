#include <stdio.h>

typedef union {
    int inteiro;      
    float flutuante;  
} Numero;

int main() {
    Numero numero1;
    numero1.inteiro = 42; 
   
    Numero numero2;
    numero2.flutuante = 3.14f;  

    printf("Valor armazenado na uniao (inteiro): %d\n", numero1.inteiro);
    printf("Valor armazenado na uniao (flutuante): %.2f\n", numero2.flutuante);

    return 0;
}
