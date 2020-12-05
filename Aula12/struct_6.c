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

typedef struct {
    char titulo[30];
    char autor[15];
    int ano;
} Tlivro;

#define TAM 5

