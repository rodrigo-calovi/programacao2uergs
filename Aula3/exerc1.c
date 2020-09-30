#include <stdio.h>
#include <stdlib.h>

float potencia(int base, int expoente);

float resp;

int main(){
    
    int base, expoente;
    
    printf("Digite a expressao da seguinte forma [n^n]: ");
    scanf("%d^%d",&base,&expoente);
    resp = potencia(base,expoente);

    (expoente>0) ? printf("\n%d^%d = %.2f", base, expoente,resp) : printf("%d^%d = %.16f\n\n", base, expoente,resp);
    
    return 0;
}

float potencia(int base, int expoente){
    if(expoente==0)
        return 1.0;
    else if(expoente>0)
        return 1.0*(base*potencia(base, expoente-1));
    else if(expoente<0){
        expoente=expoente*-1;
        resp = (base*potencia(base, expoente-1));
        return 1/resp;
    }
}