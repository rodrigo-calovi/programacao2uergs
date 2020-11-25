/**
 * By Rodrigo Calovi
 * Transformação de palavra maiuscula para minuscula
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 20
void minuscula(char palavra[]);
void maiuscula(char palavra[]);

int main() {

    char palavra[TAM];
    printf("\nDigite uma palavra:");
    gets(palavra);

    printf("\nPalavra: \t%s", palavra);

    printf("\nMaiuscula: \t");
    maiuscula(palavra);
    
    printf("\nMinuscula: \t" );
    minuscula(palavra);
    
    printf("\n");
    return 0;
}


void maiuscula(char palavra[]){
    int i =0;
    for(i=0;i<strlen(palavra);i++){
        printf("%c", toupper(palavra[i]));
    }
}

void minuscula(char palavra[]){
    int i =0;
    for(i=0;i<strlen(palavra);i++){
        printf("%c", tolower(palavra[i]));
    }
}