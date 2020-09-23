/**
** 12.	Leia uma matriz 5 x 5 e faça uma troca entre as diagonais principal e secundária.
** Escreva-a ao final.
**/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 5

int main(){

    int mat[]=  {
                    {},
                };
    int i, aux;

    for(i=0;i<TAM;i++){
        printf("Digite o número [%d] de %d: ", i+1, TAM);
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
    
    printf("\nDigite algo para sair!");
    getch();
    return 0;
}

