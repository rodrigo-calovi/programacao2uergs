/*    Ler um vetor A de 6 elementos contendo o
**    gabarito da Mega Sena. A seguir, ler um vetor B
**    de 10 elementos contendo uma aposta. Escrever
**    quantos pontos fez o apostador, e se ele fez a
**    sena (6 acertos), a quina (5 acertos) ou a quadra
**    (4 acertos)
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void){

    int gabarito[6];
    int aposta[10];
    int i,j,valor;
    int pontuacao=0;

    for(i=0; i< 6; i++) {
        do{
            printf("Digite o valor para o gabarito: ");
            scanf("%d",&valor);
        } while(valor<0 || valor>60);        
        gabarito[i]=valor;
    }
    printf("\n-----------\n");
    for(i=0; i< 10; i++) {
        do{
            printf("Digite os 10 valores da aposta: ");
            scanf("%d",&valor);
        } while(valor<0 || valor>60);        
        aposta[i]=valor;
    }

    printf("\nVerificando resultados\n");
    
    for(i=0; i<6; i++){
        for (j=0;j<10;j++){
            if(aposta[j]==gabarito[i]){
                printf("valor igual %d ", aposta[i]);
                pontuacao++;
            }
        }
    }

    printf("\n\nPontuacao: ", pontuacao);

    return 0;

}