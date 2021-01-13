//Luana Sperling Santana


# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<conio.h>

int imprimemenu();
void votosvalidoscandidatos (FILE *arquivo, int cont);
void candidatovencedor (FILE *arquivo, int cont);
void votosnulos (FILE *arquivo, int cont);
int quantvotos (FILE *arquivo);

main()
{
	int opcao, voto, cont=0;
	FILE *arquivo;
	
	cont = quantvotos (arquivo);
	printf ("\n\n Quantidade de votos ja cadastrados: %d \n", cont);
	
	opcao = imprimemenu();
	
	while (opcao!= 5)
	{
		
		switch (opcao)
		{
			case 1:
				if (cont <100)
				{
					printf ("\n\n Quantidade de votos ja cadastrados: %d \n", cont);
					
					arquivo = fopen ("votos.txt", "at");
					if (arquivo == NULL)
					{
						printf ("\n Impossivel abrir arquivo \n");
					}
					else
					{
						do
						{
							printf ("\n Candidato Joao --> 1 \n Candidato Ana --> 2 \n Candidato Felipe --> 3 \n ");
							printf ("\n Informe o seu voto: ");
							scanf ("%d", & voto);
							fprintf (arquivo, "%d\n", voto);
						} while (voto<0); //pois na urna não existe a opção de número negativo
						
						cont ++;
					}
					fclose (arquivo);
				}
				else
				{
					printf ("\n Limite de votos excedido \n");
				}
				
				break;
			
			case 2:
				votosvalidoscandidatos (arquivo, cont);
				break;
			
			case 3:
				candidatovencedor (arquivo, cont);
				break;
			
			case 4:
				votosnulos (arquivo, cont);
				break;
			
		}
		
		opcao = imprimemenu();
	}
	
	printf ("\n Programa Finalizado \n");
}

int imprimemenu()
{
	int opcao=0;
	do
	{
		printf ("\n--------------- MENU ---------------\n");
		printf ("1 - Inserir voto (no maximo 100 votantes)\n");
		printf ("2 - Quantidade de votos de cada candidato valido\n");
		printf ("3 - Candidato vencedor e a quantidade de votos\n");
		printf ("4 - Quantidade de votos nulos\n");
		printf ("5 - FIM\n");
		scanf ("%d", & opcao);
	} while (opcao <1 || opcao >5);
	
	return opcao;
	
}

void votosvalidoscandidatos (FILE *arquivo, int cont)
{
	char voto, auxiliar;
	int i, candidato1=0, candidato2=0, candidato3=0;
	
	arquivo = fopen ("votos.txt", "rt");
	
	if (arquivo == NULL)
	{
		printf ("\n Impossivel abrir arquivo \n");
	}
	else
	{
		for(i=0;i<cont;i++)
		{
		    do
			{ 
		        auxiliar=getc(arquivo);
		        
		        if (auxiliar != '\n')
		        {
		        	voto = auxiliar;
		        
			        if(voto == '1')
					{
						candidato1++;
					}
					else if(voto == '2')
					{
						candidato2++;
					}
					else if(voto == '3')
					{
						candidato3++;
					}				
		               
				}
		           
		    } while(auxiliar!='\n');
	
		}
		
	
			printf ("\n\n Quantidade de votos validos candidato 1 : %d", candidato1);
			printf ("\n\n Quantidade de votos validos candidato 2 : %d", candidato2);
			printf ("\n\n Quantidade de votos validos candidato 3 : %d\n", candidato3);			
	
	}
		
	
	fclose (arquivo);
}


void candidatovencedor (FILE *arquivo, int cont)
{
	char voto, auxiliar;
	int i, candidato1 =0, candidato2 =0, candidato3 =0;
	
	arquivo = fopen ("votos.txt", "rt");
	
	if (arquivo == NULL)
	{
		printf ("\n Impossivel abrir arquivo \n");
	}
	else
	{
		for(i=0;i<cont;i++)
		{
		    do
			{ 
		        auxiliar=getc(arquivo);
		        
		        if (auxiliar != '\n')
		        {
		        	voto = auxiliar;
		        
			        if(voto == '1')
					{
						candidato1++;
					}
					else if(voto == '2')
					{
						candidato2++;
					}
					else if(voto == '3')
					{
						candidato3++;
					}				
		               
				}
		           
		    } while(auxiliar!='\n');
		}
	
		if (candidato1 > candidato2 && candidato1 > candidato3)
		{
			printf ("\n Candidato vencedor e o 1, numero de votos: %d\n", candidato1) ;
		}
		else if (candidato2 > candidato1 && candidato2 > candidato3)
		{
			printf ("\n Candidato vencedor e o 2, numero de votos: %d\n", candidato2) ;
		}
		else if (candidato3 > candidato1 && candidato3 > candidato2)
		{
			printf ("\n Candidato vencedor e o 3, numero de votos: %d\n ", candidato3) ;
		}
	}
	
	fclose (arquivo);
	
}

void votosnulos (FILE *arquivo, int cont)
{
	char voto, auxiliar;
	int i, nulo=0;
	
	arquivo = fopen ("votos.txt", "rt");
	
	if (arquivo == NULL)
	{
		printf ("\n Impossivel abrir arquivo \n");
	}
	else
	{
		for(i=0;i<cont;i++)
		{
		    do
			{ 
		        auxiliar=getc(arquivo);
		        
		        if (auxiliar != '\n')
		        {
		        	voto = auxiliar;
		        
			        if(voto != '1' && voto != '2' && voto != '3')
					{
						nulo++;
					}				
		               
				}
		           
		    } while(auxiliar!='\n');
	
		}
		
	
			printf ("\n\n Quantidade de votos nulos : %d \n", nulo);
	}
	
	fclose(arquivo);
}


int quantvotos (FILE *arquivo)
{
	int quantidadevotos=0;
    char auxiliar;
    
    arquivo = fopen("votos.txt","rt");
    
    if (arquivo == NULL)
	{
		printf ("\n Arquivo nao existe ainda \n");
		return quantidadevotos;
	}
	else
	{
		while (!feof(arquivo))
		{
			if(auxiliar=getc(arquivo)=='\n')
			{
	            quantidadevotos++;
	        }	
		} 
	        
    	return quantidadevotos;
	}
    

    fclose(arquivo);
}
