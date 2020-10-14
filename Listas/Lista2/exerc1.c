/**
 *  1)	Observe o código abaixo e responda:
*   a)	O que faz este programa?
*   b)	Se os valores 1, 2 e 8 forem informados, qual será a saída no printf do main?
*   c)	Que valores serão impressos no printf da funcao se os valores 1, 2 e 8 forem informados?
*   Resolução by Rodrigo Calovi
*   Programação e Algoritmos 2
* teste de mesa
* i=1 | n=8 | i<n | n%i | num | num = num + i    |
*  1  |  8  | 1<8 | 8%1 |  0  |  num = 0 + 1 = 1 | 
*  2  |  8  | 2<8 | 8%2 |  1  |  1+2=3
*  3  |  8  | 3<8 | 8%3 |  3  |  -
*  4  |  8  | 4<8 | 8%4 |  3  |  3+4=7
*  5  |  8  | 5<8 | 8%5 |  7  |  -
*  6  |  8  | 6<8 | 8%6 |  7  |  - 
*  7  |  8  | 7<8 | 8%7 |  7  |  -
*  8  |  8  | 8<8 fim
*
* num = 7;
* a) teste de mesa, quando saída eh 1 é numero primo, soma o num das linhas que divididas restam 0.
* b)no printf -> 0, 1 e 7
* c) 0,1,7
**/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

int funcao (int n);

int main(){ 
    
    int numero, i;
     
     for(i = 0; i < 3; i++) {
        printf("digite o %d número: ", i+1);
        scanf("%d", &numero); 
        printf("\n\tSaída =  %d\n", funcao(numero));
    } 

    return 0;
 } 

int funcao(int n) { 
    int i = 1,  num = 0; 
    printf("Valores de %d: ", n);
    while( i < n ){ 
         if (n % i == 0){ 
             num = num+ i;
         } 
      i++; 
    } 
  
   return  num; 
}