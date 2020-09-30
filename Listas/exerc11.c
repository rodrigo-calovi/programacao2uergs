/**
** 11.	Leia uma matriz 8 x 8 e a transforme numa matriz triangular inferior,
** atribuindo zero a todos os elementos acima da diagonal principal, escrevendo-a ao final.
**/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#define TAM 8

int main(){

    int mat[TAM][TAM]={ {10,11,12,13,14,15,16,17},
                        {11,2,3,18,4,20,19,7},
                        {31,33,31,38,34,30,39,37},
                        {21,23,24,28,43,22,29,53},
                        {50,54,55,51,53,56,59,60},
                        {61,65,75,68,63,62,64,68},
                        {82,72,73,78,4,20,19,70},
                        {92,92,93,98,99,90,97,94}
                      };
    int i,j;

    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
           if(i<j) //inferior
                mat[i][j]=0;
            //if(i>j) //superior
                //mat[i][j]=0;
            //if(i==j)//principal
               //mat[i][j]=1;
        }
    }
       

    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){           
            printf("\t%d ",mat[i][j]);
        }                
        printf("\n");
    }
    
    printf("\nDigite algo para sair!");
    getch();
    return 0;
}

