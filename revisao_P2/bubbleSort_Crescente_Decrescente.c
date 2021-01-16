#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void exibeVetor(int vetor[], int numElementos);
void bubbleSortCrescente(int vetor[], int capacity);
void bubbleSortDescrescente(int vetor[], int capacity);
void trocaValores(int *var1, int *var2);

int totalTrocas=0;
int totalComparcacoes=0;

int main() {

    int vetorA[TAM]={2,5,8,4,15,25,9,18,27,1};
    printf("\n\n [VetorA] [NAO Ordenado]: ");
    exibeVetor(vetorA,TAM);

    bubbleSortCrescente(vetorA,TAM);

    printf("\n\n [VetorA] [Ordenado Crescente]: ");
    exibeVetor(vetorA,TAM);
    
    printf("\n\n %d comparacoes, %d trocas, %d operacoes. \n\n", totalComparcacoes, totalTrocas, totalComparcacoes+totalTrocas);

    printf(" ------------------------------------------------------------- ");

    // repete para decrescente
    totalTrocas=0;
    totalComparcacoes=0;

    int vetorB[TAM]={8,2,5,4,25,15,19,18,22,1};
    printf("\n\n [VetorB] [NAO Ordenado]: ");
    exibeVetor(vetorB,TAM);

    bubbleSortDescrescente(vetorB,TAM);

    printf("\n\n [VetorB] [Ordenado Decrescente]: ");
    exibeVetor(vetorB,TAM);
    
    printf("\n\n %d comparacoes, %d trocas, %d operacoes. \n\n", totalComparcacoes, totalTrocas, totalComparcacoes+totalTrocas);

    return EXIT_SUCCESS;
}

void exibeVetor(int vetor[], int capacity){
    int i;
    printf("\n");
    for(i=0;i<capacity;i++){
        printf(" %5d",vetor[i]);
    }
}

void bubbleSortCrescente(int vetor[], int capacity){
    int x,y;
    for(x=1;x<capacity;x++){
        for(y=capacity-1; y>=x; y--){
            totalComparcacoes++;
            if(vetor[y-1] > vetor[y]){ //decrescente sinal de maior para menor
                trocaValores(&vetor[y-1], &vetor[y]);
            }
        }
    }
}

void bubbleSortDescrescente(int vetor[], int capacity){
    int x,y;
    for(x=1;x<capacity;x++){
        for(y=capacity-1; y>=x; y--){
            totalComparcacoes++;
            if(vetor[y-1] < vetor[y]){ //crescente sinal de menor para maior
                trocaValores(&vetor[y-1], &vetor[y]);
            }
        }
    }
}

void trocaValores(int *var1, int *var2){
    int temp;
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;

    totalTrocas++; //conta qt trocas
}