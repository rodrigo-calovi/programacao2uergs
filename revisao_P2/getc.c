#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    

    //GETS
    char vetor[20];
    char caracter;
    printf("Digite algo: ");
    gets(vetor); //mesmo 'scanf("%s",&vetor);'- pega do teclado e grava no vetor
    printf("%s",vetor);

    fflush(stdin); //limpar buffer teclado



    //GETC
    FILE *arquivo;
    int c;
    arquivo = fopen("teste.txt","wt");
    fprintf(arquivo,"-Calovi-");
    //fputc('\0',arquivo);
    fclose(arquivo);
    arquivo = fopen("teste.txt","rt");
    do{
        c = getc(arquivo);//pega do arquivo 1 caracter e grava para variavel 'c'
        printf("%c",c); 
    }while(c!=EOF);
    //}while(c!=feof(arquivo));
    fclose(arquivo);

    fflush(stdin); //limpar buffer teclado



    //GETCHAR
    char tecla;
    printf("\nDigite uma tecla [ENTER]: ");
    tecla = getchar(); //pega do teclado um caracter e  coloca em tecla
    printf("%c",tecla);
    //putchar(tecla); 

    fflush(stdin); //limpar buffer teclado
    


    //FGETS
    char vetor2[20];
    char caracter2;
    arquivo=fopen("teste.txt","rt");
    fgets(vetor2,(20*sizeof(char)),arquivo); //mesmo 'scanf("%s",&vetor2);'- pega do arquivo e grava no vetor
    printf("%s",vetor2);

    fflush(stdin); //limpar buffer teclado

    //FGETC
   char c2;
    arquivo = fopen("teste.txt","rt");
    do{
        c2 = fgetc(arquivo); //pegado arquivo 1 caracter e coloca em c2
        printf("%c",c2); 
    }while(c2!=EOF);
    fclose(arquivo);

    fflush(stdin); //limpar buffer teclado

    //FGETCHAR
    char tecla2;
    printf("\nDigite uma tecla [ENTER]: ");
    tecla2 = fgetchar(); //pega do teclado um caracter e  coloca em tecla2
    printf("%c",tecla2);
    
    fflush(stdin); //limpar buffer teclado
    
    //GETCH
    char tecla_1;
    char tecla_2;
    printf("\nDigite uma tecla_1:");
    tecla_1 = getch(); //pega do teclado e salva 1 caracter no tecla_1
    printf("%c",tecla_1);
    printf("\nDigite uma tecla_2:");
    tecla_2 = getch();
    printf("%c",tecla_2);
    
    
    return 0;

}
