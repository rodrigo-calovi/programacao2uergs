/**
** 12.	Leia uma matriz 5 x 5 e faça uma troca entre as diagonais principal e secundária.
** Escreva-a ao final.
**/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


int main(){

    int i;
    
    printf("Intervalo de rand: [0,%d]\n",RAND_MAX);
    srand((unsigned)time(NULL));

    for(i=1;i<=10;i++){
        printf("Numero %d: %d\n",i,rand()%60);
    }

    printf("\nDigite algo para sair!");
    getch();
    return 0;
}

