/**
 * Rodrigo Britto Calovi
 * P2 - UERGS
 */
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<conio.h>

#define TAM 100

int menu();
void votosCandidatosValidos(FILE *arquivo, int cont);
void Vencedor(FILE *arquivo, int cont);
void nulos(FILE *arquivo, int cont);

int main() {

	int op;
    int voto;
    int cont=0;

	FILE *arquivo;
	
	op = menu();
	
	while (op!= 5){

		switch (op){
            
			case 1:
				if (cont <TAM){
					arquivo = fopen ("votos.txt", "at");
					if (arquivo == NULL)					{
						printf ("\nErro no arquivo\n");
					}
					else{
                        printf ("\nVoto [1,2 ou 3, outro eh nulo]: ");
                        scanf ("%d", & voto);
                        fprintf (arquivo, "%d\n", voto);
						cont ++;
					}
					fclose (arquivo);
				}else {
					printf ("\nAtencao: Limite de votos!\n");
				}
				
				break;
			
			case 2:
				votosCandidatosValidos(arquivo, cont);
				break;
			
			case 3:
				Vencedor(arquivo, cont);
				break;
			
			case 4:
				nulos(arquivo, cont);
				break;

            case 5:
                printf("Você saiu do programa!");
                break;	
		}
		op = menu();
	}
	
	printf ("\nFIM\n");

    return 0;
}

int menu() {
	int op=0;
	do{
		printf ("\n1 - Inserir voto (no maximo 100 votantes)\n");
		printf ("2 - Quantidade de votos de cada candidato valido\n");
		printf ("3 - Candidato vencedor e a quantidade de votos\n");
		printf ("4 - Quantidade de votos nulos\n");
		printf ("5 - FIM\n");
		scanf ("%d", & op);
	} while (op <1 || op >5);
	return op;
}

void votosCandidatosValidos (FILE *arquivo, int cont){
	char voto, votoAux;
	int i, candidato1=0, candidato_2=0, candidato_3=0;
	
	arquivo = fopen ("votos.txt", "rt");
	
	if (arquivo == NULL){
		printf ("\nErro no arquivo\n");
	}
	else {
		for(i=0;i<cont;i++){
		    do{ 
		        votoAux=getc(arquivo);
		        
		        if (votoAux != '\n'){
		        	voto = votoAux;
		        
			        if(voto == '1'){
						candidato1++;
					}else if(voto == '2'){
						candidato_2++;
					}else if(voto == '3'){
						candidato_3++;
					}				
				}
		    } while(votoAux!='\n');
		}
		
			printf ("\n\n Quantidade de votos validos candidato 1 : %d", candidato1);
			printf ("\n\n Quantidade de votos validos candidato 2 : %d", candidato_2);
			printf ("\n\n Quantidade de votos validos candidato 3 : %d\n", candidato_3);			
	}
		
	
	fclose (arquivo);
}


void Vencedor (FILE *arquivo, int cont){
	char voto, votoAux;
	int i, candidato_1 =0, candidato_2 =0, candidato_3 =0;
	arquivo = fopen ("votos.txt", "rt");
	
	if (arquivo == NULL){
		printf ("\nErro no arquivo\n");
	} else {
		for(i=0;i<cont;i++){
		    do{ 
		        votoAux=getc(arquivo);
		        
		        if (votoAux != '\n'){
		        	voto = votoAux;
			        if(voto == '1'){
						candidato_1++;
					} else if(voto == '2'){
						candidato_2++;
					} else if(voto == '3'){
						candidato_3++;
					}				      
				}   
		    } while(votoAux!='\n');
		}
	
		if (candidato_1 > candidato_2 && candidato_1 > candidato_3){
			printf ("\nCandidato [1] vencedor com %d votos\n", candidato_1) ;
		} else if (candidato_3 > candidato_1 && candidato_3 > candidato_2){
			printf ("\nCandidato [3] vencedor com %d votos\n ", candidato_3) ;
		}else if (candidato_2 > candidato_1 && candidato_2 > candidato_3) {
			printf ("\nCandidato [2] vencedor com %d votos\n", candidato_2) ;
		}else if (candidato_3 > candidato_1 && candidato_3 > candidato_2){
			printf ("\nCandidato [3] vencedor com %d votos\n", candidato_3) ;
		}
	}
	fclose (arquivo);
	
}

void nulos (FILE *arquivo, int cont){
	char voto, votoAux;
	int i, nulo=0;
	
	arquivo = fopen ("votos.txt", "rt");
	
	if (arquivo == NULL){
		printf ("\nErro no arquivo!\n");
	} else {
		for(i=0;i<cont;i++){
		    do { 
		        votoAux=getc(arquivo);
		        if (votoAux != '\n'){
		        	voto = votoAux;
			        if(voto != '1' && voto != '2' && voto != '3'){
						nulo++;
					}				
				}
		    } while(votoAux!='\n');
		}
		
        printf ("\nVotos nulos: %d \n", nulo);
	}
	
	fclose(arquivo);
}