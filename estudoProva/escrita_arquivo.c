#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int i;
    FILE *arquivo;
    char string[100];

    arquivo = fopen("registro.txt","wt");
    if(!arquivo){
        printf("Arquivo inexistente!");
        scanf("%c",&c);
        return 0;
    } 

    printf("\nDigite a informacao a ser registrada: ");
    gets(string);

    for(i=0; i<strlen(string); i++){
        putc(string[i],arquivo);
    }

    fclose(arquivo);

    printf("\n\nTecle algo para sair!\n\n");
    
    return EXIT_SUCCESS;
}
