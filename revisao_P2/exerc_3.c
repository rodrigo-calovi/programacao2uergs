/** 
 * 3)	Elabore um programa para controlar a agenda de aniversariantes. 
 * Cadastra-se o nome, o telefone e o dia do aniversário (dia e mês) de 
 * cada pessoa. A agenda pode armazenar até 15 contatos. Implemente um 
 * menu com: 
 * 1- cadastrar contato,
 * 2 – Lista todos os contatos, 
 * 3 – Informa aniversariantes (nome dos aniversariantes ou a 
 * informação que não existe aniversariante) do dia informado pelo teclado, 
 * 4 – Informa quantidade de aniversariantes do mês informado pelo teclado.
 **/

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
void imprimeAniversariante(struct t_agenda contatos[TAM] , int qtContatos, int dia, int mes);
int imprimeQtAniversariantesMes(struct t_agenda contatos[TAM] , int qtContatos, int mes);

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

            case 5:
                printf("\nVoce saiu!\n\n");
                break;
            
            default:
                printf("\n\nDigite uma opcao entre 1 e 5.\n\n");
                break;
        }

    } while(opcao!=5);

    return 0;
}

int menu(){
    int op;
    printf("\nMENU\n");
    printf("\n1 - cadastrar contato");
    printf("\n2 - Lista todos os contatos");
    printf("\n3 - Informe aniversariantes");
    printf("\n4 - Informe qt aniversariantes do mes");
    printf("\n5 - Sair");
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


