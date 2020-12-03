/**
 * 3) Peça ao usuário para digitar seus dados pessoais (Nome, Endereço, Data de
 * Nascimento, Cidade, CEP, email),verifique se as informações de Data de Nascimento, 
 * CEP e email fazem sentido, e mostre ao usuário as informações, se estão todas 
 * corretas, ou  mostre que alguma informação está errada. Armazene, se correto os 
 * valores de entrada em uma struct.
 *
 * @author Rodrigo Britto Calovi (rodrigo-calovi@uergs.edu.br)
 * @date 2020-12-02
 * 
 * UERGS - prof. Dra. Magrit Krug
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dados (char)(dados)
typedef struct {
    char nome[51];
    char endereco[51];
    char dataAniversario[11];
    char cidade[51];
    char cep[11];
    char email[51];
} Tdados ;


int verificaDados(char nome[], char email[], char endereco[], int dia, int mes, int ano, char cidade[], char cep[]);
void imprimeDados(Tdados t_dado);

int main() {
    
    Tdados t_dado;

    int erro;

    char nome[51];
    char endereco[51];
    int dia, mes, ano;
    char cidade[51];
    char cep[11];
    char email[51];

    printf("Digite o seu Nome: ");
    gets(nome);
    
    printf("Digite o e-mail: ");
    gets(email);

    printf("Digite o aniversario [DD/MM/AAAA]: ");
    scanf("%02d/%02d/%04d/",&dia,&mes,&ano);
    fflush(stdin);
   
    printf("Digite o CEP [XXXXX-XXX]: ");
    gets(cep);

    printf("Digite o Endereco: ");
    gets(endereco);
    
    printf("Digite a cidade: ");
    gets(cidade);

    erro = verificaDados(nome, email, endereco, dia, mes, ano, cidade,cep);

    if(erro==0){
        strcpy(t_dado.nome,nome);
        strcpy(t_dado.endereco,endereco);
        sprintf(t_dado.dataAniversario,"%02d/%02d/%04d", dia, mes, ano);         
        strcpy(t_dado.cidade,cidade);
        strcpy(t_dado.cep,cep);
        strcpy(t_dado.email,email);
        
        imprimeDados(t_dado);
        printf("\n\nInformacoes - gravadas!\n");
    } else {
        printf("\nDados incorretos - erro na gravacao!\n");    
    }

    return 0;
}

int verificaDados(char nome[], char email[], char endereco[], int dia, int mes, int ano, char cidade[], char cep[]){
    
    int erro = 0;
    
    if(strlen(nome)<4){
        printf("\nDigite um nome com mais de 4 caracteres!");
        erro = 1;
    } 
    
    if(strlen(email)<5){
        printf("\n\nEmail deve possuir mais do que 5 caracteres! Ou @");
        erro = 1;
    } 

    if (strlen(email)>5) {
        int i=0;
        for(i=0;i<strlen(email);i++){
            if(email[i]=='@'){
                erro=0;
                break;
            } else {  
                erro = 1;
            }
        }
        printf("\nEmail deve possuir mais do que 5 caracteres! Ou @");
    }

    if(dia<1 || dia > 31){
        printf("\nDia deve ser entre 1 a 31.");
        erro = 1;
    }
    
    if(mes<1 || mes > 12){
        printf("\nMes deve ser entre 1 e 12.");
        erro = 1;
    }

    if(ano<1900 || ano > 3000){
        printf("\nAno deve ser entre 1900 a 3000.");
        erro = 1;
    }

    if(strlen(endereco) < 10){
        printf("\nEndereco deve possuir no minimo 10 caracteres!");
        erro = 1;
    }
    
    if(strlen(cidade) < 4){
        printf("\nCidade deve possuir no minimo 4 caracteres!");
        erro = 1;
    }
    
    if(strlen(cep) !=9){
        printf("\nCep deve possuir 9 caracteres!");
        erro = 1;
    }


    return erro;    
}


void imprimeDados(Tdados t_dado){
    printf("\n\n-----------------------------------");
    printf("\nNOME: %s", t_dado.nome);
    printf("\nEmail: %s", t_dado.email);
    printf("\nData de Aniversario: %s", t_dado.dataAniversario);
    printf("\nEndereco: %s", t_dado.endereco);
    printf("\nCidade: %s", t_dado.cidade);
    printf("\nCEP: %s", t_dado.cep);
    printf("\n\n-----------------------------------");
}
