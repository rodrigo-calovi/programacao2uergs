#include <stdio.h>

void swap(int *a, int *b);

int main(){

    int a = 3;
    int b = 8;
    swap(&a, &b);

    printf("a: %d\nb: %d", a, b);


    return 0;
}

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void per(){

}