/**
 * Discente: Rodrigo Britto Calovi
 * Engenharia da Computação
 * UERGS - Universidade Estadual do Rio Grande do Sul
 * Docente: prof. Dra. Margrit Reni Krug
 *
 * Exercício
 * 5)	Crie uma função que mostra os caracteres de uma string são repetidos.
 *
 */

#include <stdio.h>
#include <string.h>

int localizaCaracter2apagar(char vet[], char letra);

#define TAM 20

int main() {

    char palavra[TAM];
    char vetAux[TAM];
    int i, *qtCaracter;
    int qtAchado;

    printf("Digite um texto: ");
    scanf("%s", &palavra);
    fflush(stdin);

    strcpy(vetAux,palavra);

     for(i=0;i<(int)qtCaracter-1;i++){
         qtAchado = localizaCaracter2apagar(vetAux, palavra[i]);
         if(qtAchado>1)
             printf("\nLocalizadas '%d' letras '%c' na palavra.", qtAchado, palavra[i]);
         else {
             printf("");
         }

         qtCaracter = strlen(palavra);

     }


    printf("\n");
    return 0;
}

int localizaCaracter2apagar(char vet[], char letra) {

    char auxVet[strlen(vet)];
    int i,pos=0, cont=0;

    for(i=0;i<strlen(vet);i++){
        if(vet[i]!=letra){
            auxVet[pos]=vet[i];
            pos++;
        } else {
            cont++;
        }
    }

    auxVet[i]='\0';

    strcpy(vet,auxVet);

    return cont;
}