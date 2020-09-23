
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
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

unsigned int menu();
unsigned int digitaValor();
unsigned int areaQuadrado();
unsigned int areaRetangulo();
unsigned int areaTriangulo();

int main(){
    
    unsigned int op,lado1;

    setlocale(LC_ALL, "Portuguese");  
    
    op=menu();
    
    while(op!=0){

        switch (op){
            
        case 1:
            printf("\n\nÁrea do quadrado: \n");
            printf("\nÁrea: %u",areaQuadrado());
            printf("\n\n");
            break;
        case 2:
            printf("\n\nÁrea do retângulo: \n");
            printf("\nÁrea: %u",areaRetangulo());
            printf("\n\n");
            break;
        case 3:
            printf("\n\nÁrea do triangulo: \n");
            printf("\nÁrea: %u",areaTriangulo());
            printf("\n\n");
            break;
        default:
            printf("\n\nDigite entre 0 e 3!\n\n");
            break;
        }
        printf("Digite uma tecla para continuar!\n\n");
        
        getch();
        //system("pause");
        op=menu();
    }
    
    return 0;

}

unsigned int menu(){
    int op;
    printf("MENU");
    printf("\n1 - Quadrado");
    printf("\n2 - Retângulo");
    printf("\n3 - Triângulo retângulo");
    printf("\n0 - Sair");
    printf("\n");
    scanf("%d",&op);
    return op;
}

unsigned int digitaValor(){
    int lado;
    do{
        printf("#: ");
        scanf("%u", &lado);
    }while (lado<=0);
    return lado;
}

unsigned int areaQuadrado(){
    printf("\nLado: \n");
    int lado = digitaValor();
    return lado*lado;
}


unsigned int areaRetangulo(){
    printf("\nLado: \n");
    int lado1 = digitaValor();
    printf("Altura: \n");
    int lado2 = digitaValor();
    return lado1*lado2;
}


unsigned int areaTriangulo(){
    printf("\nBase:\n");
    int lado1 = digitaValor();
    printf("Altura:\n");
    int lado2 = digitaValor();
    return (lado1*lado2)/2;
}

