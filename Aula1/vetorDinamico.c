/******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//1) Dados dois vetores x e y, ambos com n elementos,
    //determinar o produto escalar desses vetores.
    //OBS.: o produto escalar é soma de todos os produtos dos
    //números de mesma posição. Por exemplo, se n = 4:
    
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//#define TAM 4

int main(void){
    
    //scanf("%d",&TAM);
    //int vetX[] = {0,3,5,6};
    //int vetY[] = {2,4,9,8};
        
    int *vetX;
    int *vetY;
    int TAM;
    int prodScalar = 0;
    int i,j;

    do{
        printf("Digite o tamanho do vetor: ");
        scanf("%d",&TAM);
    }while(TAM<=0);
    
    vetX = (int *)malloc(TAM * sizeof(int));
    vetY = (int *)malloc(TAM * sizeof(int));

    for(i=0;i<TAM;i++){
        printf("Digite o vetor X[%d]: ",i);
        scanf("%d",&vetX[i]);
    }
    
    printf("\n\n");
    for(i=0;i<TAM;i++){
        printf("Digite o vetor Y[%d]: ",i);
        scanf("%d",&vetY[i]);
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