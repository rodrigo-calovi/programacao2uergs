#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int tamanhoVetor(char vet[]);

int main (){
    char nome[15];
    int i;
    printf("Digite um nome: ");
    scanf("%s", &nome);
    fflush(stdin);
    printf("Nome: %s", nome);
    printf("\nTamanho do nome: %d", tamanhoVetor(nome));

    return 0;
}

int tamanhoVetor(char *vet){
    int size = 0;
    while(*vet++){
        size++;
    }
    return size;
}