/**
 * Discente: Rodrigo Britto Calovi
 * Engenharia da Computação
 * UERGS - Universidade Estadual do Rio Grande do Sul
 * Docente: prof. Dra. Margrit Reni Krug
 *
 * Uso de delimitador 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char texto[100];
    char *pt;

    printf("Digite um texto: ");
    scanf("%[^\n]",texto);
    fflush(stdin);

    pt = strtok(texto," ");

    while(pt) //enquanto pt != NULL
    {
        printf("\n token: %s", pt);
        pt = strtok(NULL," ;");
    }

    
    return 0;
}
