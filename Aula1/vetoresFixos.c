//1) Dados dois vetores x e y, ambos com n elementos,
    //determinar o produto escalar desses vetores.
    //OBS.: o produto escalar é soma de todos os produtos dos
    //números de mesma posição. Por exemplo, se n = 4:
    
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 4

int main(void){
    
    //int vetX[] = {0,3,5,6};
    //int vetY[] = {2,4,9,8};
    int vetX[TAM];
    int vetY[TAM];
    int i,j,prodScalar = 0;

    for(i=0;i<TAM;i++){
        printf("Digie o valor[%d] para o vetor X: ",i);
        scanf("%d",&vetX[i]);
        printf("Digie o valor[%d] para o vetor Y :",i);
        scanf("%d",&vetY[i]);
        printf("\n");
    }
    
    printf("\nVetor X: ");
    for(i=0; i<TAM; i++){
        if(i<3)
            printf("%d, ", vetX[i]);
        if(i==TAM-1)
            printf("%d ", vetX[i]);
    }

    printf("\nVetor Y: ");
    for(i=0; i<TAM; i++){
        if(i<3)
            printf("%d, ", vetY[i]);
        if(i==TAM-1)
            printf("%d ", vetY[i]);
    }

    printf("\nProduto escalar X.Y = ");
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            if(i==j && i<TAM-1){
                printf("(%d x %d) + ",vetX[i], vetY[j]);
                prodScalar=prodScalar + vetX[i]*vetY[j];
            } else if(i==j) {
                printf("(%d x %d) = ",vetX[i], vetY[j]);
                prodScalar=prodScalar + vetX[i]*vetY[j];
            }
        }       
    }
    printf("%d\n\n",prodScalar);

    printf("Pressione uma tecla para sair!");
    getch();
    return 0;
}