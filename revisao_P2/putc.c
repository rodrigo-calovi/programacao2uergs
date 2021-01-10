#include <stdio.h>
#include <stdlib.h>

int main(){

    //PUTS
    puts("Rodrigo"); //escreve na tela em forma de string

    //PUTC
    FILE *arquivo;
    arquivo = fopen("teste.txt","w+t");
    putc('C',arquivo); //escreve 'C' no arquivo
    putc('a',arquivo);
    putc('l',arquivo);
    putc('o',arquivo);
    putc('v',arquivo);
    putc('i',arquivo);
    putc(32,arquivo); //32 espaco ou ' ';
    putc('S',arquivo);
    fclose(arquivo);
    
    //PUTCHAR
    putchar('R'); //escreve 'R' na tela
    putchar('B');
    putchar('C');

    //FPUTS
    arquivo = fopen("teste.txt","at");
    fputs("\nchocolate",arquivo); //escreve batatinha no arq
    fclose(arquivo);
    
    
    //FPUTC
    arquivo = fopen("teste.txt","at");
    fputc(' ',arquivo);
    fputc('B',arquivo); //escreve 'B' no arquivo 
    fputc('a',arquivo);
    fputc('t',arquivo);
    fputc('a',arquivo);
    fputc('t',arquivo);
    fputc('a',arquivo);
    fputc(' ',arquivo);
    fclose(arquivo);


    //FPUTCHAR
    fputchar(' ');//escreve 
    fputchar('t');//escreve 't' na tela
    fputchar('e');
    fputchar('s');
    fputchar('t');
    fputchar('e');
    
    return 0;
}