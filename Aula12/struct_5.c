/**
 * @author Rodrigo Calovi - rodrigo-calovi@uergs.edu.br
 * @date 2020-12-04
 * 
 * @copyright Copyright (c) 2020
 * 
 *  5) Elabore um programa que leia um vetor com dados de 5 livros: título (máximo 30 letras),
 * ´ autor (máximo 15 letras) e ano. Posteriormente procure um livro por título, perguntando ao
 *  usuário qual o título deseja buscar. Mostre os dados de todos os livros encontrados.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

typedef struct {
    char titulo[30];
    char autor[15];
    int ano;
} Tlivro;

#define TAM 5


void listaLivros(Tlivro t_livro[]);
void listaLivrosPOS(Tlivro t_livro[],int pos);

int main(){

    Tlivro t_livro[TAM];
    char pesquisa[30];
    int i;

    //livro1
    strcpy(t_livro[0].titulo,"O Pequeno Principe");
    strcpy(t_livro[0].autor,"Antoine S.E");
    t_livro[0].ano = 1943;

    //livro2
    strcpy(t_livro[1].titulo,"Outlander");
    strcpy(t_livro[1].autor,"Diana Gabaldon");
    t_livro[1].ano = 1991;

    //livro3
    strcpy(t_livro[2].titulo,"Mistburn");
    strcpy(t_livro[2].autor,"Brandon Sanderson");
    t_livro[2].ano = 2006;

    //livro4
    strcpy(t_livro[3].titulo,"O Cla dos Magos");
    strcpy(t_livro[3].autor,"Trudi Canavan");
    t_livro[3].ano = 2001;

    //livro5
    strcpy(t_livro[4].titulo,"As Brumas de Avalon");
    strcpy(t_livro[4].autor,"Marion Zimmer");
    t_livro[4].ano = 1979;

    for(i=0;i<TAM;i++){
        printf("\n%s",strlwr(t_livro[i].titulo));
    }


    
    printf("\n\nDigite uma obra: ");
    scanf("%[^\n]",&pesquisa);

    for(i=0;i<TAM;i++){
        if(strcmp(strlwr(t_livro[i].titulo),strlwr(pesquisa)) == 0){
            //printf("Encontrado titulo: %s ", t_livro[i].titulo);
            listaLivrosPOS(t_livro,i);
        }
    }
    //listaLivros(t_livro);
    
    return 0;
}

void listaLivros(Tlivro t_livro[]){
    int i;
    int tamanhoVetor = TAM;
    printf("\n");
    for(i=0;i<tamanhoVetor;i++) {
        printf("\n\nTitulo: %s", t_livro[i].titulo);
        printf("\nAutor: %s", t_livro[i].autor);
        printf("\nAno: %d", t_livro[i].ano);
    }
    printf("\n");
}

void listaLivrosPOS(Tlivro t_livro[], int pos){

    printf("\n\nTitulo: %s", t_livro[pos].titulo);
    printf("\nAutor: %s", t_livro[pos].autor);
    printf("\nAno: %d", t_livro[pos].ano);
    printf("\n");
}