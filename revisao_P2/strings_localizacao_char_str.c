#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int main() {
	

	char strA[6] = "Teste";
	char strB[6] = { 'T','e','s','t','e' };
	char strC[] = "Teste";
	const char *strD;
	char ch=NULL;
	char *resultado;
	char ascii;

	char minhaStringInt[3] = "50";
	char minhaStringDouble[4] = "2.3";

	int x;
	double y;
	char buffer[50];
	char matrizDeString[3][20];

	strD = "teste";

	printf("\n %s", strA);
	printf("\n %s", strB);
	printf("\n %s", strC);
	printf("\n %s", strD);

	printf("\nDigite uma string: ");
	//gets(strA); não é mais suportado pelas novas versões por ser perigoso
	fgets(strA, 6, stdin);
	strtok(strA, "\n");
	if (strlen(strA) == 6 - 1) {
		while (ch = getchar() != '\n' && ch != EOF);
	}
	puts("Texto Digitado: ");
	puts(strA);

	for (x = 0; x < 3; x++) {
		sprintf(buffer, "\nDigite o nome %d: ", x);
		puts(buffer);

		fgets(matrizDeString[x], 20, stdin);

		strtok(matrizDeString[x], "\n");
		if (strlen(matrizDeString[x]) == 20 - 1) {
			while ((ch = getchar()) != '\n' && ch != EOF);
		}
	}

	for (x = 0; x < 3; x++) {
		puts(matrizDeString[x]);
	}

	strcpy(buffer,"Rodrigo Britto Calovi");
	printf("\n\n %s \n\n", buffer);

	resultado = strchr(buffer, 'i');
	puts(resultado);

	resultado = strrchr(buffer, 'i');
	puts(resultado);

	resultado = strstr(buffer, "Cal");
	puts(resultado);

	//posicao
	resultado = strchr(buffer, 'i');
	printf("\nPosicao da ocorrencia: %d", resultado - buffer + 1);

	//posicao
	resultado = strrchr(buffer, 'i');
	printf("\nPosicao da ocorrencia: %d", resultado - buffer + 1);

	//Posicao
	resultado = strstr(buffer, "Cal");
	printf("\nPosicao da ocorrencia: %d", resultado - buffer + 1);


	//Todas ocorrencias i no  buffer
	resultado = strchr(buffer, 'i');
	while (resultado != NULL) {
		printf("\n\nEncontrou 'i' em: %d ", resultado - buffer + 1);
		resultado = strchr(resultado + 1, 'i');
	}

	ascii = 'A';
	printf("\n\n Caracter e seu cod ascii: %c (%d) \n\n", ascii, ascii);
	

	//string para inteiro
	x = atoi(minhaStringInt);
	printf("\n A soma de %d com 10 resulta em: %d", x, x + 10);

	y = atof(minhaStringDouble);
	printf("\n O dobro de %.2f eh: %.2f", y, y*2);

	
	getch();
	return 0;
}
