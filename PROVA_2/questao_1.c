/**
 * Rodrigo Britto Calovi
 * P2 - UERGS
 */
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <conio.h>
//#include <ctype.h>

int main(){

    char nomeComposto[30]; 
    char *sobrenome; //ponteiro para strrchr pegando ultima ocorrencia
	
	printf ("\nDigite o nome completo: ");
	scanf("%[^\n]",nomeComposto);
	printf ("\nSobrenome: ");
	sobrenome = strrchr(nomeComposto, ' ');	
	printf("%s\n", sobrenome);
	printf("Tamanho: %d", strlen(sobrenome)-1);

    return 0;
}