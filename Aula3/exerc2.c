/**
 * By Rodrigo Britto Calovi
 * Exercício 2 da aula 3.
 * Implemente uma função recursiva para computar o valor de 2n
 * Recursividade
 * Data: 30/09/2020
 **/ 
 
#include <stdio.h>
#include <stdlib.h>

float calculoN(int n);

float valor=0;

int main(){
    int n=0;
    printf("\nDigite o valor de 'n' para calculo de 2^n: ");
    scanf("%d",&n);
    printf("\nO valor de 2^%d é: ",n);
    if(n<0){
        n=n*-1;
        printf("%.8f\n\n", 1/calculoN(n) );
    } else 
        printf("%.0f\n\n",calculoN(n));
    return 0;
}

float calculoN(int n){
    if(n>1)
        valor = valor + calculoN(n-1);
    else if(n==1)
        valor = 2;
    else if(n==0)
        valor = 1;
    return valor;
}