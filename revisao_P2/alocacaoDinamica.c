
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



int main(){

    int *num;
    int TAM,i;

    printf("Digite um tamanho: ");
    scanf("%d",&TAM);

    num = (int*)malloc(sizeof(int)*TAM); //num[3]; //faz alocacao de memoria

    num[0]=1; //vetores alocados
    num[1]=2;
    num[2]=3;

    for(i=0;i<TAM;i++){
        printf("\n%d",num[i]);
    }

    free(num); //libera alocacao

    for(i=0;i<TAM;i++){
        printf("\n%d",num[i]);
    }

    getch();

    return 0;
}