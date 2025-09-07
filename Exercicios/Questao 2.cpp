#include<stdio.h>

int contarCaractere(char* param, char caracter){
	
    int cont=0, a=0;
    while (param[a]!='\0')
    {
        if (param[a] == caracter)
        {
            cont++;
        }
        a++;
    }
    return cont;
}
int main()
{	
	int x;
	char param[100],caracter;
	printf("Digite sua frase: ");
	gets(param);
	printf("Digite seu caracter: ",caracter);
	scanf("%c",&caracter);
	x=contarCaractere(param,caracter);
    printf("Numero de caracteres: %d",x);
    return 0;
}
