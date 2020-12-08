/**
 * UERGS - Engenharia de computação
 * Desenvolvido por: Rodrigo Britto Calovi
 */


#ifdef __unix__
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>

#elif defined(_WIN32) || defined(WIN32)
    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>

#define OS_Windows

#endif


int main(void) {

#ifdef OS_Windows
    system("timeout 5");
    printf("\n");

#else
    printf("\nAguarde o tempo de 5s: ");
    int i = 1;
    while (i <= 5){
        printf("\r\t\t\t%ds",i++);
        system("sleep 1s");
        fflush(stdout);
    }
    printf("\n");
#endif

    return 0;
}