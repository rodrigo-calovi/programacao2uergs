#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


int main() {

	char vetor1[] = "Batata";
	char vetor2[] = "Assada";
	char vetor3[16];


	//strcpy
	strcpy(vetor3, vetor1); //copia string para outra vetor
	printf("%s", vetor3); //Batata
	printf("\n");



	//strncpy
	strncpy(vetor3, vetor2, 3);
	vetor3[3] = '\0'; //copia qtd n de caracteres para outro vetor
	printf("%s", vetor3); 
	printf("\n");
	
	

	//strcmp
    strcpy(vetor1, "A");
	strcpy(vetor2, "A");
	if (strcmp(vetor1, vetor2) == 0) { //compara string
		printf("\nPalavras identicas");
	} else if (strcmp(vetor1, vetor2) > 0) {
		printf("\nVetor1 eh maior que vetor2");
	} else {
		printf("\nVetor2 eh maior que vetor1");
	}
    printf("\nvetor1: %s\nVetor2: %s",vetor1,vetor2);



	//strncmp
    printf("\n\n");
    strcpy(vetor1, "Anas");
	strcpy(vetor2, "Anaz");
    int n=4;

	if (strncmp(vetor1, vetor2,n) == 0) { //compara n caracteres da string
		printf("\n%d caracteres iniciais identicos",n);
	} else if (strncmp(vetor1, vetor2,3) > 0) {
		printf("\nVetor1 eh maior que vetor2, comparado %d caracteres",n);
	} else {
		printf("\nVetor2 eh maior que vetor1, comparado %d caracteres",n);
	}
    printf("\nvetor1: %s\nVetor2: %s",vetor1,vetor2);



	//strcasecmp
        printf("\n\n");
    strcpy(vetor1, "Anas");
	strcpy(vetor2, "anas");

	if (strcasecmp(vetor1, vetor2) == 0) { //compara caracteres da string maisculos ou minusculos
		printf("\nPalavra identica");
	} else if (strcasecmp(vetor1, vetor2) > 0) {
		printf("\nVetor1 eh maior que vetor2");
	} else {
		printf("\nVetor2 eh maior que vetor1");
	}
    printf("\nvetor1: %s\nVetor2: %s",vetor1,vetor2);



	//strncasecmp
    printf("\n\n");
    strcpy(vetor1, "Anas");
	strcpy(vetor2, "anaz");
    n=3;

	if (strncasecmp(vetor1, vetor2, n) == 0) { //compara caracteres da string maisculos ou minusculos
		printf("\nPalavra identica nos primeiros %d caracteres",n);
	} else if (strncasecmp(vetor1, vetor2, n) > 0) {
		printf("\nVetor1 eh maior que vetor2 nos %d caracteres",n);
	} else {
		printf("\nVetor2 eh maior que vetor1 nos %d caracteres",n);
	}
    printf("\nvetor1: %s\nVetor2: %s",vetor1,vetor2);


	//strcat
    printf("\n\n");
    strcpy(vetor3,"Hello ");
    strcat(vetor3,"World!"); //concatena no vetor
    printf("%s",vetor3);


	//strncat
    printf("\n\n");
    strcpy(vetor3,"vdgkfdljgfdsjgk");
    strcpy(vetor3,"Hello ");
    strncat(vetor3,"World!",1); //concatena no vetor n caracteres
    strncat(vetor3, ".!",1);
    printf("%s",vetor3);


	//strlen
    n = strlen(vetor3); //retorna o tamanho da string
    printf("\n\nPalavra: %s",vetor3);
    printf("\nTamanho: %d",n);
    



	//strchr
    printf("\n\n");
    strcpy(vetor3,"ESPECIAL DA MADRUGA"); //imprime a partir da primeira ocorrencia
    printf(strchr(vetor3,'A'));

    
	//strrchr
    printf("\n\n");
    strcpy(vetor3,"ESPECIAL DA NOITE");
    printf(strrchr(vetor3,'A')); //imprime a partir da ultima ocorrencia


    //strstr
    printf("\n\n");
    //strcpy(vetor2,"SP"); //não funciona
    strcpy(vetor3,"ESPECIAL DA NOITE");
    printf(strstr(vetor3,"PE")); //compara primeira ocorrencia de string


    
	//strpbrk 
    printf("\n\n");
    char *p="Nome;Telefone;Cidade;Bairro";
    p = strpbrk(p,"Ba"); //procura primeira ocorrencia das letras nao importa ordem Ba aB 
    while(p!=NULL){
        printf("%c",*p);
        p = strpbrk(p+1,"Ba");
    }

    //{OBservacao}
    //ou //strpbrk // Declaring three strings 
    printf("\n\n\n");
    strcpy(vetor1,"geeksforgeeks");
    strcpy(vetor2,"ksy");
    strcpy(vetor3,"for");
    char* r, *t; 
  
    //Verifica caracteres iguais
    //sem ocorrencia 
    r = strpbrk(vetor1, vetor2);  
    if (r != 0) 
        printf("Primeira ocorrencia encontrada: %c\n", *r); 
    else
        printf("Caracter nao localizado."); 
  
    //Verifica caracteres iguais
    // Primeira ocorrencia "e" 
    t = strpbrk(vetor1, vetor3); 
    if (t != 0) 
        printf("\nPrimeira ocorrencia encontrada: %c\n", *t); 
    else
        printf("Caracter nao localizado."); 
  




	//strtok
    printf("\n\n");
    char str[] = "Rodrigo;Calovi"; 
  
    //Retorna o primeiro caracter
    char *token = strtok(str, ";"); 
  
    // Mantem imprimindo os tokens enquanto tiver delimitadores 
    // presentes em str[]. 
    while (token != NULL) { 
        printf("%s\n", token); 
        token = strtok(NULL, ";"); 
    } 



	return 0;
}