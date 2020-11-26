/**
 * Discente: Rodrigo Calovi
 *
 * UERGS - Universidade Estadual do Rio Grande do Sul
 * Docente: Dra.Margrit Reni Krug
 *
 * 4) Crie uma função que recebe uma string e um caractere,
 * e apague todas as ocorrências desse caractere da string.
 * Imprima a string resultante.
 *
 */

#include <stdio.h>
#include <string.h>

#define TAM 15
void localizaCaracter(char *vet, char letra);
int localizaCaracter2apagar(char *vet, char letra);

int main() {

    char palavra[TAM], letra;
    printf("\nDigite uma palavra:");
    gets(palavra);

    printf("\nDigite um caracter ou palavra: ");
    letra = getchar();

    printf("\nPalavra: %s", palavra);

    printf("Quantidade Localizada: %d", localizaCaracter2apagar(palavra, letra));
    printf("\nPalavra com '%c' retirado: %s", letra, palavra);
    printf("\n\n");

    return 0;
}

void localizaCaracter(char palavra[], char letra){
    int i;
    int posicaoEncontrada[TAM]={0};

    for(i=0;i<strlen(palavra);i++){
        if(palavra[i]==letra){
            posicaoEncontrada[i]=1;
        }
    }

    printf("\nretirada de '%c' na palavra: \t" );
    for(i=0;i<strlen(palavra);i++){
        if(posicaoEncontrada[i]==0) {
            printf("%c", palavra[i]);
        }
    }
    

}


int localizaCaracter2apagar(char vet[], char letra) {

    char auxVet[TAM];
    int i,pos=0, cont=0;

    for(i=0;i<strlen(vet);i++){
        if(vet[i]!=letra){
           auxVet[pos]=vet[i];
           pos++;
        } else { 
            cont++;
        }
    }
    strcpy(vet,auxVet); //copia para vetor original com a letra retirada do vetor original
    //printf("\nPalavra sem a letra '%c' : %s", letra, vet);
    return cont;
}

