//Questão 3

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h>

typedef struct dados

{

   char nome[30];

   int idade;

   int peso;

}cadspa;

void ordenardecrecente(cadspa cadastro[], int capacidade);
void imprimircadastro(cadspa cadastro[], int capacidade);

main()
{
	int capacidade, i;
	cadspa *cadastro;
	
	do
	{
		printf ("\n Informe a capacidade maxima do SPA: ");
		scanf ("%d", & capacidade);
		fflush (stdin);
	} while (capacidade<=0);
	
	cadastro = (cadspa*)malloc(sizeof(cadspa)*capacidade);
	
	
	
	
	for(i=0; i<capacidade; i++)
	{
		printf ("\n Informe o nome do hospede [%d]: ", i);
		gets (cadastro[i].nome);
		fflush (stdin);
		
		do
		{
			printf ("\n Informe a idade do hospede [%d]: ", i);
			scanf ("%d", & cadastro[i].idade);
			fflush (stdin);
		} while (cadastro[i].idade<=0);
		
		
		do
		{
			printf ("\n Informe o peso do hospede [%d]: ", i);
			scanf ("%d", & cadastro[i].peso);
			fflush (stdin);
		} while (cadastro[i].peso<=0);
	}
	
	ordenardecrecente(cadastro, capacidade);
	
}

void ordenardecrecente(cadspa cadastro[], int capacidade)
{
	int i, j, auxiliar;
	char auxiliarnome[30];
	
	//bubble - troca - Bubble Sort
    int troca = capacidade - 1 ;
    
    for(i = 0; i < capacidade; i++)
	{
  
      for(j = 0; j < troca; j++)
	   {
	   	
        if(cadastro[j].peso < cadastro[j+1].peso)
		{
          auxiliar = cadastro[j].peso;
          cadastro[j].peso = cadastro[j+1].peso;
          cadastro[j+1].peso = auxiliar;
          
          auxiliar = cadastro[j].idade;
          cadastro[j].idade = cadastro[j+1].idade;
          cadastro[j+1].idade = auxiliar;
          
          strcpy (auxiliarnome, cadastro[j].nome);
          strcpy (cadastro[j].nome, cadastro[j+1].nome);
          strcpy (cadastro[j+1].nome, auxiliarnome);
        }
      }
      troca--;
      printf("\n");
    }
	
	imprimircadastro(cadastro, capacidade);
}


void imprimircadastro(cadspa cadastro[], int capacidade)
{
	int i;
	
	printf ("\n-------------- Hospedes Cadastrados --------------\n");
	
	for(i = 0; i < capacidade; i++)
    {
    	printf ("\n\n Nome do hospede [%d]: %s", i, cadastro[i].nome);
    	printf ("\n Idade do hospede [%d]: %d", i, cadastro[i].idade);
    	printf ("\n Peso do hospede [%d]: %d", i, cadastro[i].peso);
	}
}