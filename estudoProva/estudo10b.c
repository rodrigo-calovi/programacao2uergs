#include<stdio.h>
#include<stdlib.h>

float mediaAritimetica(int a, int aux);

int main(){
	
	float a, aux;
	printf ("\n Numero inteiro para calculo de media: "); scanf("%f", & a);
	aux=a;
	printf("Resultado: %.2f", mediaArit(a, aux));
	

    return 0;
}


float mediaArit(int a, int aux)
{
	
	if (a>1){
		return (a/aux)+mediaArit(a-1, aux);
	}

}