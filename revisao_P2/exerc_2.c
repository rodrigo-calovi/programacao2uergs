/** 
 * 2)	Elabore um programa que leia 3 strings. Compare as 
 * strings e se duas delas forem iguais preencha uma delas 
 * com X mantendo o conteúdo da outra. Caso as três forem 
 * iguais preencha 2 delas com Y e mantendo uma delas. No 
 * caso das três serem diferentes imprima-as de traz para 
 * frente.
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 10

void imprime(char string1[TAM], char string2[TAM], char string3[TAM]);
void imprimeReverso(char string[TAM]);

int main(){

    char string1[TAM],string2[TAM],string3[TAM];
    int i;
   
    printf("String_1: ");
    scanf("%s",string1);

    printf("String_2: ");    
    scanf("%s",string2);

    printf("String_3: ");
    scanf("%s",string3);

    if(strcmp(string1,string2)==0 && strcmp(string1,string3)== 0){
        for(i=0;i<strlen(string1);i++){
            string1[i]='Y';
            string2[i]='Y';
        }
        imprime(string1, string2, string3);
    }else if(strcmp(string1,string2)==0 && strcmp(string1,string3)!=0 ){
        for(i=0;i<strlen(string1);i++){
            string1[i]='X';
        }
        imprime(string1, string2, string3);
    } else if(strcmp(string1,string3)==0 && strcmp(string1,string2)!=0 ){
        for(i=0;i<strlen(string1);i++){
            string1[i]='X';
        }
        imprime(string1, string2, string3);
    }  else if(strcmp(string2,string3)==0 && strcmp(string1,string2)!=0 ){
        for(i=0;i<strlen(string2);i++){
            string2[i]='X';
        }
        imprime(string1, string2, string3);
    } else {
        imprimeReverso(string1);
        imprimeReverso(string2);
        imprimeReverso(string3);
       
    }
    return 0;
}

void imprime(char string1[TAM], char string2[TAM], char string3[TAM]){
    printf("\n%s",string1);
    printf("\n%s",string2);
    printf("\n%s",string3);
}

void imprimeReverso(char string[TAM]){
    int i;
    char stringAux;
    for(i = 0; i < (strlen(string)/2); i++){
        stringAux = string[i]; //guarda character inicial
        string[i] = string[strlen(string) - i]; //Troca character oposto
        string[strlen(string) - i] = stringAux; //Armazena character em string
    }
    printf("\n%s",string);
}