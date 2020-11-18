/**
 * Programa para imprimir na tela caracter ou string sem uso do prinf ou string
 * Nome: Rodrigo Britto Calovi
 * UERGS - Engenharia de computação
 **/
#include <stdio.h>

char imprimeCaracter(char letra);
void imprimeCadeiaCaracter(char *texto);

/**
 * Função principal
 * @return 0;
 */
int main() {
    imprimeCadeiaCaracter("\nHello World\n");
    imprimeCaracter('A');
    imprimeCaracter('B');
    imprimeCaracter('C');
    imprimeCaracter('\n');
    return 0;
}

/**
 * imprime caracter
 * @return int
 **/
char imprimeCaracter(char letra){
    return putchar(letra);
}

/**
 * Imprime conteudo da função imprimeCaracter
 * @return void
 **/
void imprimeCadeiaCaracter(char *texto){
    while(*texto != '\0'){
        imprimeCaracter(*texto++);
    }
}
