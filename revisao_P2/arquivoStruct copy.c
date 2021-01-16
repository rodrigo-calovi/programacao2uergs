#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct meuStruct {
    int x;
    double y;
    char z[10];
};

int	main(){
    //para usar sem conio.h o getch();
    char *c;

    FILE *arquivo;
    struct meuStruct t_Gravar, t_Ler;

    t_Gravar.x = 15;
    t_Gravar.y = 25.75;
    strcpy(t_Gravar.z, "Calovi");
    
    //GRAVACAO
    arquivo = fopen("registroStruct.bin", "wb");
    fwrite(&t_Gravar, sizeof(struct meuStruct), 1, arquivo);
    fclose(arquivo);

    //LEITURA
    arquivo = fopen("registroStruct.bin", "rb");
    fread(&t_Ler, sizeof(struct meuStruct), 1, arquivo);
    fclose(arquivo);

    printf("\nx = %d, y= %.2f, z=%s\n", t_Ler.x, t_Ler.y, t_Ler.z);

    //para uso sem biblioteca conio.h
    printf("\nDigite uma tecla para sair e <ENTER>!");
    scanf("%c",&c);

    return EXIT_SUCCESS; //return 0, precisa stdlib.h
}
