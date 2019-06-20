#include<stdio.h>
#include<stdlib.h>

//====================== TESTE DE CONSTRUÇÃO DE ÁRVORES UNICAS COM TUPLA =======================

//VARIAVEIS GLOBAIS

int max_ascii = 256;

//STRUCTS

typedef struct Nodo{ //Binary Tree Struct
    int valor; //frequencia da letra
    char caractere; //caractere especifico
    struct Node* pai; //Nodo do pai que vem antes
    struct Node* esq; //Nodo do Filho da Esquerda
    struct Node* dir; //Nodo do Filho da Direita
}Nodo;

typedef struct Tupla{//Tuple Struct
    char letra;
    int freq;
}Tupla;

//INICIALIZAÇÃO DO STRUCT

typedef struct Nodo NODO;


//PROTÓTIPOS

void inserir(NODO* arvore, Tupla* tupla);
NODO* nodoUnico(Tupla* tupla); //serve para criar ABP de um unico Nodo
void mostrar(NODO* arvore);


//FUNCOES

void inserir(NODO* arvore, Tupla* tupla){
    if(*arvore == NULL){
        
    }
}

/*
 * nodoUnico serve para construir as arvores binarias com um unico nodo
 *
 *
*/
NODO* nodoUnico(Tupla* tupla){
    NODO* auxiliar = malloc(sizeof(NODO*));//alocado um espaço de memória especial para a arvore
    
    //Informacoes dentro da arvore
    auxiliar->valor=tupla.freq;
    auxiliar->caractere=tupla.letra;
    auxiliar->pai=NULL;
    auxiliar->esq=NULL; 
    auxiliar->dir=NULL;

    return auxiliar;
}



//MAIN
int main(){

}









//==============================================================================================
