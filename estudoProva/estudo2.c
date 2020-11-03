#include <stdio.h>
#include <stdlib.h>

int vetOrdemCrescente(int vet[],int n);
int vetOrdemDecrescente(int vet[],int n);

int main(){

    int vet[]={1,2,3,4,5,6,7,8,9,10},n;
    printf("Digite 0 para crescente e 9 para descrescnte: ");
    scanf("%d",&n);
    if(n==0) {
        vetOrdemCrescente(vet,n);
    } else if(n==9){
        vetOrdemDecrescente(vet,n);
    }
    return 0;
}

int vetOrdemCrescente(int vet[],int n){
    if(n<9){
        printf(" %d,",vet[n]);
        vetOrdemCrescente(vet, n+1);
    } 
    else 
        printf(" %d.",vet[n]);
}

int vetOrdemDecrescente(int vet[],int n){
    if(n>0){
        printf(" %d,",vet[n]);
        vetOrdemDecrescente(vet, n-1);
    } else
        printf(" %d.",vet[n]);
}