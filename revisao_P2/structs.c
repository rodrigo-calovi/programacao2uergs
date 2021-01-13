#include <stdio.h>
#include <stdlib.h> // struct
#include <string.h>

typedef enum {
    JANEIRO = 1, FEVEREIRO = 2, MARCO =3
} t_mes;

typedef struct {
    int dia;
    int mes;
    int ano;
} t_agenda;


struct t_pessoa {
    char nome[20];
    char endereco[50];
    int idade;
    t_agenda calendario;
};

 struct t_acor{
    char nomeCor[5];
    int  numcor;
};

 typedef struct {
    char nomeCor[5];
    int  numcor;
} t_cor2;



//void funcao(struct t_acor cor);
void funcao2(struct t_pessoa p1);
void funcao(t_cor2 cor2[]);


int main(){

    t_mes mes = JANEIRO;
    switch (mes)
    {
    case JANEIRO:
        printf("\n%d",JANEIRO);
        break;
    
    default:
        break;
    }

    
    struct t_pessoa p1;
    p1.idade=2;
    printf("\n%d",p1.idade);

    funcao2(p1);
    printf("\n%d",p1.idade);


    t_agenda agenda;

//----------------------------------------------------------
    struct t_acor *cor;
    cor = (struct t_acor*) malloc(sizeof(struct t_acor));
   
    printf("\nDigite o nome da cor: ");
    scanf("%s",&cor->nomeCor);
    fflush(stdin);

    printf("Digite o numero da cor: ");
    scanf("%s",&(*cor).numcor);
    fflush(stdin);
   
//----------------------------------------------------
    t_cor2 cor2[2];
    //cor2 = (t_cor2*) malloc(sizeof(t_cor2));

    printf("Digite o nome da cor: ");
    scanf("%s",&cor2[0].nomeCor);
    fflush(stdin);

    printf("Digite o nome da cor: ");
    scanf("%s",&cor2[1].nomeCor);
    fflush(stdin);

    printf("\n\n");
    
    printf("%s",cor2[0].nomeCor);
    funcao(cor2);
    printf("Novo valor: %s",cor2[0].nomeCor);

    printf("\n\n");
    printf("Digite o numero da cor: ");
    scanf("%s",&(*cor2).numcor);
    fflush(stdin);
//----------------------------------------------------

    //usando o typedef
    printf("\nDigite um dia: ");
    scanf("%d",&agenda.dia);
    printf("\nDia: %d\n",agenda.dia);

    //usando struct dentro de struct
    printf("\nDigite o dia: ");
    scanf("%d", &p1.calendario.dia);
    fflush(stdin);

    printf("Digite o mes: ");
    scanf("%d", &p1.calendario.mes);
    fflush(stdin);
    
    printf("Digite o ano: ");
    scanf("%d", &p1.calendario.ano);
    fflush(stdin);

    printf("\n%02d/%02d/%02d\n",p1.calendario.dia, p1.calendario.mes, p1.calendario.ano);


    
    //copia por funcao
    strcpy(p1.nome,"Rodrigo"); //passar por cópia não direto
    p1.idade = 15;

    printf("\nDigite o endereco: ");
    scanf("%s", &p1.endereco);
    fflush(stdin);

    printf("\nNome: %s", p1.nome);
    printf("\nEndereco: %s", p1.endereco);
    printf("\nIdade: %d", p1.idade);


    return 0;
}

//void funcao(struct t_acor *cor){
//}

void funcao2(struct t_pessoa p1){
    p1.idade=10;
    printf("\n%d",p1.idade);
}


void funcao(t_cor2 cor2[]){
    printf("\n%s",cor2[0].nomeCor);
    printf("\n%s",cor2[1].nomeCor);
    printf("\nDigite valor cor2: ");
    scanf("%s",&cor2[0].nomeCor);
    fflush(stdin);
    
}