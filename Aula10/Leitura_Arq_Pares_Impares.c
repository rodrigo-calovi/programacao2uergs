/**
 * UERGS - Engenharia de computação
 * Docente: Dra. Margrit Reni Krug
 * 
 * Exercício
 * 
 * Ler 10 valores para um vetor. Guardar
 * no arquivo texto “pares.txt” os valores
 * pares do vetor e, no arquivo
 * “impares.txt” os valores ímpares.
 * 1) Fazer menu para opções /gravar / ler pares / ler impares / sair
 * 2) Não sair qd gravar, somente qd selecionado sair
 *
 * ->PADRÃO C++
 * #include <iostream>
 * using namespace std;
 * 
 * @author Rodrigo Britto Calovi
 * @version 1.0
 * 
**/
 
#include <stdio.h>

/**
 * cabeçalho 
 */
int menu();
void leituraImpares();
void leituraPares();
void dados(int vetor[]);
void gravarArquivo(int vetPar[], int vetImpar[], int qtPar, int qtImpar);
void gravacao(int vet[], int qt, char nomeArquivo[]);

//Define tamanho do vetor a ser lido
#define TAM 10

/**
 * Main
 * @return int - 0 sem erros 
 */
int main(){

    FILE *arquivo;
    int vetor[TAM]={0};
    //TAM = sizeof(vetor)/sizeof(vetor[0])

    int i, op;
    while( (op = menu() ) != 4) {
        switch (op) {
            case 1:
                dados(vetor); //insere os dados
                break;
            case 2:
                leituraImpares(); //lê do arquivo impares Odd
                break;
            case 3:
                leituraPares(); //lê do arquivo os pares Even
                break;
            case 4:
                printf("Voce saiu do sistema!"); // Sai do programa
                break;
            default:
                printf("Digite 1 para inserir dados, 2 para ler impares, 3 para ler pares ou 4 para Sair.");
        }
    }

    return 0;
}

/**
 * Função Menu 
 * @return op (int) 
 */
int menu(){
    int op;
    printf("\n--------------------");
    printf("\n------- MENU -------");
    printf("\n--------------------");
    printf("\n-  1) Writer Vetor -");
    printf("\n-  2)  Read Odd    -");
    printf("\n-  3)  Read Even   -");
    printf("\n-  4)  Exit        -");
    printf("\n--------------------");
    printf("\n\n\rEscolha: ");
    scanf("%d",&op);
    return op;
}


 /**
  * Função para inserção de dados 
  * @param vetor (int) 
  * @return void 
  */
void dados(int vetor[]){

    int i=0;
    int vetPar[TAM]={0}; //define para o mesmo tamanho de vetor caso seja tudo par
    int vetImpar[TAM]={0}; //define para o mesmo tamanho de vetor caso seja tudo impar
    int qtPar=0, qtImpar=0; //qt de numeros pares e impares

    for(i=0;i<TAM;i++){
        printf("Digite [%i%c] valor: ", i+1, 167); //167 caracter char(167) da tabela ascii
        scanf("%d",&vetor[i]);
        fflush(stdin); //limpa buffer teclado

        if(vetor[i]%2==0){ //se par
            vetPar[qtPar]=vetor[i];
            qtPar++;
        } else { //se não, impar
            vetImpar[qtImpar]=vetor[i];
            qtImpar++;
        }
    }
  
    //Grava os registros
    gravarArquivo(vetPar, vetImpar,qtPar, qtImpar);
    gravarArquivo( vetPar, vetImpar,qtPar, qtImpar);
}


/**
 * @param vetPar - vetor par (int[])
 * @param vetImpar - vetor impar (int[])
 * @param qtPar - quantidade pares (int)
 * @param qtImpar - quantidade impares (int)
 * @return void
 */
void gravarArquivo(int vetPar[], int vetImpar[], int qtPar, int qtImpar){
    gravacao(vetPar, qtPar, "pares.txt");
    gravacao(vetImpar, qtImpar, "impares.txt");
}


/**
 * 
 * @param vet - vetor qualquer (int)
 * @param qt - quantidade qualquer (int)
 * @param nomeArquivo - nome para o arquivo (char[])
 * @return void
 */
void gravacao(int vet[], int qt, char nomeArquivo[]) {
    int i = 0;
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "wt");

    if (arquivo == NULL) {
        printf("Arquivo não pode ser aberto para escrita!");
    } else {
        for (i = 0; i < qt; i++) {
            fprintf(arquivo, "%d\r", vet[i]);
        }
        fclose(arquivo);
    }
}


/**
 * Função Leitura Impares
 * @param void
 * @return void
 */
void leituraImpares(void){
    FILE *arquivo;
    int scan[20];
    char temp;
    int i=0, qt;
    arquivo = fopen("impares.txt", "rt");
    if (arquivo == NULL) {
        printf("Impossivel abrir arquivo para leitura...");
    } else {
        printf("\n\nNumeros Impares: ");
        while(!feof(arquivo)) {

            fscanf(arquivo, "%d", &scan[i++]);

            if(feof){
                qt = i-1;
                //break;
            }
        }

    }
    fclose(arquivo);

    for(i=0;i<qt;i++) {
        printf("%d ", scan[i]);
    }

}

/**
 * Função Leitura Pares
 * @param void
 * @return void
 */
void leituraPares(void){
    FILE *arquivo;
    int scan[20];
    char temp;
    int i=0, qt;
    arquivo = fopen("pares.txt", "rt");
    if (arquivo == NULL) {
        printf("Impossivel abrir arquivo para leitura...");
    } else {
        printf("\n\nNumeros Pares: ");
        while(!feof(arquivo)) {
            fscanf(arquivo, "%d", &scan[i++]);
            if(feof){
                qt = i-1;
            }
        }

    }
    fclose(arquivo);

    for(i=0;i<qt;i++) {
        printf("%d ", scan[i]);
    }

}