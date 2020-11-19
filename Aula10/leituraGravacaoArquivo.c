/**
* Exercício 1: leitura de arquivo texto e gravaçao
* arquivos necessários:
* entrada.txt -> onde ficam as entradas de texto
* saida.txt -> gravação do arquivo final apos leitura de entrada (clone)
**/

#include <stdio.h>

int main(void){

    FILE *entrada, *saida;

    int letra;

    if ((entrada = fopen("entrada.txt", "r")) == NULL) {
        printf("ERRO ao abrir arquivo!");
    } else if ((saida = fopen("saida.txt", "w")) == NULL) {
        printf("ERRO ao abrir arquivo!\n");
    } else {

        // Lê e grava cada caractere no arquivo
        while ((letra = fgetc(entrada)) != EOF) {
            fputc(letra, saida);
            putchar(letra);
        }

        fclose(entrada); // Fecha o arquivo entrada

        fclose(saida); // Fecha o arquivo saida

    }
    return 0;
}