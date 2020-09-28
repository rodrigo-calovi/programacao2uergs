
/*
*Exercício 2:
*Criar um programa para calcular o tempo entre dois horários quaisquer de um determinado dia.
*
*O programa deve ler dois horários, compostos por três números inteiros, representando horas,
* minutos e segundos. O programa deve verificar se o horário é válido(horas entre 0 e 23,
* minutos entre 0 e 59, e segundos entre 00 e 59).
*
*O programa deve ter uma função para calcular a quantidade de segundos em um horário, 
* e outra função para calcular e imprimir a quantidade de horas, minutos e segundos em uma quantidade de segundos;
*
* Resolução by Rodrigo Calovi
*
*  comparação com: https://www.calculadora-online.xyz/calculadora-horario.php
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define TRUE 1
#define FALSE 0
#define LINHA 2
#define COLUNA 4

int verificaHora(int hora, int minuto, int segundo);
int transf2Seg(int hora, int min, int seg);
int diferencaHorario(int hora1, int hora2);
float transfHora(int segundos);
float transfMin(int segundos);
float transfSeg(int segundos);
void imprimeSegundos(int valor);

int dadosValidos = FALSE;

int main(){
    
    int hora, minuto, segundo;
    int dados[LINHA][COLUNA];
    int i, tempoSeg;
    
    setlocale(LC_ALL, "Portuguese");  
    
    for(int i=0;i<LINHA;i++){
        do{
            printf("Digite horario[%i] da forma [hh:mm:ss]: ",i+1);
            scanf("%d:%d:%d",&hora,&minuto,&segundo);
            dadosValidos = verificaHora(hora,minuto,segundo);

            if(dadosValidos){
                dados[i][0]=hora;
                dados[i][1]=minuto;
                dados[i][2]=segundo;
                dados[i][3]=transf2Seg(hora,minuto,segundo);
                //printf("\nHora inserida valida: %d:%d:%d - segundos Totais: %d\n",dados[i][0],dados[i][1],dados[i][2],dados[i][3]);
            }
        }while(dadosValidos!=TRUE);
    }

    if(diferencaHorario(dados[0][3],dados[1][3])<0){
        tempoSeg=-diferencaHorario(dados[0][3],dados[1][3]);
    } else {
        tempoSeg=diferencaHorario(dados[0][3],dados[1][3]);
    }

    printf("\nDiferença de: %02.0f:%02.0f:%02.f",transfHora(tempoSeg),transfMin(tempoSeg),transfSeg(tempoSeg));
    
    imprimeSegundos(tempoSeg);

    return 0;
}


int verificaHora(int hora, int minuto, int segundo){
    if(hora>=0 && minuto >=0 && segundo >=0){
        if(hora<24 && minuto<60 && segundo <60){
            return TRUE;        
        }
    }
    return FALSE;
}

int transf2Seg(int hora, int min, int seg){
    return (hora*3600.0 + min*60.0 + seg*1.0);
}

float transfHora(int segundos){
    return segundos/3600.0;
}

float transfMin(int segundos){
    float aux = (segundos/3600.0-(segundos/3600))*60;
    if(aux>59.5){
        aux = 0;
        return aux;
    } else 
        return aux;
}

float transfSeg(int segundos){
    float aux = (segundos/3600.0-segundos/3600)*60;
    aux = (aux - (int)aux)*60;
    if(aux>59.5){
        aux = 0;
        return aux;
    } else 
        return aux;
}

int diferencaHorario(int hora1, int hora2){
    return hora1-hora2;
}

void imprimeSegundos(int valor){
    int segundos = valor;
    printf("\nOu de %d segundos", segundos);
}


