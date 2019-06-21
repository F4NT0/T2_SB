#include<stdio.h>
#include<stdlib.h>

//==================== CRIANDO VETOR DE UMA ENTRADA DE TEXTO =================================

int main(){

    /*  VARIAVEIS */
    tupla tup; //chamando struct da tupla
    int cont_tupla = 1; //contador da tupla, para a frequencia
    int cont_tamanho = 0; //contador para saber o numero de chars
    int contador_vetor = 0; //contador do vetor


    /* LENDO ARQUIVO TEXTO */
    FILE* file = fopen("../Arquivos_Textos/arquivo.txt", "r");

    if(file == NULL){
        printf("Erro! Arquivo não encontrado!\n");
        exit(EXIT_FAILURE);
    }


    /* NUMERO DE CHARS NO ARQUIVO */
    char caractere;
    while((caractere = fgetc(file)) != EOF){
        cont_tamanho = cont_tamanho+1;
    }

    rewind(file); //retorna ao inicio do arquivo

    /* TESTE DO TAMANHO DO VETOR */
    printf("Tamanho do String : %d\n", cont_tamanho);

    /* VETOR COM OS CHARS DO ARQUIVO */

    char vetor[cont_tamanho];

    while((caractere = fgetc(file)) != EOF){
       // printf("char: %c\n", caractere);
       vetor[contador_vetor] = caractere;
       contador_vetor = contador_vetor+1;
    }

    //fechando o arquivo
    fclose(file);
    return 0;
}
//==================================================================================================