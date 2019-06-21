#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "frequencia.h"
#include "arvore.h"

/*---------------------
    VARIAVEIS GLOBAIS
 ---------------------*/
int tamanhoNodos = 0;
int max_ascii_arvore = 256;


/*--------------------
    INICIANDO STRUCT
 --------------------*/
typedef struct Nodo Nodo;
typedef struct Tupla Tupla;

/*-------------------
        FUNCOES
 -------------------*/

// FUNCAO PARA CONSTRUIR NODOS UNICOS (AUXILIAR A LISTA DE NODOS)
Nodo* nodoUnico(Tupla tup){
    Nodo* novo;
    novo = malloc(sizeof(Nodo));
    novo->caractere = tup.caractere;
    novo->frequencia = tup.freq;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

// MOSTRAR UM NODO ESPECIFICO
void mostrar(Nodo* nodo){
    if(nodo == NULL){
        return;
    }

    mostrar(nodo->esq);
    printf("( %c ) | ",nodo->caractere);
    mostrar(nodo->dir);
}

// DEFININDO O TAMANHO DA ARVORE (TAMANHO DA ASCII)
void  definindoTamanho(Tupla* tup){
    for(int i = 0 ; i < max_ascii_arvore ; i++){
        if(tup[i].caractere == '\0'){
            break;
        }
        tamanhoNodos += 1;
    }
}

// CRIANDO A LISTA DE NODOS
Nodo** listaNodos(Tupla* tup){
    definindoTamanho(tup);
    Nodo** lista = malloc(sizeof(Nodo*) * (tamanhoNodos + 1));
    for(int i = 0 ; i < tamanhoNodos ; i++){
        lista[i] = nodoUnico(tup[i]);
    }
    // free(tup);
    return lista;
}

// ORDENANDO A LISTA DE NODOS (AUXILIAR A FUNCAO UNIAO)
void ordenar(Nodo** lista){
    //Pegar um caractere auxiliar
    char aux = 'v';
    //Pegar uma frequencia auxiliar
    int freqAux = 0;


    for(int i = 0 ; i < tamanhoNodos ; i++){
        for(int j = 0 ; j < tamanhoNodos - i - 1 ; j++){
            if(lista[j]->frequencia > lista[j+1]->frequencia){
                aux = lista[j]->caractere;
                freqAux = lista[j]->frequencia;
                lista[j]->caractere = lista[j+1]->caractere;
                lista[j]->frequencia = lista[j+1]->frequencia;
                lista[j+1]->caractere = aux;
                lista[j+1]->frequencia= freqAux;
            }
        }
    }
}


// DELETANDO UM NODO ESPECIFICO
void deletarNodo(Nodo** lista, int pos){
    for(int i = pos ; i < tamanhoNodos ; i++){
        lista[i] = lista[i+1];
    }
}


// DETERMINANDO O PAI DOS DOIS MENORES NODOS
Nodo* determinandoPai(Nodo* primeiro, Nodo* segundo){
    Nodo* pai = malloc(sizeof(Nodo*));

    pai->frequencia = (primeiro->frequencia + segundo->frequencia);
    char valor = pai->frequencia+'0';
    pai->caractere = valor;
    pai->esq = primeiro;
    pai->dir = segundo;

    return pai;
}

// UNINDO TODOS OS NODOS EM UMA UNICA ARVORE
void uniao(Nodo** lista){
    while(tamanhoNodos > 1){
        ordenar(lista);
        Nodo* primeiro = lista[0];
        Nodo* segundo = lista[1];
        Nodo* pai = determinandoPai(primeiro,segundo);
        deletarNodo(lista,0);
        lista[0] = pai;
        tamanhoNodos -= 1;
    }
}




