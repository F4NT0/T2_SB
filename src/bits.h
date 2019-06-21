#ifndef BITS_H
#define BITS_H

// ARQUIVO COM OS STRUCTS E PROTOTIPOS DA LEITURA DE BITS

/*----------------------------------
    STRUCT DE ARMAZENAMENTO DE BITS
----------------------------------*/

typedef struct Bits{
    char caractere;
    char* stringBits; 
}Bits;

/*----------------
    PROTOTIPOS
-----------------*/

void insereBits(Nodo* nodo,Bits bits,char valor);




#endif