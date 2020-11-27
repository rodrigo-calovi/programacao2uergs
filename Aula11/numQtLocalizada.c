
#include <stdio.h>
#include <string.h>

int localizaCaracter2apagar(char vet[], char letra);

#define FALSE 0
#define TRUE 1

#define TAM 20

int main() {

    char palavra[TAM];
    char vetAux[TAM];
    int i, qtCaracter;
    int qtAchado;
    int isAchado = FALSE;

    printf("Digite uma palavra: ");
    scanf("%s", &palavra);
    fflush(stdin);

    strcpy(vetAux,palavra);

     for(i=0;i<(int)qtCaracter-1;i++){
         qtAchado = localizaCaracter2apagar(vetAux, palavra[i]);
         if(qtAchado>1){
             printf("\nLocalizadas '%d' letras '%c' na palavra.", qtAchado, palavra[i]);
             isAchado = TRUE;
        } else {
             //printf("");
        }

         qtCaracter = strlen(palavra);

     }

    if(!isAchado){
        printf("Nao encontrado letras repetidas!");
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