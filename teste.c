#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main (){

    char tecla;
    int restante;

    int i=0;

    printf("Digite algo: ");
    while(!kbhit()){
    
        tecla = getch();
        //restante++;

    }

    

    printf("%c",tecla);
    printf("%d",restante);
    return 0;
}