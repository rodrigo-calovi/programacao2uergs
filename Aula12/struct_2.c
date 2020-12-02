/**
* 2) Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
* conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
* da terceira prova. 
* (a) Permita ao usuário entrar com os dados de 5 alunos. 
* (b) Encontre o aluno com maior nota da primeira prova. 
* (c) Encontre o aluno com maior média geral. 
* (d) Encontre o aluno com menor média geral 
* (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
* aprovação.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[20];
    float p[3];
    float somaGeral;
} alunos;

#define TAM 3

int AlunoMaiorNotaP1 (alunos aluno[]); 
int AlunoMaiorSomaGeral (alunos aluno[]);
int AlunoMenorSomaGeral (alunos aluno[]);
void situacao(alunos aluno[]);

int main() {
    int i,j;
    alunos aluno[TAM];
    int posAluno, tamVetor;
    float mediaMaiorAluno;
    float mediaMenorAluno;

   for(i=0;i<TAM;i++) {
       do {
            printf("\nDigite a matricula: ");
            scanf("%d", &aluno[i].matricula);
       } while(aluno[i].matricula<0 || aluno[i].matricula > 100000);

        printf("Digite o nome: ");
        scanf("%s", &aluno[i].nome);
        fflush(stdin);
        
        
        for(j=0;j<3;j++){
            do{
                printf("Digite a nota P[%d]: ",j);  
                scanf("%f", &aluno[i].p[j]);
            } while(aluno[i].p[j]<0 || aluno[i].p[j]> 10);
        }
        

        printf("\n-------------------------------\n");
    
    }
    
    tamVetor = sizeof(aluno->p)/sizeof(aluno->p[0]);

    posAluno = AlunoMaiorNotaP1(aluno);
    printf("\nAluno '%s' com maior P1: %.2f.",aluno[posAluno].nome, aluno[posAluno].p[0]);

    posAluno = AlunoMaiorSomaGeral(aluno);
    mediaMaiorAluno = (aluno[posAluno].somaGeral)/tamVetor;
    printf("\nAluno '%s' com maior Media: %.2f.",aluno[posAluno].nome, mediaMaiorAluno);

    posAluno = AlunoMenorSomaGeral(aluno);
    mediaMenorAluno = (aluno[posAluno].somaGeral)/tamVetor;
    printf("\nAluno '%s' com menor Media: %.2f.",aluno[posAluno].nome, mediaMenorAluno);

    situacao(aluno);
    printf("\n\n");

    return 0;
}

int AlunoMaiorNotaP1 (alunos aluno[TAM]) {
    
    int i;
    float maior = aluno[0].p[0];
    int pos=0;
    
    for(i=0;i<TAM;i++) {
        
       if(maior < aluno[i].p[0]){
            maior = aluno[i].p[0];
            pos = i;
        }
        
    }

    return pos;
}

int AlunoMaiorSomaGeral (alunos aluno[TAM]) {
    
    int i,j;
    int pos=0;
    float maiorSoma=0;

    int tamVetorNotas = sizeof(aluno->p)/sizeof(aluno->p[0]);
        

    for(i=0;i<TAM;i++) {
       aluno[i].somaGeral = 0; 
       for(j=0;j<tamVetorNotas;j++) {
            aluno[i].somaGeral = aluno[i].somaGeral + aluno[i].p[j];
       }
    }
    
    for(i=0;i<TAM;i++) {
        if(maiorSoma < aluno[i].somaGeral){
            maiorSoma = aluno[i].somaGeral;
            pos = i;
        }
    }

    return pos;
}

int AlunoMenorSomaGeral (alunos aluno[TAM]) {
    
    int i,j;
    int pos=0;
    float menorSoma= aluno[0].somaGeral;
    int tamVetorNotas = sizeof(aluno->p)/sizeof(aluno->p[0]);

    for(i=0;i<TAM;i++) {
       aluno[i].somaGeral = 0;
       for(j=0;j<tamVetorNotas;j++) {
            aluno[i].somaGeral = aluno[i].somaGeral + aluno[i].p[j];
       }
    }

    for(i=0;i<TAM;i++) {
        if(aluno[i].somaGeral<menorSoma){
            menorSoma = aluno[i].somaGeral;
            pos = i;
        }
    }

    return pos;
}

void situacao(alunos aluno[TAM]){

    int i,j;
    int tamVetorNotas = sizeof(aluno->p)/sizeof(aluno->p[0]);
    float media;

    for(i=0;i<TAM;i++) {
       aluno[i].somaGeral = 0; 
       for(j=0;j<tamVetorNotas;j++) {
            aluno[i].somaGeral = aluno[i].somaGeral + aluno[i].p[j];
       }
        
       media = aluno[i].somaGeral/tamVetorNotas;
       if(media>=6){
           printf("\n\nMatricula %d - Aluno %s - Media: %.2f",aluno[i].matricula, aluno[i].nome, media);
           printf("\n|_Aprovado!");
       } else if(media>=4 || media<6){
           printf("\n\nMatricula %d - Aluno %s - Media: %.2f",aluno[i].matricula, aluno[i].nome, media);
           printf("\n|_Exame!");
       } else {
           printf("\n\nMatricula %d - Aluno %s - Media: %.2f",aluno[i].matricula, aluno[i].nome, media);
           printf("\n|_Reprovado!");
       }
    }
}