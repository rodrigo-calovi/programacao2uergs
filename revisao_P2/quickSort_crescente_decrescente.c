#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void exibeVetor(int vetor[], int numElementos);
void trocaValores(int *var1, int *var2);
void quicksortCrescente(int vetor[], int esquerda, int direita);
void quicksortDecrescente(int vetor[], int esquerda, int direita);

int totalTrocas;
int totalComparcacoes;

int main() {

    totalTrocas = 0;
    totalComparcacoes = 0;

    int vetorA[TAM]={2,5,8,4,15,25,9,18,27,1};
    printf("\n\n [VetorA] [NAO Ordenado]: ");
    exibeVetor(vetorA,TAM);

    quicksortCrescente(vetorA,0,TAM-1);

    printf("\n\n [VetorA] [Ordenado Crescente]: ");
    exibeVetor(vetorA,TAM);
    
    printf("\n\n %d comparacoes, %d trocas, %d operacoes. \n\n", totalComparcacoes, totalTrocas, totalComparcacoes+totalTrocas);

    printf(" ------------------------------------------------------------- ");
   

    totalTrocas = 0;
    totalComparcacoes = 0;

    int vetorB[TAM]={2,5,8,4,15,25,9,18,27,1};
    printf("\n\n [VetorB] [NAO Ordenado]: ");
    exibeVetor(vetorB,TAM);

    quicksortDecrescente(vetorB,0,TAM-1);

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

void trocaValores(int *var1, int *var2){
    int temp;
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;

    totalTrocas++; //conta qt trocas
}

void quicksortCrescente(int vetor[], int esquerda, int direita){
    
    int x, y, meio;

    x = esquerda;
    y = direita;
    
    meio = vetor[(esquerda+direita)/2];
    
    do{
        while(vetor[x] < meio && (x < direita)){
            x++;
        } 
        
        while( (meio < vetor[y]) &&  (y > esquerda)) {
            y--;
        }
        
        totalComparcacoes++;
        
        if(x<=y){
            trocaValores(&vetor[x], &vetor[y]);
            x++;
            y--;
        }
        
    }while(x<=y);

    if(esquerda < y){
        quicksortCrescente(vetor, esquerda, y);
    }
    
    if(x < direita){
        quicksortCrescente(vetor, x, direita);
    }
    
}


void quicksortDecrescente(int vetor[], int esquerda, int direita){

   
    int x, y, meio;

    x = esquerda;
    y = direita;
    
    meio = vetor[(esquerda+direita)/2];
    
    do{
        while(vetor[x] > meio && (x < direita)){
            x++;
        } 
        
        while( (meio > vetor[y]) &&  (y > esquerda)) {
            y--;
        }
        
        totalComparcacoes++;
        
        if(x<=y){
            trocaValores(&vetor[x], &vetor[y]);
            x++;
            y--;
        }
        
    }while(x<=y);

    if(esquerda < y){
        quicksortDecrescente(vetor, esquerda, y);
    }
    
    if(x < direita){
        quicksortDecrescente(vetor, x, direita);
    }
    

}

