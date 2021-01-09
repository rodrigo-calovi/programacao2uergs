/**
*	1)	Elabore um programa que lê o nome e o sobrenome de uma pessoa em 2
*		strings separadas e depois crie uma string com o nome completo.
*		Escreva a informação das três strings na tela.
**/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main() {
	
	char nome[30];
	char sobrenome[30];
	//char nomeCompleto[70] = {NULL}; //para uso com cadeia de caracteres
	char *nomeCompleto; //para uso ponteiro retirar o de cadeia de caracteres
	nomeCompleto = (char*)malloc(70 * sizeof(char)); //uso ponteiro alocacao
	
	printf("Digite o nome: ");	
	scanf("%s", &nome);
	fflush(stdin);
	
	printf("Digite o sobrenome: ");
	scanf("%s", &sobrenome);
	fflush(stdin);

	strcpy(nomeCompleto, nome);
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, sobrenome);

	printf("\nNome Completo: %s", nomeCompleto);

	getch();
	return 0;
}


