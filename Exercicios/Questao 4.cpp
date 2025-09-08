#include<stdio.h>
#include<string.h>

    void juntadorDeStrings(char* string,char* string1,char* string2){
        int i=0;
        for(i=0;i<strlen(string);i++)
            string2[i] = string[i];
        for(i=0;i<strlen(string1);i++)
            string2[i+strlen(string)] = string1[i];
        string2[i+strlen(string)] = 0;
    }
    int main(){
    char x,string[100], string1[100], string2[100];
    printf("Digite sua frase: ");
    gets(string);
    printf("Digite sua frase: ");
    gets(string1);
    juntadorDeStrings(string,string1,string2);
    printf("Strings juntas: %s",string2);
        return 0;
    }
