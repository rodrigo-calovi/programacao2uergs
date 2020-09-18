
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int main(void){

    setlocale(LC_ALL,"portuguese");
    
    printf("Olá Mundo!");
    printf("\n");
    printf("Hello World!");
    
    printf("Pressione uma tecla para continuar!");
    getch();
    
    return 0;

}