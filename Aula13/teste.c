#include <stdio.h>

int main() {
    int numero;
    printf("Digite: ");
    scanf(" %d*%[^\n] ", &numero) ;
    printf ("-- %d\n", numero);

    return 0;

}