/**
 * 6)	Elabore um programa que leia dados em um vetor de inteiros de 10 posições.
 * Posteriormente utilizando algoritmos de ordenação coloque os valores em ordem
 * crescente. Imprima o vetor ordenado.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int menu();
int separa (int *vetor, int p, int r);
void quicksortCrescente (int *vetor, int p, int r);
void BubbleSort(int *vetor, int tamanho);
void imprimeVetor(int *vetor, int tamanho);
void swap(int *xp, int *yp);
void merge(int *vetor, int l, int m, int r);
void mergeSort(int *vetor, int left, int right);

int main(){
    int op,i,tamanhoVetor;
    int *vetor;  

    do{
        op=menu();
        
        switch(op){

            case 1: //VETOR
                do{
                    printf("Digite a qt de numeros a ler numeros: ");
                    scanf("%d",&tamanhoVetor);
                }while(tamanhoVetor<0);

                vetor = (int*) malloc(tamanhoVetor*sizeof(int));

                for(i=0; i< tamanhoVetor; i++){
                        printf("Digite %d numeros: ",tamanhoVetor);
                        scanf("%d",&vetor[i]);
                }
                break;

            case 2: //QUICKSORT
                quicksortCrescente(vetor,0,tamanhoVetor);
                imprimeVetor(vetor,tamanhoVetor);
                printf("\n\n");
                system("pause");
                break;

            case 3: //BUBBLE SORT
                BubbleSort(vetor,tamanhoVetor);
                imprimeVetor(vetor,tamanhoVetor);
                printf("\n\n");
                system("pause");
                break;

            case 4: //MERGE SORT
                mergeSort(vetor, 0, tamanhoVetor - 1);
                imprimeVetor(vetor,tamanhoVetor);
                printf("\n\n");
                system("pause");

            case 5: //SAIR
                printf("\nVoce saiu!\n");
                break;

            default:
                printf("\nDigite uma opcao valida!\n");
                break;
        }

    }while(op != 5 );

    return 0;
}

int menu(){
    system("cls");
    int op;
    printf("\nMENU\n");
    printf("\n1 - Digitar VETOR");
    printf("\n2 - QuickSort - crescente");
    printf("\n3 - BubbleSort - crescente");
    printf("\n4 - MergeSort - crescente");
    printf("\n5 - Sair");
    printf("\nDigite uma opcao: ");
    scanf("%d",&op);
    fflush(stdin);
    return op;
}

//QUICKSORT SEPARACAO
int separa (int *vetor, int left, int right) {
   int c = vetor[right]; // pivô
   int t, j = left;
   for (int k = left; k < right; ++k)
      if (vetor[k] <= c) {
         t = vetor[j];
         vetor[j] = vetor[k];
         vetor[k] = t;
         ++j; 
      } 
   t = vetor[j]; 
   vetor[j] = vetor[right];
   vetor[right] = t;

   return j; 
}

//RECURSIVO CRESCENTE
void quicksortCrescente(int *vetor, int left, int right){
   if (left < right) {
      int j = separa (vetor, left, right);
      quicksortCrescente (vetor, left, j-1);
      quicksortCrescente (vetor, j+1, right);
   }
}

//BUBBLE SORT CRESCENTE
void BubbleSort(int *vetor, int tamanho){ 
   int i, j; 
   for (i = 0; i < tamanho-1; i++)        
       for (j = 0; j < tamanho-i-1; j++)  
           if (vetor[j] > vetor[j+1]) 
              swap(&vetor[j], &vetor[j+1]); 
}

void imprimeVetor(int *vetor, int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        printf("%d ", vetor[i]);
    }
}

void swap(int *xp, int *yp){ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

//MERGE SORT
//https://www.geeksforgeeks.org/merge-sort/
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int *vetor, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = vetor[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = vetor[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        }
        else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

//MERGE SORT - CRESCENTE
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int *vetor, int left, int right){
    if (left < right) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = left + (right - left) / 2;
 
        // Sort first and second halves
        mergeSort(vetor, left, m);
        mergeSort(vetor, m + 1, right);
        merge(vetor, left, m, right);
    }
}
 
