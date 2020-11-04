#include <stdio.h>
#include <stdlib.h>

void muda(int vet[1]);

int main(){

    int vet[2]={3,4};
    printf("\nAntes da funcao: %d",vet[1]);

    muda(vet);
    printf("\nDepois da Funcao: %d",vet[1]);


    return 0;
}

void muda(int vet[]){
    int i = vet[0];
    printf("\nRecebe funcao: %d",i);
    vet[1]=9;
    printf("\nAltera na funcao: %d",vet[0]);
}