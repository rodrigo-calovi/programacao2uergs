/**************************************************************************
* Programa para criar arquivo tipo texto e gravar nome de pessoa e idade
* A leitura e gravação de pessoas no arquivo vai até que  o nome fim seja * * digitado pelo teclado
*
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

#define tamFile 15
#define tamNome 20

int main(void) {

    char nomeArq[tamFile], nome[tamNome]; 
    int idade;

    FILE *fileArq;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);
    fflush(stdin);

    fileArq = fopen(nomeArq, "wt");
    
    if(fileArq==NULL){
        printf("Impossível abrir arquivo!");
    }else {
        printf("\nDigite o nome da pessoa: ");
        scanf("%s",nome); //não tem &
        fflush(stdin);

        while (strcmp(nome,"fim")!=0){
            printf("Digite a idade da pessoa:");
            scanf("%d", &idade);
            
            fprintf(fileArq,"%s,%d\n", nome, idade);
            
            printf("\nDigite o nome da pessoa: ");
            scanf("%s",nome);
            fflush(stdin);
        }

        fclose(fileArq);
    }

    return 0;

}
