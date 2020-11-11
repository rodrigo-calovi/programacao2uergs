#include <stdio.h>
#include <stdlib.h>

int tamanhoOcupadoVetor(char vet[]);

int main (){
    char nome[15];
    char letra;
    int i, tamanho, qtRepeticao=0;
    system("cls");
    printf("\nDigite um nome: ");
    scanf("%s", &nome);
    fflush(stdin);
    
    printf("\nNome: %s", nome);

    tamanho=tamanhoOcupadoVetor(nome);
    printf("\nTamanho do nome: %d", tamanho );

    printf("\n\nDigite a letra a substituir: ");
    letra = getchar();

    for(i=0; i<tamanho; i++){
        if(nome[i]==letra){
           nome[i]='*';
           qtRepeticao += 1;
        }
    }
     printf("\nA letra '%c', se repete %d vezes.", letra, qtRepeticao);
     printf("\n\nNome: %s\n", nome);

    printf("\nTamanho Vetor: %d\n\n", sizeof(nome));

    return 0;
}

int tamanhoOcupadoVetor(char *vet){
    int size = 0;
    while(*vet++){
        size++;
    }
    return size;
}