#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int tamanhoVetor(char vet[]);

int main (){
    char nome[15];
    char letra;
    int i, tamanho, qtRepeticao=0;

    printf("Digite um nome: ");
    scanf("%s", &nome);
    fflush(stdin);
    
    printf("Nome: %s", nome);

    tamanho=tamanhoVetor(nome);
    printf("\nTamanho do nome: %d", tamanho );

    printf("\nDigite a letra a substituir: ");
    letra = getchar();
    fflush(stdin);

    for(i=0; i<tamanhoVetor(nome); i++){
        if(nome[i]==letra){
           nome[i]='*';
           qtRepeticao += 1;
        }
    }
     printf("Letra '%c', se repete %d vezes.", letra, qtRepeticao);
     printf("\nNome: %s", nome);

    return 0;
}

int tamanhoVetor(char *vet){
    int size = 0;
    while(*vet++){
        size++;
    }
    return size;
}