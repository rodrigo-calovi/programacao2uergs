#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef enum {
    FALSE = 0,
    TRUE = 1
} Tbool;

typedef struct _data{
    int dia;
    int mes;
    int ano;
} Tdata;

typedef struct _cadastro{
    char nome[30];
    long long int cpf;
    char endereco[30];
    char bairro[30];
    Tdata dataNasc;
    Tdata dataUltimaCompra;
    float valorAcumulado;
} Tcadastro;

#define TAMClientes 100
#define TAMcpf  11

int menu(); 
int cadastraCliente(int cpf[], Tcadastro *t_clientes, int pos); 
void listaCliente4Data(Tcadastro t_clientes[], int pos, int dia, int mes, int ano);
void clientes4Bairro(Tcadastro t_clientes[], int pos);
void clienteMaiorValAcumulado(Tcadastro t_clientes[], int pos);
unsigned int validaCPF(int *numCPF);
void getCPF(int *destino, int *source);
void imprimeClientes(Tcadastro t_clientes[], int pos);

int main(){
    int op;
    int isCPF = FALSE;
    int numCPF[TAMcpf];
    int pos=0, dia, mes, ano;

    Tcadastro t_clientes[TAMClientes];
    
    do{
        op=menu();
        switch (op) {
            case 1:
                if(pos<TAMClientes){
                    isCPF = validaCPF(numCPF);
                    isCPF ? pos=cadastraCliente(numCPF,t_clientes,pos) : printf("CPF nao eh valido!");
                } else {
                    printf("cadastro lotado!");
                }
                break;
            
            case 2:
                printf("Digite a data: ");
                scanf("%02d/%02d/%4d",&dia,&mes,&ano);
                listaCliente4Data(t_clientes, pos, dia, mes, ano);
                break;

            case 3:
                clientes4Bairro(t_clientes, pos);
                break;

            case 4:
                clienteMaiorValAcumulado(t_clientes, pos);
                break;

            default:
                if(op!=5){
                    printf("Digite uma opcao de 1 a 5!");
                }
                break;
        }
    } while(op!=5);

    return 0;
}

int menu(){
    int op;
    printf("\n\n\tMenu\n");
    printf("\n\t1 - Cadastrar clientes");
    printf("\n\t2 - Listar cliente com compra por data informada");
    printf("\n\t3 - Listar clientes por bairro");
    printf("\n\t4 - Listar cliente com maior valor acumulado de compras");
    printf("\n\t5 - Fim\n\n");
    scanf("%d",&op);
    return op;
}

int cadastraCliente(int cpf[TAMcpf], Tcadastro *t_clientes, int pos){

    fflush(stdin); //precisei limpar buffer de entrada
    Tcadastro t_cadastro;
    Tdata t_data;
    long long int cpfAux;

    printf("\n---CADASTRO---\n");
    
    printf("\nNome: ");
    gets(t_cadastro.nome);
    //scanf("%*[^\n]",&t_cadastro.nome); // Deu problema
    //fflush(stdin);

    printf("CPF: ");
    printf("%d%d%d.%d%d%d.%d%d%d-%d%d",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8],cpf[9],cpf[10],cpf[11]);
    cpfAux = cpf[0]*10000000000+cpf[1]*1000000000+cpf[2]*100000000+cpf[3]*10000000+cpf[4]*1000000+cpf[5]*100000+cpf[6]*10000+cpf[7]*1000+cpf[8]*100+cpf[9]*10+cpf[10]*1;
    t_cadastro.cpf = cpfAux;
    //printf("\n%lli",t_cadastro.cpf);

    printf("\nEndereco: ");
    gets(t_cadastro.endereco);
    
    printf("Bairro: ");
    gets(t_cadastro.bairro);
    
    printf("Data de Nascimento: ");
    scanf("%02d/%02d/%4d*%[^\n] ", &t_cadastro.dataNasc.dia,&t_cadastro.dataNasc.mes,&t_cadastro.dataNasc.ano) ;
    fflush(stdin);
    
    printf("Data da Ultima Compra: ");
    scanf("%02d/%02d/%4d*%[^\n] ", &t_cadastro.dataUltimaCompra.dia,&t_cadastro.dataUltimaCompra.mes,&t_cadastro.dataUltimaCompra.ano) ;
    fflush(stdin);

    printf("Valor Total de gastos: ");
    scanf("%f*%[^\n]",&t_cadastro.valorAcumulado);
    fflush(stdin);
        
    strcpy(t_clientes[pos].nome,t_cadastro.nome);
    t_clientes[pos].cpf = t_cadastro.cpf;
    strcpy(t_clientes[pos].endereco,t_cadastro.endereco);
    strcpy(t_clientes[pos].bairro,t_cadastro.bairro);
    t_clientes[pos].dataNasc.dia = t_cadastro.dataNasc.dia;
    t_clientes[pos].dataNasc.mes = t_cadastro.dataNasc.mes;
    t_clientes[pos].dataNasc.ano = t_cadastro.dataNasc.ano;
    t_clientes[pos].dataUltimaCompra.dia = t_cadastro.dataUltimaCompra.dia;
    t_clientes[pos].dataUltimaCompra.mes = t_cadastro.dataUltimaCompra.mes;
    t_clientes[pos].dataUltimaCompra.ano = t_cadastro.dataUltimaCompra.ano;
    t_clientes[pos].valorAcumulado = t_cadastro.valorAcumulado;

    pos = pos+1;

    return pos;
}

void listaCliente4Data(Tcadastro t_clientes[TAMClientes], int pos, int dia, int mes, int ano){
    int i;

    for(i=0;i<pos;i++){
        if(t_clientes[i].dataUltimaCompra.dia==dia && t_clientes[i].dataUltimaCompra.mes==mes && t_clientes[i].dataUltimaCompra.ano==ano){
            printf("\n%s",t_clientes[i].nome);
            printf("\n%lli",t_clientes[i].cpf);
            printf("\n%s",t_clientes[i].endereco);
            //printf("\n%s",t_clientes[i].bairro);
            //printf("\n%02d/%02d/%4d",t_clientes[i].dataNasc.dia,t_clientes[i].dataNasc.mes,t_clientes[i].dataNasc.ano);
            //printf("\n%02d/%02d/%4d",t_clientes[i].dataUltimaCompra.dia,t_clientes[i].dataUltimaCompra.mes,t_clientes[i].dataUltimaCompra.ano);
            //printf("\n%.2f",t_clientes[i].valorAcumulado);
        }
    }
    
}

void clientes4Bairro(Tcadastro t_clientes[], int pos){
    int i, cont=0;
    char bairro[30];
    
    printf("Digite o bairro: ");
    scanf("%s",&bairro);

    for(i=0;i<pos;i++){
        if(strcmp(strlwr(t_clientes[i].bairro),strlwr(bairro))==0){
            cont++;
        }
    }
    printf("Existe(m) %d morador(es) neste bairro!", cont);
}

void clienteMaiorValAcumulado(Tcadastro t_clientes[], int pos){
    int i,j,posicao=0;
    int cpfAux[TAMcpf];
    long long int cpf;
    float maior = t_clientes[posicao].valorAcumulado;
        
    for(i=0;i<pos;i++){
        if(maior < t_clientes[i].valorAcumulado){
           maior = t_clientes[i].valorAcumulado;
           posicao = i; 
        }
    }
    if(pos>0){
        printf("\nMaior valor acumulado eh do cliente: [%d]", posicao);
        printf("\nCliente(s):");
        printf("\n%s",t_clientes[posicao].nome);
        printf("\n%lli",t_clientes[posicao].cpf);
        
    }
}

unsigned int validaCPF(int *numCPF){
    int i;
    long long int num, auxNum, div=10000000000;
    int cpf[TAMcpf];
    int digito1=0, digito2=0;

    printf("Digite o CPF: ");
    scanf("%lli",&num);

    //trunca cpf int para um vetor
    for(i=0;i<TAMcpf;i++){
        cpf[i]=num/div;
        auxNum = (num/div)*div;
        num = num-auxNum;
        div=div/10;
    }

    //soma dos digitos para o primeiro digito
    for(i=0;i<TAMcpf-2;i++){
        digito1=digito1+cpf[i]*(i+1);
    }
    
    //printf("soma d1: %d",digito1);

    //verifica digito 1
    if((digito1%11)==10){
        digito1 = 0;
    } else  {
        digito1 = digito1%11;
    }

    //printf("\nD1: %d",digito1);


   //Verificador do segundo digito
   //soma dos digitos para o primeiro digito
    for(i=0;i<TAMcpf-1;i++){
        digito2=digito2+cpf[i]*(i);
    }
    
    //printf("\n\nsoma d2: %d",digito2);

    //verifica digito 2
    if((digito2%11)==10){
        digito2 = 0;
    } else  {
        digito2 = digito2%11;
    }

   //printf("\nD2: %d",digito2); 

    if(cpf[TAMcpf-2]==digito1 && cpf[TAMcpf-1]==digito2){
        getCPF(numCPF, cpf);
        return TRUE;
    }

    return FALSE;
}

void getCPF(int *destino, int *source){
    int i;
    for(i=0;i<TAMcpf;i++){
        destino[i]=source[i];
    }
}

void imprimeClientes(Tcadastro t_clientes[TAMClientes], int pos){
    int i;
    int posicao = pos-1;
    for(i=0;i<pos;i++){
        printf("\n%s",t_clientes[posicao].nome);
        printf("\n%lli",t_clientes[posicao].cpf);
        printf("\n%s",t_clientes[posicao].endereco);
        printf("\n%s",t_clientes[posicao].bairro);
        printf("\n%02d/%02d/%4d",t_clientes[posicao].dataNasc.dia,t_clientes[posicao].dataNasc.mes,t_clientes[posicao].dataNasc.ano);
        printf("\n%02d/%02d/%4d",t_clientes[posicao].dataUltimaCompra.dia,t_clientes[posicao].dataUltimaCompra.mes,t_clientes[posicao].dataUltimaCompra.ano);
        printf("\n%.2f",t_clientes[posicao].valorAcumulado);
    }
}