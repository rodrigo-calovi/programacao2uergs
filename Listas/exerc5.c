/**
** 5. Crie uma matriz  5 x 5 de inteiros e posteriormente (após o preenchimentos dos elementos via teclado),
** escreva a localização (linha e a coluna) do maior valor.
** By Rodrigo Calovi
**/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <locale.h>

#define TAM 5

int main(){

   // int vet[5][5]={
   //                 { 4, 1, 2, 3, 5},
   //                 {10,13,11,14,12},
   //                 {22,34,33,14,15},
   //                 {24,23,16,42,21},
   //                 {20,17,18,31,27}
   //               };
    int vet[TAM][TAM];
    int i,j;
    int maior;
    int linha;
    int coluna;

    setlocale(LC_ALL,"Portuguese");

    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            printf("Digite um valor [%d][%d]: ", i, j);
            scanf("%d",&vet[i][j]);
        }
    }

    maior=vet[0][0];
    
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            if(vet[i][j]>maior){
                maior = vet[i][j];
                linha = i;
                coluna = j;
            }
        }
    }

    printf("\nMaior: %d ",maior);
    printf("\nLinha: %d ",linha);
    printf("\nColuna: %d ",coluna);
 
    printf("\nDigite algo para sair!");
    getch();
    return 0;
}

