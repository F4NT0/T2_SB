#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "frequencia.h"
#include "arvore.h"

/*--------------------
    VARIAVEIS GLOBAIS
 ---------------------*/
int tamanhoNodos = 0;
int max_ascii_arvore = 256;


/*-------------------
    INICIANDO STRUCT
 -------------------*/
typedef struct Nodo Nodo;
typedef struct Tupla Tupla;

/*------------------
        FUNCOES
 -------------------*/

//Funcao para poder criar os nodos unicos
Nodo* nodoUnico(Tupla tup){
    Nodo* novo;
    novo = malloc(sizeof(Nodo));
    novo->caractere = tup.caractere;
    novo->frequencia = tup.freq;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;

    return novo;
}

//Criando lista com os Nodos unicos
Nodo** listaNodos(Tupla* tup){
    Nodo** lista = malloc(sizeof(Nodo*) * (tamanhoNodos + 1));
    for(int i = 0 ; i < tamanhoNodos ; i++){
        lista[i] = nodoUnico(tup[i]);
    }
    return lista;
}

//Definindo o tamanho da arvore
Nodo** definindoTamanho(Tupla* tup){
    for(int i = 0 ; i < max_ascii_arvore ; i++){
        tamanhoNodos += 1;
    }
    Nodo** lista = malloc(sizeof(Nodo*) * (tamanhoNodos + 1));
    lista = listaNodos(tup);
    return lista;
}

//Deletando o Nodo
void deletarNodo(Nodo** lista, int pos){
    for(int i = 0 ; i < tamanhoNodos ; i++){
        lista[i] = lista[i+1];
    }
}

//Ordenando a lista com os Nodos
void ordenar(Nodo** lista){
    //Criando um Nodo auxiliar para salvar um Nodo
    Nodo* auxiliar = malloc(sizeof(Nodo));
    auxiliar->esq = NULL;
    auxiliar->dir = NULL;
    auxiliar->frequencia = '0';

    for(int i = 0 ; i < tamanhoNodos ; i++){
        for(int j = 0 ; i < tamanhoNodos - 1 ; j++){
            if(lista[j]->frequencia > lista[j+1]->frequencia){
                auxiliar = lista[j];
                lista[j] = lista[j+1];
                lista[j + 1] = auxiliar;
            }
        }
    }
}


//Determinando o pai da arvore(soma dos dois menores)
Nodo* determinandoPai(Nodo* primeiro, Nodo* segundo){
    Nodo* pai = malloc(sizeof(Nodo*));

    pai->frequencia = (primeiro->frequencia + segundo->frequencia);
    char caractere = pai->frequencia+'0';
    pai->caractere = caractere;
    pai->esq = primeiro;
    pai->dir = segundo;

    return pai;
}

//Agora se junta todos os Nodos
void uniao(Nodo** lista){
    Nodo* primeiro = malloc(sizeof(Nodo));
    Nodo* segundo = malloc(sizeof(Nodo));
    while(tamanhoNodos > 1){
        ordenar(lista);
        primeiro = lista[0];
        segundo = lista[1];
        for(int i = 0 ; i < tamanhoNodos ; i++){
            printf("( %c , %d)\n", lista[i]->caractere,lista[i]->frequencia);    
        }
        Nodo* nova_arvore = malloc(sizeof(Nodo));
        nova_arvore = determinandoPai(primeiro,segundo);
        //TODO: definir para onde vai os valores das arvores
    }
}




