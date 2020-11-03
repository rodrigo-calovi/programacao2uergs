#include <stdio.h>
#include <stdlib.h>

float potenciaRec(int x, int y);

int main() {
    int x, y;
    printf("Digite a (base)^(expoente): ");
    scanf("%d^%d",&x,&y);

    printf("%.6f",potenciaRec(x,y));
    return 0;
}

float potenciaRec(int x, int y){
    if(y==0){
        return 1;
    } else if(y==1){
        return x;
    } else if(y>1) {    
        return x*potenciaRec(x , y-1);  
    } else if(y<0){
        y=-1.0*y;                
        return 1/(x*potenciaRec(x , y-1));  
    }
}