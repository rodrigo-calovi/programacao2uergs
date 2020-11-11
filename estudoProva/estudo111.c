#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inverte(int n);

int main(){

    inverte(6);
    
    return 0;
}

/* Ex3 --> Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321 */
int inverte(int n) {
	if((n / 10) == 0) {
		return n;
	}
	return inverte(n / 10) + (n % 10) * pow(10, abs(log10(n)));
}