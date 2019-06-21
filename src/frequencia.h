#ifndef FREQUENCIA_H
#define FREQUENCIA_H

// ARQUIVO COM OS STRUCTS E PROTOTIPOS DAS TUPLAS

/*-----------------
 * STRUCT DA TUPLA
-----------------*/

typedef struct Tupla{
    char caractere;
    int freq;
}Tupla;

//PROTOTIPOS
Tupla* lendoArquivo(char* arquivo);
int frequencia(char car, Tupla* tup,int contador);

#endif