/**
 * 4)Faça um programa que leia 3 números inteiros obrigatoriamente com três dígitos e depois 
 * utilizando uma função imprima o número lido de forma invertida (os números que foram 
 * passados por parâmetro).  Ex: 234 saída: 432
 * 
 * By Rodrigo Calovi
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void inverteDigito(int *num);
void inverteOrdem(int *num);

int main () {
    int i = 0;
    int *num;

    while(i<3){
        do {        
            printf("Digite um numero: [%d] ",i);
            scanf("%d",&num[i]);
        }while(*num<100 || *num >999);
        i++;
    }

    //na ordem de entrada
    inverteDigito(num);

    //de traz pra frente
    //inverteOrdem(num); // descomentar para inverter ordem de entrada
    
    for(i=0; i<TAM; i++){
        printf("%d ",*(num+i));
    }

    return 0;
}

void inverteDigito(int *num){
    int i = TAM;
    int numInvert;
           
    while (i--) {

        numInvert = 0;

        while ( *(num+i) > 0 ) { //igual a num[i]
            numInvert = 10*numInvert + *(num+i)%10;
            *(num+i) /= 10;
        }

        *(num+i)=numInvert;
    }
}

void inverteOrdem(int *num){
    int i;
    int vet[TAM];
    for(i=0; i<TAM; i++){
        vet[i]=*(num+i);
        //printf("%d ",vet[i]);
    }
    //inverte do vetor
    for(i=0; i<TAM; i++){
        *(num+i) = vet[(TAM-1)-i];
        //printf("%d ",vet[i]);
    }
      
}

