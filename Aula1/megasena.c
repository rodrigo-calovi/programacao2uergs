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
#include <locale.h>

int main(void){

    setlocale(LC_ALL,"Portuguese");

    int gabarito[6];
    int aposta[10];
    int i,j,valor;
    int pontuacao=0;
    
    for(i=0; i< 6; i++) {
        do{
            printf("Digite o valor para o gabarito: ");
            scanf("%d",&valor);
            if(valor<0 || valor >60){
                printf("\nDigite valor entre 0 e 60!\n\n");
            }
        } while(valor<0 || valor>60);    
        gabarito[i]=valor;
        
        for(j=0;j<i;j++){
            while(gabarito[j]==valor){
                do{
                    printf("Digite outro valor para o gabarito: ");
                    scanf("%d",&valor);
                } while(valor<0 || valor>60); 
                gabarito[i]=valor;
                j=0;
            }
        }
    }

    printf("\n-----------\n");
    for(i=0; i< 10; i++) {
        do{
            printf("Digite os 10 valores da aposta: ");
            scanf("%d",&valor);      
            if(valor<0 || valor >60){
                printf("\nDigite valor entre 0 e 60!\n\n");
            }      
        } while(valor<0 || valor>60);        
        aposta[i]=valor;

        for(j=0;j<i;j++){
            while(aposta[j]==valor){
                do{
                    printf("Digite outro valor para a aposta: ");
                    scanf("%d",&valor);
                } while(valor<0 || valor>60); 
                aposta[i]=valor;
                j=0;
            }
        }
    }

    printf("\nVerificando resultados\n");
    
    for(i=0; i<6; i++){
        for (j=0;j<10;j++){
            if(aposta[j]==gabarito[i]){
                printf("%d ", aposta[j]);
                pontuacao++;
            }
        }
    }

    switch (pontuacao){
        case 4:
            printf("Quadra");
            break;
        case 5:
            printf("Quina");
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            printf("Sena");
            break;
        default:
            printf("\n\nTente na proxima!");
            break;
        }
        printf("\n\nAcertos: %d", pontuacao);

    printf("\nDigite uma tecla para continuar!");
    getch();
    return 0;

}