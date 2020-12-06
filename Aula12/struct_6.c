/**
 * @author Rodrigo Britto Calovi (rodrigo-calovi@uergs.edu.br)
 * @date 2020-12-02
 * UERGS - prof. Dra. Magrit Krug
 * 
 * 6)  Elabore um programa que seja uma agenda de compromissos e:
 * Crie e leia um vetor de 5 estruturas de dados com: compromisso 
 * (máximo 60 letras) e data. A data deve ser outra estrutura de 
 * dados contendo dia, mês e ano. 
 * Leia dois inteiros M e A e mostre todos os compromissos do mês 
 * M do ano A. Repita o procedimento até ler´ M = 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Tcalendario;

typedef struct {
    char compromisso[60];
    Tcalendario data;
} Tagenda;


#define TAM 5

void flush_in();
int menu();
int cadastrarCompromissos(Tagenda t_agenda[], int cont);
void pesquisaCompromisso(Tagenda t_agenda[], int mes, int ano, int cont);

int main(){
    int cont=0;
    int i,op, mes,ano;
    Tagenda t_agenda[TAM];
    Tcalendario t_calendario;

    do {
        op=menu();

        switch (op){
            case 1:
                printf("\n[%d] Compromisso(s) agendado(s)!\n",cont);
                cont = cadastrarCompromissos(t_agenda,cont);
                break;

            case 2:
                printf("Pesquisar por [mm/aaaa]: ");
                scanf("%02d/%04d",&mes,&ano);
                pesquisaCompromisso(t_agenda, mes, ano, cont);
                break;

            default:
                if(op!=0){
                    system("cls");
                    printf("--------------------------------");
                    printf("\nDigite as opcoes do menu!\n");
                    printf("--------------------------------\n");
                }
                break;
        }
    }while(op!=0);

    return 0;
}

/**
* fflush(stdin)-windows ou
* Ambiente UNIX/LINUX
* https://www.inf.pucrs.br/~pinho/LaproI/Fflush/CorrigeScanfGets.html
*
**/
void flush_in(){
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int menu(){
    //system("cls");
    int op;
    printf("\nMenu\n");
    printf("\n1 - Cadastrar compromissos");
    printf("\n2 - Ver compromissos (mes/ano)");
    printf("\n0 - Sair");
    printf("\n");
    scanf("%d",&op);
    return op;
}

int cadastrarCompromissos(Tagenda t_agenda[], int cont){

    if(cont<5){
        printf("Digite o mes: ");
        scanf("%d",&t_agenda[cont].data.mes);
        flush_in();
        if(t_agenda[cont].data.mes==0){
            return cont;
        }

        printf("Digite o ano: ");
        scanf("%d",&t_agenda[cont].data.ano);
        flush_in();

        printf("Digite o dia: ");
        scanf("%d",&t_agenda[cont].data.dia);
        flush_in();

        printf("Digite o compromisso: ");
        scanf("%[^\n]", &t_agenda[cont].compromisso);
        flush_in();

        //printf("\nCadastro: [%d]",cont);


        cont = cont +1;


    } else {
        printf("\nRegistro cheio!\n");
    }




    return cont;
}

void pesquisaCompromisso(Tagenda t_agenda[TAM], int mes, int ano, int cont){
    int i, qt=0;
    for(i=0;i<cont;i++){
        if((t_agenda[i].data.mes == mes) && (t_agenda[i].data.ano == ano)){
            printf("\n-----------------------------------");
            printf("\n-Compromisso: [%d] ",i);
            printf("\n  | Mes: [%02d]",t_agenda[i].data.mes);
            printf("\n  | Ano: [%04d]",t_agenda[i].data.ano);
            printf("\n  | Dia: [%02d]",t_agenda[i].data.dia);
            printf("\n  | Compromisso: [%s]",t_agenda[i].compromisso);
            qt++;
        }
    }
    printf("\n\nExiste(m) %d registro(s)!\n\n", qt);
}