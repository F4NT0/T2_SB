#include<stdio.h>
#include<stdlib.h>

//teste de criação de uma tupla, para depois criar uma modularização

//Struct de uma Tupla
typedef struct{
    char caractere;
    int frequencia;
}tupla;

//prototipo
void criandoTupla(char *vetor, char caractere);


//Funcoes

void criandoTupla(char *vetor, char caractere){
    /* VARIAVEIS */
    int contador = 1; //conta quantas vezes o char aparece no vetor

    for(int i = 0 ; i < sizeof(vetor) ; i++){
        if(vetor[i] == caractere){
            contador = contador+1;
        }
    }
    printf("Caractere : %c\n", caractere);
    printf("Frequencia: %d\n", contador);
}

void contandoFrequencia()


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

    /* VETOR COM OS CHARS DO ARQUIVO */

    char vetor[cont_tamanho];

    while((caractere = fgetc(file)) != EOF){
       // printf("char: %c\n", caractere);
       vetor[contador_vetor] = caractere;
       contador_vetor = contador_vetor+1;
    }

    /* VETOR COM SOMENTE OS CHARS DIFERENTES */

    //testando a função no vetor
    criandoTupla(vetor,vetor[5]);

    /* COLOCANDO NAS TUPLAS A FREQUENCIA E CHAR */
    

    



    //fechando o arquivo
    fclose(file);
    return 0;
}