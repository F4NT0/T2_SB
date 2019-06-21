#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "frequencia.h"

//GLOBAL VARIABLES
int max_ascii_frequencia = 256;

// INICIALIZANDO STRUCTS
typedef struct Tupla Tupla;

// FUNCOES

/*
 -------------
 VERIFICANDO FREQUENCIA
 -------------
*/
int frequencia(char car,Tupla* tup,int contador){
    // VARIAVEIS
    int verificador = 1;

    for(int i = 0 ; i < contador ; i++ ){
        if(tup[i].caractere == car){
            tup[i].freq += 1;
            verificador = 0; //retorna false 
            break;
        }
    }

    if(verificador == 1){ //se n tiver sido iniciado
        tup[contador].caractere = car;
        tup[contador].freq = 1;
    }

    return verificador;
}

/*
 -------------
 LENDO ARQUIVO
 -------------
*/
 Tupla* lendoArquivo(char* arquivo){
     // VARIAVEL
     int contador = 0; //contador para saber se foi todos os valores
     Tupla* tupla = malloc(sizeof(Tupla) * (max_ascii_frequencia + 1)); //alocação de memória

    
    // ABRINDO ARQUIVO
    FILE* file = fopen(arquivo, "r");

    if(file == NULL){
        printf("Erro! Arquivo não encontrado!\n");
        exit(EXIT_FAILURE);
    }

    // LENDO CHAR POR CHAR
    char caractere;
    while((caractere = fgetc(file)) != EOF){
        contador = contador + frequencia(caractere,tupla,contador);
    }

    fclose(file);

    return tupla;
 }

