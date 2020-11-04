/**
 *
 **/

#include <stdio.h>

int main(){
    int b,a;

    int *pa, *pb;
    pa = &a;
    pb = &b;

    printf("\nEndereco a: %p",pa);
    printf("\nEndereco b: %p",pb);


    if(pa>pb){
        printf("\nEndereco a eh maior!");
    } else {
        printf("\nEndereco b eh maior!");
    }


    return 0;
}