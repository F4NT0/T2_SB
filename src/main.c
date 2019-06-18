#include<stdio.h>
#include<stdlib.h>

int main(){
    //lendo arquivo texto
    FILE* file = fopen("../Arquivos_Textos/arquivo.txt", "r");

    if(file == NULL){
        printf("Erro! Arquivo não encontrado!\n");
        exit(EXIT_FAILURE);
    }

    //lendo char por char
    char caractere;
    while((caractere = fgetc(file)) != EOF){
        printf("char: %c\n", caractere);
    }

    //fechando o arquivo
    fclose(file);
    return 0;
}