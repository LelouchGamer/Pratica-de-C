#include<stdio.h>
#include<string.h>

    void contarLetrasENumeros(char* string,int* letra,int* numero){
        *letra=0;
        *numero=0;
        for(int i=0;i<strlen(string);i++){
        if((string[i] >=65 && string[i] <=90) || (string[i] >= 'a' && string[i] <='z'))
            (*letra)++;
        if(string[i] >='0' && string[i] <='9')
            (*numero)++;
        }
    }
    int main(){
    int numero,letra;
    char string[100];
    printf("Digite sua frase: ");
    gets(string);
    contarLetrasENumeros(string,&letra,&numero);
    printf("Quantidade de letras: %d\n Quantidade de numeros: %d\n",letra,numero);
    return 0;
    }
