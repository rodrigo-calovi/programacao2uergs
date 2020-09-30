/**
** 10.	Leia uma matriz 4 x 4 e troque os valores da 1ª.linha pelos da 4ª.coluna, vice-e-versa. Escrever ao final a matriz obtida.
** By Rodrigo Calovi
**/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 4

int main(){

    int i,j, cont=0;
    int vet[TAM][TAM] = {
                            {8,7,6,1},
                            {0,0,0,2},
                            {0,0,0,3},
                            {0,0,0,4}
                        };

            for(cont=1; cont<TAM; cont++){
                int aux = vet[0][(TAM-1)-cont];
                vet[0][(TAM-1)-cont] = vet[cont][(TAM-1)];
                vet[cont][(TAM-1)] = aux;
            }
    
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){           
            printf("%d ",vet[i][j]);
        }                
        printf("\n");
    }
    
    printf("Pressione uma tecla para sair!");
    getch();
    
    return 0;
}