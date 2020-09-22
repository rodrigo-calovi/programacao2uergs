/**
** 8.	Leia uma matriz 6 x 6, conte e escreva quantos valores maiores que 10 ela possui.
**/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 4

int main(){
    int i,j,cont=0;
    int MAT1[TAM][TAM] = {
                            {6,3,74,8},
                            {10,2,30,4},
                            {1,20,3,60},
                            {13,40,7,52},
                            {18,32,33,22}
                        };
    
    printf("Valores encontrados:");
    for(i=0;i<TAM;i++){
            for(j=0;j<TAM;j++){           
                if(MAT1[i][j]>10){
                    printf("%d ",MAT1[i][j]);
                    cont++;
                }
            }
    }

    printf("\nValores maiores que 10: %d",cont);
    getch();
    )
    return 0;
}