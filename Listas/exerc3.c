/**
** 3 Crie um vetor de 15 posições de inteiros e posteriormente realize a compactação dele, isto é,
** elimine as posições com valor zero avançando uma posição, com os com os valores subseqüentes do
** vetor. Dessa forma todos “zeros” devem ficar para as posições finais do vetor.
**/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 15

int main(){

    int vet[TAM];
    int i, cont=0;
    int indice=1;
    
    for(i=0;i<TAM-cont;i++){
        do {
            printf("Digite valor [%d]: ",indice++);
            scanf("%d",&vet[i]);
            if(vet[i]==0){
                vet[(TAM-1)-cont]=vet[i];
                cont++;
                i--;
            }         
        } while(vet[i]==0);
    }

    printf("Vetor compactado: ");
    for(i=0;i<TAM;i++){
        printf("%d ",vet[i]);
    }

    printf("\nDigite algo para sair!");
    getch();

    return 0;
}
