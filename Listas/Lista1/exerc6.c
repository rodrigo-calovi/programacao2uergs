/**
** 6. Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais elementos.
** Escreva ao final a matriz obtida.
** By Rodrigo Calovi
**/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 5

int main(){

    int vet[TAM][TAM];
    int i,j;

    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            if(i==j)
                vet[i][j]=1;
            else
                vet[i][j]=0;
        }
    }
    
    printf("\n\tMatriz %dx%d\n\n",TAM,TAM);
    printf("\t|\t\t\t\t    |\n");
    for(i=0;i<TAM;i++){
        printf("\t|");
        for(j=0;j<TAM;j++){           
            printf("   %d   ",vet[i][j]);    
        }
        printf("|\n"); 
        printf("\t|\t\t\t\t    |\n");
    }

    printf("\n\nDigite algo para sair!");
    getch();
    return 0;
}

