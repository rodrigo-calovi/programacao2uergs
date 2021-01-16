#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char buffer[10] = "";
    char caractere;
    FILE *arquivo;
    arquivo = fopen("registro.txt","r");
    if(arquivo!=NULL){
        while( (caractere = getc(arquivo)) != EOF){
            if(strlen(buffer)<9){
                //imprime o buffer e acrescenta caracter ao lado de buffer
                sprintf(buffer,"%s%c",buffer,caractere);
            } else {
                //imprime o restante de buffer
                printf("%s",buffer);
                //limpa o buffer                 
                sprintf(buffer,"%c",caractere);
            }
        }
        //final do arquivo se tiver algo ainda imprime o restante
        if(strlen(buffer)>0){
            printf("%s",buffer);
        } 
        fclose(arquivo);
    }
    printf("\n\nDigite uma tecla para sair!\n\n");
    return EXIT_SUCCESS;
}   