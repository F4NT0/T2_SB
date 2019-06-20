#include<stdio.h>
#include<stdlib.h>

//====================== TESTE DE CONSTRUÇÃO DE ÁRVORES UNICAS COM TUPLA =======================

//VARIAVEIS GLOBAIS

int max_ascii = 256;

//STRUCTS

typedef struct Nodo{ //Binary Tree Struct
    Tupla* valor;
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

void inserir(NODO* arvore, Tupla* valor);
NODO* nodoUnico(Tupla* valor); //serve para criar ABP de um unico Nodo
void mostrar(NODO* arvore);


//FUNCOES
/**
 * A funcao inserir vai receber um Nodo da arvore e uma Tupla como valor
 * se o Nodo for vazio, ele vai inicializar o Nodo com o valor de entrada
 * se o Nodo existir, ele vai verificar: 
 *    Se o valor de entrada for menor que o valor no sistema, vai para a esquerda
 *    se o valor de entrada for maior que o valor no sistema, vai para a direita 
 **/
void inserir(NODO* arvore, Tupla* valor){
    if(*arvore == NULL){
        
    }
}



//MAIN
int main(){

}









//==============================================================================================
