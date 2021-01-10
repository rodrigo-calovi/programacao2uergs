#include <stdio.h>
#include <stdlib.h>

int main(){

    //PUTS
    puts("Luana"); //escreve na tela em forma de string

    //PUTC
    FILE *arquivo;
    arquivo = fopen("teste.txt","w+t");
    putc('L',arquivo); //escreve 'L' no arquivo
    putc('u',arquivo);
    putc('a',arquivo);
    putc('n',arquivo);
    putc('a',arquivo);
    putc(32,arquivo); //32 espaco ou ' ';
    putc('S',arquivo);
    fclose(arquivo);
    
    //PUTCHAR
    putchar('A'); //escreve 'A' na tela
    putchar('n');
    putchar('a');

    //FPUTS
    arquivo = fopen("teste.txt","at");
    fputs("\nBatatinha",arquivo); //escreve batatinha no arq
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
    fputchar('j');//escreve 'J' na tela
    fputchar('u');
    fputchar('j');
    fputchar('u');
    fputchar('b');
    fputchar('a');

    
    return 0;
}