#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int i, palavras=0;
    char frase[50];

    printf("Insira sua frase: ");
    fgets(frase, 50, stdin);

    for(i=0; frase[i] != '\0'; i++){
        if(!isspace(frase[i]) && (i == 0 || isspace(frase[i-1]))){
            palavras++;
        }
    }
    printf("Quantidade de palavras: %d", palavras);


    return 0;
}