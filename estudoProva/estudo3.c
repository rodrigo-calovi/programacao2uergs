#include <stdio.h>
#include <stdlib.h>

void converte_Hora(int total_segundos, int *hora, int *min, int *seg);

int main() {

    int total_segundos;
    int hora, min, seg;

    do {
        printf("Digite o tempo em segundos: ");
        scanf("%d",&total_segundos);
        converte_Hora(total_segundos, &hora, &min, &seg);
    }
    while(total_segundos < 0 || total_segundos > 86399);
    printf("%02d:%02d:%02d",hora,min,seg);

    return 0;
}

void converte_Hora(int total_segundos, int *hora, int *min, int *seg){
    *hora = (total_segundos/60)/60;
    *min = (total_segundos-(*hora)*60*60)/60;
    *seg = total_segundos-(*hora)*60*60-(*min)*60;
}