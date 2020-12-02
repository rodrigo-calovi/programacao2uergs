/**
 * 1) Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até 10 pessoas.
 * Cada pessoa deve ser representada por uma struct dentro de um vetor.
 * O nome, a data de nascimento e a altura de cada pessoa devem ser informados pelo teclado.
 * Posteriormente imprima os nomes das pessoas que possuem altura superior a 1,78.
 */

#include <stdio.h>

typedef struct dado1{
    char nome[20];
    float altura;
    char aniver[10];
} dados;
//typedef struct dados dados;

#define TAM 3

int main() {

    int i;
    dados dado1[TAM];

   for(i=0;i<TAM;i++) {
        printf("\nDigite o nome:");
        scanf("%s", &dado1[i].nome);

        printf("Digite a altura:");
        scanf("%f", &dado1[i].altura);

        printf("Digite o aniversario:");
        scanf("%s", &dado1[i].aniver);
        
        printf("\n-------------------------------\n");
    }


    for(i=0;i<TAM;i++) {
        if(dado1[i].altura > 1.78 ){
            
            printf("\nNome: %s", dado1[i].nome);
            printf("\nAltura: %.2f", dado1[i].altura);
            printf("\nAniversario: %s", dado1[i].aniver);
            printf("\n-------------------------------\n");
        }
    }

    return 0;
}
