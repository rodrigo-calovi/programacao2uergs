#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int y, *p, x;

    y=0;
    printf("\nEndereco de y : %p ", &y);
    printf("\n\ny= %d\n",y);

    p=&y;
    printf("\np recebe endereco de y = %p\n",p); 

    x=*p;
    printf("\nx = p o valor endereco de y = %d\n", x);

    x=4;
    printf("\nx eh igual a 4 = %d\n",x);

    (*p)++;
    printf("\np incrementa conteudo de p em mais 1 = %d\n",*p);

    x--;
    printf("\nx decrementa em -1 = %d\n",x);
    
    (*p) += x;
    printf("\np incrementa conteudo de p em mais x = %d\n",*p);

    printf("\ny= %d\n",y);

    return 0;
}