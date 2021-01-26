#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validaNumero(int pontos_I, int pontos_V , int  pontos_X, int pontos_L, int pontos_C, int pontos_D, int pontos_M );

int main(){

    char *letras;
    int tamanho, i;
    int pontos_I=0, pontos_V=0, pontos_X=0, pontos_L=0, pontos_C=0, pontos_D=0, pontos_M=0;
    int total = 0;

    letras = (char*)malloc(sizeof(char));
    
    do{
        printf("\n\nDigite o numero em Romano ateh 4000 devido a simbologia ex: MMCDVIII => 2408 \n |=> ");
        scanf("%s",letras);
        fflush(stdin);
    
        letras = strupr(letras);
        tamanho =  strlen(letras);
        
        while(tamanho>=0){
        
            switch (letras[i]) {
                case 'I':
                   
                    if(i==0)
                        pontos_I = pontos_I + 1;
                    else if(letras[i+1]!='I' && i!=0)
                        pontos_I = pontos_I + 1;
                    else if(letras[i+1]=='I' && i!=0)
                        pontos_I = pontos_I + 1;
                    break;
                
                case 'V':
                    if(i==0)
                        pontos_V = pontos_V + 5;
                    else if(letras[i+1]!='V' && i!=0)
                        pontos_V = pontos_V + 5;

                    if(letras[i-1]=='I'){
                        pontos_I = -1*pontos_I;
                    }
                    break;
                    
                case 'X':
                    if(i==0)
                        pontos_X = pontos_X + 10;
                    else if(letras[i+1]!='X' && i!=0)
                        pontos_X = pontos_X + 10;
                    else if(letras[i-1]=='X' )
                        pontos_X = pontos_X + 10;

                    else if(letras[i+1]=='X' && i!=0)
                        pontos_X = pontos_X + 10;

                    if(letras[i-1]=='I'){
                        pontos_I = -1*pontos_I;
                    }
                    
                    break;
                
                case 'L':
                    if(i==0)
                        pontos_L = pontos_L + 50;
                    else if(letras[i+1]!='L' && i!=0)
                        pontos_L = pontos_L + 50;
                    else if(letras[i-1]=='L' && i!=0)
                        pontos_L = pontos_L + 50;
                    
                    if(letras[i-1]=='I'){
                        pontos_I = -1*pontos_I;
                    }

                    if(letras[i-1]=='X'){
                        pontos_X = -1*pontos_X;
                    }
                    break;
                
                case 'C':
                    if(i==0)
                        pontos_C = pontos_C + 100;
                    else if(letras[i+1]!='C' && i!=0)
                        pontos_C = pontos_C + 100;
                    else if(letras[i-1]=='C' && i!=0)
                        pontos_C = pontos_C + 100;
                    else if(letras[i+1]=='C' && i!=0)
                        pontos_C = pontos_C + 100;

                    if(letras[i-1]=='I'){
                        pontos_I = -1*pontos_I;
                    }

                    if(letras[i-1]=='X'){
                        pontos_X = -1*pontos_X;
                    }

                    if(letras[i-1]=='L'){
                        pontos_L = -1*pontos_L;
                    }
                    break;

                case 'D':
                    if(i==0)
                        pontos_D = pontos_D + 500;
                    else if(letras[i+1]!='D' && i!=0)
                        pontos_D = pontos_D + 500;
                    else if(letras[i-1]=='D' && i!=0)
                        pontos_D = pontos_D + 500;
                    else if(letras[i+1]=='D' && i!=0)
                        pontos_D = pontos_D + 500;

                    if(letras[i-1]=='I'){
                        pontos_I = -1*pontos_I;
                    }

                    if(letras[i-1]=='X'){
                        pontos_X = -1*pontos_X;
                    }

                    if(letras[i-1]=='L'){
                        pontos_L = -1*pontos_L;
                    }

                    if(letras[i-1]=='C'){
                        pontos_C = -1*pontos_C;
                    }
                    break;

                case 'M':
                     if(i==0)
                        pontos_M = pontos_M + 1000;
                    else if(letras[i+1]!='M' && i!=0)
                        pontos_M = pontos_M + 1000;
                    else if(letras[i-1]=='M' && i!=0)
                        pontos_M = pontos_M + 1000;
                    
                    else if(letras[i+1]=='M' && i!=0)
                        pontos_M = pontos_M + 1000;

                    if(letras[i-1]=='I'){
                        pontos_I = -1*pontos_I;
                    }

                    if(letras[i-1]=='X'){
                        pontos_X = -1*pontos_X;
                    }

                    if(letras[i-1]=='L'){
                        pontos_L = -1*pontos_L;
                    }

                    if(letras[i-1]=='C'){
                        pontos_C = -1*pontos_C;
                    }

                    if(letras[i-1]=='D'){
                        pontos_D = -1*pontos_D;
                    }
                    break;
                    
                default:
                    break;
            }

            tamanho--;
            i++;
        }
    
        total = validaNumero(pontos_I, pontos_V, pontos_X, pontos_L, pontos_C, pontos_D, pontos_M);
        
        if(total!=0)
            printf("\nNumero Romano para Decimal: ** %d ** ",total);
        else
            printf("\n*** Digite um numero em romano valido ateh 4000!  ***\n");

        //RESETA VALORES
        i=0;
        pontos_I=0;
        pontos_V=0;
        pontos_X=0;
        pontos_L=0;
        pontos_C=0;
        pontos_D=0;
        pontos_M=0;

    }while(strcmp(letras,"0"));

    return 0;
}

int validaNumero(int pontos_I, int pontos_V , int  pontos_X, int pontos_L, int pontos_C, int pontos_D, int pontos_M ){
    
    int total = 0;

    if(pontos_I>3)
        return 0;
    if(pontos_V>5)
        return 0;
    if(pontos_X>=100)
        return 0;
    if(pontos_L>50)
        return 0;
    if(pontos_C>=1000)
        return 0;
    if(pontos_D>500)
        return 0;
    if(pontos_M>4000)
        return 0;
    
    return total = pontos_I + pontos_V + pontos_X + pontos_L + pontos_C + pontos_D + pontos_M; 
}
