/**
 * Rodrigo Britto Calovi
 * P2 - UERGS
 */

# include<stdlib.h>
# include<stdio.h>
# include<string.h>
//# include<conio.h>

typedef struct dados{
   char nome[30];
   int idade;
   int peso;
} cadspa;

void sortingDecrescenteBubble(cadspa hospedes[], int capacity);
void imprimiHospedes(cadspa hospedes[], int capacity);

int main(){

	int capacity, i;
    
	cadspa *hospedes; //para tamanho dinamico
	
	do {
		printf("\nMaxima capacidade do SPA: ");
		scanf("%d", & capacity);
		fflush(stdin);
	} while (capacity<=0);
	hospedes = (cadspa*)malloc(sizeof(cadspa)*capacity);
	
	for(i=0; i<capacity; i++)	{
        do{
            printf("\nNome do hospede [%d]: ", i);
            scanf("%[^\n]", &hospedes[i].nome);
            fflush(stdin);
            if(strlen(hospedes[i].nome)<3){
                printf("Informe nome novamente!");
            }
        }while(strlen(hospedes[i].nome)<3);
		
		do {
			printf("Idade do hospede [%d]: ", i);
			scanf("%d", &hospedes[i].idade);
			fflush(stdin);
            if(hospedes[i].idade<=0){
                printf("Informe idade novamente!");
            }
		} while (hospedes[i].idade<=0);
				
		do {
			printf("Massa(peso) do hospede [%d]: ", i);
			scanf("%d", &hospedes[i].peso);
			fflush(stdin);
            if(hospedes[i].idade<=0){
                printf("Informe a massa (peso) novamente!");
            }
		} while (hospedes[i].peso<=0);
	}
	
	for(i = 0; i < capacity; i++){
    	printf ("\nMassa (peso) do hospede [%d]: %d", i, hospedes[i].peso);
	}
    
    //utilizacao de Bubble Sort
	sortingDecrescenteBubble(hospedes, capacity);
	
    return 0;
}

//funcao do bubble sort modificada para receber struct
void sortingDecrescenteBubble(cadspa hospedes[], int capacity){
	int i, j;
    //Para uso aux de peso e idade
    int aux;
    //Para uso aux de nome
	char auxNome[30];
	
    int troca = capacity - 1 ;
    
    for(i = 0; i < capacity; i++) {
      //ordenacao crescente (j > j+1) para decrescente (j < j+1)
      for(j = 0; j < troca; j++) {  
        if(hospedes[j].peso < hospedes[j+1].peso){
          aux = hospedes[j].peso;
          hospedes[j].peso = hospedes[j+1].peso;
          hospedes[j+1].peso = aux;
          
          aux = hospedes[j].idade;
          hospedes[j].idade = hospedes[j+1].idade;
          hospedes[j+1].idade = aux;
          
          //strcpy para copia de vetor
          strcpy (auxNome, hospedes[j].nome);
          strcpy (hospedes[j].nome, hospedes[j+1].nome);
          strcpy (hospedes[j+1].nome, auxNome);
        }
      }
      printf("\n");
      troca--;
    }

    //chama funcao de impressao com a capacidade e vetor de struct de hospedes
	imprimiHospedes(hospedes, capacity);
}

//funcao para impressao
void imprimiHospedes(cadspa hospedes[], int capacity){
	int i;
    printf("\n\nHospedes ordenados por Massa (peso) Decrescente:\n\n");
	for(i = 0; i < capacity; i++){
    	printf ("\n\nHospede [%d]: %s", i, hospedes[i].nome);
    	printf ("\nIdade [%d]: %d", i, hospedes[i].idade);
    	printf ("\nMassa(peso) [%d]: %d", i, hospedes[i].peso);
	}
}