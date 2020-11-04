#include<stdio.h>
#include<stdlib.h>

float mediaArit(float a, float aux);

int main()
{
	float a, aux;
	printf ("\n Digite um numero: ");
	scanf("%f", & a);
	aux=a;
	printf("Resultado: %.2f", mediaArit(a, aux));
    return 0;
}


float mediaArit(float a, float aux)
{
	if (a>0){
		return (a/aux)+mediaArit(a-1, aux);
	}

}