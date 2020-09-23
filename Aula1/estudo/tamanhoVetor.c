
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int main(void){

    setlocale(LC_ALL, "Portuguese");
    
    int valores[] = { 1, 2, 3, 4, 5 };

    //int size = sizeof valores / sizeof valores[0];
    int size = sizeof valores / sizeof *valores;
    
    printf("Tamanho do vetor \"valores\": %u", size);
    
    printf("\n\nPressione uma tecla para continuar!\n\n");
    getch();
    
    return 0;

}