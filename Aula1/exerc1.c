/**
** 1.	Crie um vetor de 16 posições de inteiros (receba os valores pelo teclado
** para serem armazenados). Posteriormente, troque os 8 primeiros valores pelos 
** 8 últimos e vice-e-versa. Escreva ao final o vetor obtido.
**/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define TAM 16

int main(){

    int vet[TAM];
    int i, aux;

    for(i=0;i<TAM;i++){
        printf("Digite o numero [%d] de %d: ", i+1, TAM);
        scanf("%d", &vet[i]);
    }
  
    printf("\nVetor original:\n");
    for(i=0;i<TAM;i++){
        printf("%d ", vet[i]);
    }

    printf("\n\nVetor trocado por sua metade:\n");
    for(i=0;i<TAM;i++){
         if(i<TAM/2){
            aux=vet[i];
            vet[i]=vet[(TAM/2)+i];
            vet[(TAM/2)+i]=aux;
        }
        printf("%d ", vet[i]);    
    }
    
    printf("\n\n", vet[i]);
    printf("Digite algo para sair!");
    getch();
    return 0;
}

