/**
 * 4)Elabore um programa que leia um vetor com os dados de 5 carros: marca (máximo
 * 15 letras), ano e preço. 
 * -Leia um valor e mostre as informações de todos os carros com preço menor que o
 * valor lido.
 * - Repita este processo até que seja lido um valor 0 (Zero).
 *
 * @author Rodrigo Britto Calovi (rodrigo-calovi@uergs.edu.br)
 * @date 2020-12-02
 * 
 * UERGS - prof. Dra. Magrit Krug
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define TAM 5


typedef struct {
    char marca[15];
    int ano;
    float preco;
} Tcarro;

typedef enum condicao_booleana {
  FALSE = 0,
  TRUE = 1
}bool;

int menu();

int main() {
    
    Tcarro t_carro[TAM];

    int op;
    int i;
    bool veiculosCadastrado = FALSE;
    

    do{
        op = menu();
        float valor;
       
        system("cls");

        switch (op) {
            case 1:
                for(i=0;i<TAM;i++){
                    do{
                        printf("Digite a marca do carro [%d]: ",i+1);
                        scanf("%s",&t_carro[i].marca);
                        fflush(stdin);
                    }while(strlen(t_carro[i].marca)<2);
                    
                    do{
                        printf("Digite o ano do carro [%d]: ",i+1);
                        scanf("%d",&t_carro[i].ano);
                    }while(t_carro[i].ano<0 || t_carro[i].ano>3000);

                    do{
                        printf("Digite o valor do carro [%d]: ",i+1);
                        scanf("%f",&t_carro[i].preco);
                        printf("\n");
                    }while(t_carro[i].preco<0);
                } 
                veiculosCadastrado = TRUE;
                break;

            case 2:
                if(veiculosCadastrado){
                    do{
                        printf("\nDigite um valor: ");
                        scanf("%f",&valor);
                    }while(valor<0);
                    
                    printf("\nLocalizado...");
                    

                    for(i=0;i<TAM;i++){
                        if((t_carro[i].preco < valor) && (t_carro[i].preco >= 0)){
                            printf("\n-------------------------");
                            printf("\nMarca: %s",t_carro[i].marca);
                            printf("\nAno: %d",t_carro[i].ano);
                            printf("\nPreco: %.2f",t_carro[i].preco);
                        
                        } 
                    }
                    printf("\n-------------------------");
                    
                } 
            default:
                break;
        }

    }while(op!=0);

    return 0;
}

int menu(){
    int op;
    printf("\n--------------MENU-------------\n");
    printf("\n   1 - Cadastro veiculos       ");
    printf("\n   2 - Busca por valores ate...");
    printf("\n   0 - para sair!              ");
    printf("\n\n-------------------------------\n");
    scanf("%d", &op);
    return op;
}