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
#define TAM 10

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

int main(){
    char resposta;
    int opcao;
    struct t_agenda aniversariantes[TAM];
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
                imprimeAgenda(aniversariantes, cont);
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

            case 4:
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
                break;
            case 6:
                printf("\nVoce saiu!\n\n");
                break;
            
            default:
                printf("\n\nDigite uma opcao entre 1 e 5.\n\n");
                break;
        }

    } while(opcao!=6);

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
    printf("\n6 - Sair");
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
    arquivo = fopen("contatos.txt","wt");
    //fwrite(aniversariantes,sizeof(struct t_agenda),qtContatos,arquivo);
    for(i=0;i<qtContatos;i++){
        fprintf(arquivo, "%s;%s;%d;%d\n",aniversariantes[i].nome,aniversariantes[i].telefone, aniversariantes[i].data.dia,aniversariantes[i].data.mes);
    }
    fclose(arquivo);
    
}

int numContatos(){
    int i;
    FILE *arquivo;
    char nome[TAM];
    int qtLinhas;
    
    arquivo = fopen("contatos.txt","rt");
    while(arquivo!=feof){
        fscanf(arquivo,"%s",&nome[i]);
        qtLinhas++;
    }
    
    fclose(arquivo);
    return qtLinhas;
}