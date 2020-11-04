#include <stdio.h>
#include <stdlib.h>

int main(){

    int num, *p;
    num=55;
    p=&num;
    printf("\nValor inicial: %d\n", num);
    *p=100;
    printf("\nValor final: %d \n", num);
    
    return 0;
}