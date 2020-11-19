#ifdef __unix__
    #include <unistd.h>
    #include <stdlib.h>
#elif defined(_WIN32) || defined(WIN32)

    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>

    #define OS_Windows

#endif



#define TAM 5



int main(int argc, char *argv[]) {

    #ifdef OS_Windows
        /* Codigo Windows */
        system("cls");
    #else
        /* Codigo GNU/Linux */
        system("clear");
    #endif

    return 0;
}
