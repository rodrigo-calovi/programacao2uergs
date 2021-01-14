#include <stdio.h>

#define VAR(var)    n##var              //concatenacao
#define SHOW(x)     printf(#x)          //coisas
#define TAM         15                  //definicao
#define NOME        "Rodrigo Calovi"    //definicao
#define ABS(x)      (x>0) ? (x) : -(x)  //condicao
#define mult(x,y)   (x*y)               //funcao

int main(){
    int n1=100, n2=200;
    printf("%d\n",VAR(1));
    printf("%d\n",VAR(2));
    SHOW(Engenharia de Computacao);
    printf("\nTAM: %d",TAM);
    printf("\n%s\n",NOME);
    printf("ABS: %d\n",ABS(-5));
    printf("x*y: %d",mult(5,3));
    return 0;
}