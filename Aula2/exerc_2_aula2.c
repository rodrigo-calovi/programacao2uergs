
/*
*Exercício 1:
* Fazer um programa para calcular a área de um quadrado, um retângulo ou um triângulo retângulo. 
* O programa deve perguntar qual a figura geométrica, e então pedir para o usuário digitar os tamanhos dos lados (1 – quadrado, 2 – retângulo, 3 triângulo retângulo). 
* Um quadrado só tem um tamanho de lado, o retângulo tem dois, e o triângulo retângulo também tem dois lados(mais a hipotenusa, mas neste caso não é necessário digitar este valor).
* Após a digitação, o programa deve calcular a área e apresentar ao usuário.
* Utilizar uma função para a leitura dos lados (verificando se não é digitado um valor negativo para o lado), e uma função para o cálculo de cada área. As fórmulas são
* Área_quadrado = lado * lado
* Área_retângulo = lado1 * lado2
* Área_triângulo = (lado 1 * lado 2)/2
*
* Resolução by Rodrigo Calovi
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>


int main(){
    
   
    setlocale(LC_ALL, "Portuguese");  
    
        printf("Digite uma tecla para continuar!\n\n");
        getch();
        
    
    
    return 0;

}

