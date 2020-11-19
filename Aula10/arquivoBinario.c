/**
 * Exercicio 2 - Criar um programa para escrever um arquivo binário
 * UERGS - Engenharia de computação
 * Algoritmos e programação 2 - 2020/2
 * Docente: Dra. Margrit Reni Krug
 * Discente: Rodrigo Britto Calovi
 */


#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main() {

    int i=0, A[TAM];
    
    FILE *arquivo;
    arquivo = fopen("matint.dat", "wb");
    
    while(i<TAM){
        printf("Numero[%2d]: ",i+1);
        scanf("%d",&A[i]);
        i += 1;
    }
    //fwrite(buffer, tamanho, contador, ponteiro);
    fwrite(A,sizeof(A),1,arquivo);
    fclose(arquivo);

    A[0]=101;
    A[1]=102;
    A[2]=103;
    A[3]=104;
    A[4]=105;

    printf("\nNumeros memoria: ");
    for(i=0;i<TAM;i++){
        printf("%2d ", A[i]);
    }

    //LEITURA ARQUIVO
    arquivo = fopen("matint.dat", "rb");
    fread(A,sizeof(A),1, arquivo);

    printf("\n\nNumeros arquivo: ");

    for(i=0;i<TAM;i++){
        printf("%2d ", A[i]);
    }
    fclose(arquivo);

    return 0;
}
