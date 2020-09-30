/**
 * By Rodrigo Britto Calovi
 * Exercício 2 da aula 3.
 * 
 * Implemente uma função recursiva para computar o valor de 2n
 * 
 * Aula de Algorítmos e programação 2
 * Recursividade
 * 
 * Data: 30/09/2020
 **/ 
 

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <locale.h>

float calculoN(int n);
float calculoNneg(int n);

float valor=0;

int main(){

    setlocale(LC_ALL,"portuguese");

    int n=0;

    printf("\nDigite o valor de 'n' para cálculo de 2^n: ");
    scanf("%d",&n);
    
    printf("\nO valor de 2^n é: ");
    if(n>=0)
        printf("%.1f\n\n",calculoN(n));
    else{
        n=n*-1;
        printf("%.8f\n\n",calculoNneg(n));
    }

    //printf("\n\nPressione uma tecla para continuar!");
    //getch();
    //system("pause");
    
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


float calculoNneg(int n){ 
    valor = valor + calculoN(n-1);
    return 1/valor;
}