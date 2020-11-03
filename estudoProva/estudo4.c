#include <stdio.h>
#include <stdlib.h>

void mm(int vet[], int *min, int *max);
#define TAM 10

int main() {
    int i, min, max,vet[TAM]={-1,8,3,9,0,1,8,6,11,7};
    mm(vet, &min, &max);
    printf("\n Valor Min: %d",min);
    printf("\n Valor Max: %d",max);
    return 0;
}

void mm(int vet[], int *min, int *max){
    int i;
    *max=*min=vet[0];
    for(i=0;i<TAM;i++){
        if(*max<vet[i]){
            *max=vet[i];
        } else if(*min>vet[i]){
            *min=vet[i];
        }
    }
}
