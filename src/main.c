#include<stdio.h>
#include<stdlib.h>

//GLOBAL VARIABLES
#define max_ascii 256
int tamanho = 0;

//STRUCTS

//PROTOTYPES
char[] charArray(); // CRIAÇÃO DE UM VETOR COM OS VALORES INTERNOS DO ARQUIVO


//FUNCTIONS
char[] charArray(){
    /*  VARIAVEIS */
    int cont_tamanho = 0; //CONTADOR DO TAMANHO DA STRING
    int contador_vetor = 0; //CONTADOR DO VETOR


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
       vetor[contador_vetor] = caractere;
       contador_vetor = contador_vetor+1;
    }

    return vetor; //SAIDA DO VETOR
}

int main(){
    
}