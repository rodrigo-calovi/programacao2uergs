/**
** 2. Crie um vetor de 20 posições de inteiros.  Após o vetor estar todo preenchido com valores 
** informados pelo teclado, solicite ao usuário a informação de um número, o qual será procurado
** no vetor. Se o valor for encontrado informe em que posição ele se encontra (a primeira, caso 
** ele esteja armazenado em mais de uma posição). Utilize mensagem adequada para o caso do valor 
** não estar armazenado no vetor.
**/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define TAM 20
#define FALSO 0
#define VERDADEIRO 1

int main(){

    setlocale(LC_ALL,"Portuguese");

    int vet[TAM];
    int i, valor;
    int existeValor=FALSO;
    int posicao=0;   

    for(i=0; i<TAM; i++){
        printf("Digite um valor[%d]: ",i);
        scanf("%d",&vet[i]);
    }
    printf("\nDigite o valor a ser procurado: ");
    scanf("%d", &valor);
    
    for(i=0;i<TAM;i++){
        if(valor==vet[i] && !existeValor){ //só se for valor igual ao procurado
            existeValor = VERDADEIRO; //encontrou valor
            posicao = i; //guarda valor posicao
            i=TAM; //abrevia contagem do for
        }
    }

    printf("\nVetor: \n");
    for(i=0;i<TAM;i++){
        if(i<TAM)
            printf("pos[%d]:%d \t ",i, vet[i]);
        else 
            printf("pos[%d]:%d",i, vet[i]);
    }

    if(existeValor){
        printf("\n\nValor: %d \nPosição: [%d]  ", vet[posicao],posicao);
        printf("\n");
        printf("Localizado!\n");
    } else {
        printf("\nValor não encontrado!\n");
    }
    
    printf("\nDigite algo para sair!");
    getch();

    return 0;
}

