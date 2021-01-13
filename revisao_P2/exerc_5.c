/**
 * Por: Rodrigo Calovi
 * UERGS 2020/2
 * 
 * 5)	Escreva um programa que armazene a agenda do exercício 3 em um 
 * arquivo e posteriormente realize a impressão dos contatos conforme o menu:
 * 1 – contatos com nome iniciando com a letra J
 * 2 – Contatos com “ana” no nome(em qualquer posição)
 * 3 – Quantidade de contatos cadastrados
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define TAMnome 30
#define TAMtel 20 
#define TAM 15 //limite contatos

typedef struct data_aniversario {
    int dia;
    int mes;
} t_dataAniver;

struct t_agenda {
    char nome[TAMnome];
    char telefone[TAMtel];
    t_dataAniver data;
};

int menu();
void limparTela();
void pause();
struct t_agenda cadastroContato();
void imprimeAgenda(struct t_agenda contatos[] , int qtContatos);
void imprimeAniversariante(struct t_agenda contatos[] , int qtContatos, int dia, int mes);
int imprimeQtAniversariantesMes(struct t_agenda contatos[] , int qtContatos, int mes);
void GravaArquivo(struct t_agenda aniversariantes[], int qtContatos);
void leArquivo();
int contRegistros();
//void localizaInicialNome(struct t_agenda contatos[]);
//void localizaInicialNome();
void leArquivoGravaVetor(struct t_agenda aniversariantesAux[]);
void localizar_J(struct t_agenda aniversariantesAux[]);
void localizaAna(struct t_agenda aniversariantesAux[]);


int main(){
    char resposta;
    int opcao;
    struct t_agenda aniversariantes[TAM];
    struct t_agenda aniversariantesAux[TAM];
   //aniversariantes = (struct t_agenda*)malloc(sizeof(struct t_agenda)*TAM);

    int cont=0;
    int dia, mes;
    int qtAniversariantesMes;
    
    do{
        limparTela();
        opcao = menu();

        switch (opcao){
            case 1: //cadastro contato
                do{
                    aniversariantes[cont] = cadastroContato();

                    printf("\nDeseja cadastrar mais? ");
                    scanf("%c",&resposta);
                    fflush(stdin);
                    
                    cont++;
                }while(cont<TAM && resposta != 'n');                
                break;

            case 2: //mostras contatos
                limparTela();
                //imprimeAgenda(aniversariantes, cont);
                leArquivoGravaVetor(aniversariantesAux);
                pause();
                break;

            case 3: //informe nomes aniversariantes

                do{
                    printf("Informe o mes dos aniversariantes: ");
                    scanf("%02d", &mes);
                }while(mes<1 || mes >12);

                do{
                    printf("Informe o dia dos aniversariantes: ");
                    scanf("%02d", &dia);
                }while(dia<1 || dia >31);

                imprimeAniversariante(aniversariantes,cont,dia,mes);

                printf("\n\n");
                pause();
                break;

            case 4: //informe aniversariantes do mes
                do{
                    printf("Informe o mes dos aniversariantes: ");
                    scanf("%02d", &mes);
                }while(mes<1 || mes >12);
            
                qtAniversariantesMes = imprimeQtAniversariantesMes(aniversariantes, cont, mes);
                printf("\n\nTotal: %d", qtAniversariantesMes);
                printf("\n\n");
                pause();
                break;

            case 5: //GRAVAR arquivo
                GravaArquivo(aniversariantes,cont);
                cont=0;
                
                break;

            case 6: //Le arquivo
                leArquivo();
                printf("\n\n");
                pause();
                break;

            case 7: //Num Registros no arquivo
                printf("Existem %d cadastrados no arquivo e %d na memoria.",contRegistros(), cont);
                printf("\n\n");
                pause();
                break;

            case 8: //Localizar nome com J
                //leArquivoGravaVetor(aniversariantesAux);
                localizar_J(aniversariantesAux);
                pause();
                break;

            case 9: //Localiza Ana
                localizaAna(aniversariantesAux);
                pause();
                break;
            

            case 10:
                printf("\nVoce saiu!\n\n");
                break;
            
            default:
                printf("\n\nDigite uma opcao entre 1 e 5.\n\n");
                break;
        }

    } while(opcao!=10);

    return 0;
}

int menu(){
    int op;
    printf("\nMENU\n");
    printf("\n1 - cadastrar contato");
    printf("\n2 - Lista todos os contatos");
    printf("\n3 - Informe aniversariantes");
    printf("\n4 - Informe qt aniversariantes do mes");
    printf("\n5 - Gravar arquivo");
    printf("\n6 - Le Arquivo");
    printf("\n7 - Quantidade de registros");
    printf("\n8 - Localizar nomes com J");
    printf("\n9 - Localizar nomes com Ana");
    printf("\n10 - Sair");
    printf("\n\nDigite uma opcao: ");
    scanf("%d",&op);
    fflush(stdin);
    return op;
}

void limparTela(){
    system("cls");
}

void pause(){
    system("pause");
}

struct t_agenda cadastroContato(){

    struct t_agenda contato;
    do{
        printf("Digite o nome: ");
        scanf("%[^\n]",&contato.nome);
        fflush(stdin);
    }while(strlen(contato.nome)<3);

    do{
        printf("Digite o telefone (XX) XXXXXXXXX: ");
        scanf("%[^\n]",&contato.telefone);
        fflush(stdin);
    }while(strlen(contato.telefone)<9);

    do{
        printf("Digite o dia/mes: ");
        scanf("%d/%d",&contato.data.dia, &contato.data.mes);
        fflush(stdin);
    }while((contato.data.dia<1 || contato.data.dia > 31) || (contato.data.mes<1 || contato.data.mes>12));
    
    return contato;
}

void imprimeAgenda(struct t_agenda contatos[TAM] , int qtContatos){
    int i;
    for(i=0; i<qtContatos; i++){
        printf("\nNome: %s", contatos[i].nome);
        printf("\nTelfone: %s",contatos[i].telefone);
        printf("\nDia: %02d",contatos[i].data.dia);
        printf("\nMes: %02d\n",contatos[i].data.mes);
    }
    qtContatos=0;
}

void imprimeAniversariante(struct t_agenda contatos[TAM] , int qtContatos, int dia, int mes){
    int i;
    int qt=0;    

    for(i=0; i<qtContatos; i++){
        if(contatos[i].data.mes==mes && contatos[i].data.dia==dia){
            qt++;
            if(qt==1){
                printf("\nAniversariantes: ");
            }
            printf("\n - %s", contatos[i].nome);        
        }
    }
    if(qt==0){
        printf("\nNao existem aniversariantes!\n\n");
    }

}

int imprimeQtAniversariantesMes(struct t_agenda contatos[TAM] , int qtContatos, int mes){
    int i;
    int qt=0;    

    for(i=0; i<qtContatos; i++){
        if(contatos[i].data.mes==mes){
            qt++;
            if(qt==1){
                printf("\nAniversariantes do mes %02d:",mes);
            }
            printf("\n - %s", contatos[i].nome);       
        }
    }
    if(qt==0){
        return 0;
    }
    return qt;
}

void GravaArquivo(struct t_agenda aniversariantes[TAM], int qtContatos){
    int i;
    FILE *arquivo;
    arquivo = fopen("contatos.txt","at");
    struct t_agenda msGrava[TAM];
    //fwrite(&msGrava,sizeof(struct t_agenda),1,arquivo);
    for(i=0;i<qtContatos;i++){
        fprintf(arquivo, "%s;%s;%d;%d;\n",aniversariantes[i].nome,aniversariantes[i].telefone, aniversariantes[i].data.dia,aniversariantes[i].data.mes);
    }
    //putc('\0',arquivo);
    //fwrite(&msGrava,sizeof(struct t_agenda),1,arquivo);

    fclose(arquivo);
}

void leArquivo(){

    int i=0;
    int qtRegistros = contRegistros();
  
    FILE *arquivo;
    
    char c;
    arquivo = fopen("contatos.txt","rt");

    do{
        c=getc(arquivo);
        printf("%c",c);
    }while(c!=EOF);

    fclose(arquivo);    
}

int contRegistros(){

    FILE *arquivo;
    int qtLinhas=0;
    char c;
    
    arquivo = fopen("contatos.txt","r");
    
    while(!feof(arquivo)){
        if(c=getc(arquivo)=='\n'){
            qtLinhas++;
        }
    }

    fclose(arquivo);

    return qtLinhas;
}

void localizaInicialNome(){

    FILE *arquivo;
    arquivo = fopen("contatos.txt","rt");
    int i, qtLinhas = contRegistros();

    struct t_agenda *contatos;
    contatos = malloc(sizeof(contatos)*qtLinhas);

    if(arquivo != NULL)	{
		
        do{
          
        } while(!feof(arquivo));
        
        fclose(arquivo);
	}

	

}


void leArquivoGravaVetor(struct t_agenda aniversariantesAux[]){

    int i,j;
    int qtRegistros = contRegistros();
    char vetor[100];
    char *p;
 
    FILE *arquivo;
    
    arquivo = fopen("contatos.txt","rt");

        for(j=0;j<qtRegistros;j++){

            i=0;
        
            do{ 
                vetor[i]=getc(arquivo);
            }while(vetor[i++]!='\n');
        
            //printf("%s",vetor);

            p = strtok(vetor,";");
            strcpy(aniversariantesAux[j].nome, p);
            printf("\n%s", aniversariantesAux[j].nome);
            
            p = strtok(NULL,";");
            strcpy(aniversariantesAux[j].telefone, p);
            printf("\n%s", aniversariantesAux[j].telefone);
            
            p = strtok(NULL,";");
            aniversariantesAux[j].data.dia = (int)p;
            printf("\n%s", aniversariantesAux[j].data.dia);
            
            p = strtok(NULL,";");
            aniversariantesAux[j].data.mes = (int)p;
            printf("\n%s\n", aniversariantesAux[j].data.mes);
            
        }
    
    printf("\n");
    fclose(arquivo);    
}

void localizar_J(struct t_agenda aniversariantesAux[TAM]){
    
    
    int i,j;
    int qtRegistros = contRegistros();
    char vetor[100];
    char *p;
 
    FILE *arquivo;
    
    arquivo = fopen("contatos.txt","rt");

        for(j=0;j<qtRegistros;j++){

            i=0;
        
            do{ 
                vetor[i]=getc(arquivo);
            }while(vetor[i++]!='\n');
        
            p = strtok(vetor,";");
            strcpy(aniversariantesAux[j].nome, p);
            p = strtok(NULL,";");
            strcpy(aniversariantesAux[j].telefone, p);
            p = strtok(NULL,";");
            aniversariantesAux[j].data.dia = (int)p;
            p = strtok(NULL,";");
            aniversariantesAux[j].data.mes = (int)p;
            
        }


    
    for(i=0;i<qtRegistros;i++){
        if(aniversariantesAux[i].nome[0]=='J'){
            printf("\n%s",aniversariantesAux[i].nome);
            printf("\n%s",aniversariantesAux[i].telefone);
            printf("\n%s",aniversariantesAux[i].data.dia);
            printf("\n%s",aniversariantesAux[i].data.mes);
            printf("\n");
        }
    }
    
}




void localizaAna(struct t_agenda aniversariantesAux[]) {


    int i,j;
    int qtRegistros = contRegistros();
    char vetor[100];
    char *p;
 
    FILE *arquivo;
    
    arquivo = fopen("contatos.txt","rt");

        for(j=0;j<qtRegistros;j++){

            i=0;
        
            do{ 
                vetor[i]=getc(arquivo);
            }while(vetor[i++]!='\n');
        
            p = strtok(vetor,";");
            strcpy(aniversariantesAux[j].nome, p);
            p = strtok(NULL,";");
            strcpy(aniversariantesAux[j].telefone, p);
            p = strtok(NULL,";");
            aniversariantesAux[j].data.dia = (int)p;
            p = strtok(NULL,";");
            aniversariantesAux[j].data.mes = (int)p;
            
        }


    for(i=0;i<qtRegistros;i++){
        p = strstr(aniversariantesAux[i].nome,"Ana");
        if(p!=NULL){
            printf("\n%s",aniversariantesAux[i].nome);
            printf("\n%s",aniversariantesAux[i].telefone);
            printf("\n%s",aniversariantesAux[i].data.dia);
            printf("\n%s",aniversariantesAux[i].data.mes);
            printf("\n");
        }
    }
}