/**
 * 2)	Elabore um programa que implemente uma função que receba um 
 * parâmetro (inteiro por valor) com o total de minutos passados ao 
 * longo do dia e receba também dois parâmetros (inteiros por referência) 
 * no qual deve preencher com o valor da hora e do minuto corrente. 
 * Faça um programa que leia do teclado quantos minutos se passaram desde 
 * meia-noite e imprima a hora corrente.
 * By Rodrigo Calovi
 */

#include <stdio.h>
#include <stdlib.h>

int minutosDias(int min, int *hora, int *minuto);

int main(){
    int minutosDia;
    int hora, minuto;

    do {
        printf("\nMinutos passados ao longo do dia: ");
        printf("\nDigite o valor em minutos: ");
        scanf("%d", &minutosDia);
    }while(minutosDia>1440 || minutosDia <=0);

    minutosDias(minutosDia, &hora, &minuto);
    printf("\nPassaram-se %d min. ", minutosDia); 
    printf("\nou: %02dh %02dmin ",hora, minuto);

    return 0;
}

int minutosDias(int min, int *hora, int *minuto){
    *hora = min/60;
    *minuto = min-(*hora*60);
    return min;
}
