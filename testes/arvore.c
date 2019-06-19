#include<stdio.h>
#include<stdlib.h>

//===================== CRIANDO ARVORE BINARIA BÁSICA ============================

//STRUCTS

typedef struct Node{
    int valor;
    struct Node* pai;
    struct Node* esq;
    struct Node* dir;
}Node;

//CRIACAO DE UM STRUCT
typedef struct Node NODO;

//PROTOTIPOS

void inserir(NODO** arv, int val);  // SERVE PARA INSERIR UM VALOR NA ÁRVORE
void mostrar(NODO* arv);           //  SERVE PARA MOSTRAR OS VALORES DA ÁRVORE   
NODO* pesquisar(NODO* arv,int val); // SERVE PARA PESQUISAR UM VALOR DENTRO DA ÁRVORE

//FUNCOES
void inserir(NODO** arv, int val){
    if(*arv == NULL){
        NODO* novo;
        novo = malloc(sizeof(NODO));
        novo->valor = val;
        novo->pai = NULL;
        novo->esq = NULL;
        novo->dir = NULL;

        *arv = novo;
    }else{
        if(val < (*arv)->valor){
            inserir(&((*arv)->esq),val);
        }else{
            inserir(&((*arv)->dir),val);
        }
    }
}

NODO* pesquisar(NODO* arv,int val){
    if(arv == NULL){
        return NULL;
    }
    if(arv->valor == val){
        return arv;
    }
    else if(arv -> valor > val){
        return pesquisar(arv->esq, val);
    }else{
        return pesquisar(arv->dir, val);
    }
}

void mostrar(NODO* arv){
    if(arv == NULL){
        return;
    }
    mostrar(arv->esq);
    printf("%d\n",arv->valor);
    mostrar(arv->dir);
}


//MAIN
int main(){
    NODO* raiz = NULL;

    inserir(&raiz, 40);
    inserir(&raiz, 20);
    inserir(&raiz, 50);
    inserir(&raiz, 45);
    inserir(&raiz, 70);
    inserir(&raiz, 2);
    inserir(&raiz, 90);
    inserir(&raiz, 82);
    printf("== VALORES NA ÁRVORE ==\n");
    mostrar(raiz);
    printf("=======================\n");
    printf("\n");

    NODO* aux = pesquisar(raiz,90);
    if(aux != NULL){
        printf("90 pertence a arvore\n");
    }
    aux = pesquisar(raiz,77);
    if(aux == NULL){
        printf("77 nao pertence a arvore\n");
    }
}



//================================================================================
