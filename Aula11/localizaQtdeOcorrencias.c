/**
 * Discente: Rodrigo Calovi
 *
 * UERGS - Universidade Estadual do Rio Grande do Sul
 * Docente: Dra.Margrit Reni Krug
 *
 * 3) Crie uma função que recebe uma string de até 15 caracteres
 * e um caractere, e retorne o número de vezes que esse caractere
 * aparece na string
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 20
void minuscula(char palavra[]);
void maiuscula(char palavra[]);
int localizaCaracter(char palavra[], char letra);

int main() {

    char palavra[TAM], letra;
    printf("\nDigite uma palavra:");
    gets(palavra);

    printf("\nDigite um caracter ou palavra: ");    
    letra = getchar();

    printf("\nPalavra: \t%s", palavra);

    localizaCaracter(palavra, letra);

    printf("\n");

    return 0;
}

int localizaCaracter(char palavra[], char letra){
    int cont=0,i;
    char *ret;
    for(i=0;i<strlen(palavra);i++){
        if(palavra[i]==letra){
            cont++;
        }
    }
    printf("\n\nLocalizacao de: '%c' na palavra", letra);
    printf("\nOcorrencias encontradas: %d", cont);
}

