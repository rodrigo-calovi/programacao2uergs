/**
 * By Rodrigo Calovi
 * Transformação de palavra maiuscula para minuscula
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 20
void maiuscula(char palavra[]);

int main() {

    char palavra[TAM];
    printf("Digite uma palavra:");
    gets(palavra);
    printf("\nMaiuscula: %s\n", palavra);
    printf("\nMinuscula: " );
    maiuscula(palavra);
    printf("\n");
    return 0;
}

void maiuscula(char palavra[]){
    int i =0;
    for(i=0;i<strlen(palavra);i++){
        printf("%c", tolower(palavra[i]));
    }
}