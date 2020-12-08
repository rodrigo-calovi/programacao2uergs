/**
 * UERGS - Engenharia de computação
 * Desenvolvido por: Rodrigo Britto Calovi
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("\nAguarde o tempo de 5s: ");
    int i = 1;
    while (i <= 5){
        printf("\r\t\t\t%ds",i++);
        system("sleep 1");
        fflush(stdout);
    }
    printf("\n");
    return 0;
}