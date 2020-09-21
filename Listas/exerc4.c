/**
** 
** 4. Considere um vetor de trajetórias de 9 elementos, onde cada elemento possui o valor do próximo elemento do vetor a ser lido. 
** Índice       1    2    3    4    5    6    7     8     9  
** Valor       5    7    6    9     2   8    4     0     3 
** Assim, a seqüência da leitura seria 1, 5, 2, 7, 4, 9, 3, 6, 8, 0
** Faça um algoritmo que seja capaz de ler esse vetor e seguir a trajetória.
** By Calovi
**/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define TAM 9

int main(){
    int vet[]={5,7,6,9,2,8,4,0,3};
    int pos,i=0,next;
    setlocale(LC_ALL,"Portuguese");

    pos=1;
    next=vet[pos-1];
    printf("Trajetória: ");
    printf("%d %d ",pos, next);

    for(i=1;i<TAM;i++){
        pos=next;
        next=vet[pos-1];
        printf("%d ",next);
    }

    printf("\nDigite algo para sair!");
    getch();

    return 0;
}
