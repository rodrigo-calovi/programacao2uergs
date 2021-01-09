//atof( ) function converts string to float
//atoi( ) function converts string to int
//atol( ) function converts string to lon
//ltoa( ) function converts long to stringg
//itoa( ) function converts int to string
//char *  itoa ( int value, char * str, int base );

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(){

    //char A[2] = "1";
    //char B[2] = "5";
    
    int A ='A';
    int B = 'B';
    char buffer[5];
    
    //result = atoi(A) + atoi(B);
    itoa(A,buffer,2);
    printf("Binario: %s\n", buffer);

    itoa(A,buffer,10);
    printf("Decimal: %s\n", buffer);

    itoa(A,buffer,16);
    printf("Hexadecimal: 0x%s", buffer);

    getch();

    return 0;
}