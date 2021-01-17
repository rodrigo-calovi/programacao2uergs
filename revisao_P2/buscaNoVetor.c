#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 10

void exibeVetor(int vetor[], int numElementos);
void trocaValores(int *var1, int *var2);
void quicksortCrescente(int vetor[], int esquerda, int direita);
int buscaSequencial(int vetor[], int numElementos, int buscarPor);

int main(){

    int vetorA[]={2,5,8,4,15,25,9,18,27,1};
    int buscaPor = 27;
    int posicao;
    printf("Busca por: %d", buscaPor);

    printf("\n\n Vetor NAO ORDENADO: \n");
    exibeVetor(vetorA,TAM);

    quicksortCrescente(vetorA,0,TAM);

    printf("\n\n Vetor ORDENADO: \n");
    exibeVetor(vetorA,TAM);

    posicao = buscaSequencial(vetorA,TAM, buscaPor);
    printf("\n\n Resultado da busca sequencial: %d \n\n", posicao);

    return EXIT_SUCCESS; //return 0;
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

int buscaSequencial(int vetor[], int numElementos, int buscarPor)
{
    int x;
    for(x=0;x<=numElementos;x++)
    {
        if(vetor[x] == buscarPor){
            return x;
        }
    }
    return -1;
}
