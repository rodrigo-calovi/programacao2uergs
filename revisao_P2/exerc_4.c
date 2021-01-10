/**
 * 4) Implemente um vetor dinâmico com os números primos de um 
 * número informado pelo teclado. 
 * 
 * Por: Rodrigo Calovi
 * UERGS/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void imprimeVetor(int *vPrimos,int cont);

int main(){

    int *vPrimos;
    int num,qtDiv,i,j,cont=0;
    int EhPrimo;

    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &num);
    } while(num<0);
    
    vPrimos = (int*) malloc(num*sizeof(int));
 
    if(num==0 || num==1){
        EhPrimo = 0;
    } else {

        for(i = 0; i <= num; i++) {
            qtDiv = 0;

            for(j = 1; j <= i; j++) {
                if(i % j == 0) {
                    qtDiv++;
                }
            }
            // Se o total de divisores é dois, imprime o primo
            if(qtDiv == 2) {
                vPrimos[cont]=i;
                cont++;
            }
        }

        printf("Sao numeros primos ateh [%d]: \n",num);
        imprimeVetor(vPrimos,cont);
    
    return 0;
    }
}

void imprimeVetor(int *vPrimos, int cont){
    int i;
    for(i=0;i<cont;i++){
        printf("%d\t",vPrimos[i]);
    }
}