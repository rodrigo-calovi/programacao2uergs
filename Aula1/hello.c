
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int main(void){

    setlocale(LC_ALL, "Portuguese");
    
    printf("\n");
    printf("Olá Mundo!");
    printf("\n");
    printf("Hello World!");
    
    printf("\n\nPressione uma tecla para continuar!\n\n");
    getch();
    
    return 0;

}