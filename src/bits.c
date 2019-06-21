#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arvore.h"
#include "bits.h"

/*----------------------
    VARIAVEIS GLOBAIS
------------------------*/


/*----------------------- 
    INICIANDO STRUCTS
------------------------*/
typedef struct Nodo Nodo;
typedef struct Bits Bits;


/*----------------------
        FUNCOES
----------------------*/

// PEGAR CADA BIT DO CAMINHO E ADICIONAR EM UM VETOR
void insereBits(Nodo* nodo,Bits bits,char valor){
    if(nodo == NULL){
        return;
    }

    strcat(bits->stringBits,valor);

    // INSERE os valores no Struct
    insereBits(nodo->esq,bits,'0');
    insereBits(nodo->dir,bits,'1');    
}

