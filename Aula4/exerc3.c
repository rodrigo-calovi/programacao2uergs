/**
 * 3)Elabore um programa que leia um número e depois escreva uma função que receba este valor 
 * inteiro lido como referência e retorne o resto da divisão deste número por 10. Altere também 
 * o valor da variável passada por referência, dividindo-a por 10.
 * 
 * By Rodrigo Calovi
 */

#include <stdio.h>
#include <stdlib.h>

int restoDivisao(float *num);

int main(){

    float num;
    printf("\nDigite um numero: ");
    scanf("%f",&num);
    
    printf("\nResto divisao: %d", restoDivisao(&num));
    printf("\nValor dividido por 10: %.2f", num);
    printf("\n");

    return 0;
}

int restoDivisao(float *num){
    int aux = (int)*num%10;
    *num = *num/10;
    return aux;
}