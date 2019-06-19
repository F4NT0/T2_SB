#include<stdio.h>
#include<stdlib.h>

//Variáveis Globais
#define max_ascii 256
int tamanho = 0;



//Structs das árvores

/* Struct dos Nodos */
//typedef struct Node {
  //  int valor;
  //  char caractere;
  //  struct Node* pai;
  //  struct Node* esq;
  //  struct Node* dir;
//}Node;

/*  */



//Prototypes
int frequencia(char caractere, )
void inserir(NODO** arv, char val);
void mostrar(NODO* arv);
NODO* pesquisar(NODO* arv, char val);

//Functions



void inserir(NODO** arv, char val){
    if(*arv == NULL){
        NODO* novo;
        novo = malloc(sizeof(NODO));
        novo->valor = val;
        novo->pai = NULL;
        novo->esq = NULL;
        novo->dir = NULL;

        *arv = novo;
    }else {
        if(val < (*arv)->valor){
            inserir(&((*arv)->esq), val);
        }else{
            inserir(&((*arv)->dir),val);
        }
    }
}

NODO* pesquisar(NODO* arv, char val){
    if(arv == NULL) return NULL;

    if( arv->valor == val){
        return arv;
    }else if(arv->valor > val){
        return pesquisar(arv->esq, val);
    }else{
        return pesquisar(arv->dir,val);
    }
}

void mostrar(NODO* arv){
    if(arv == NULL) return;

    mostrar(arv->esq);
    printf("(%c) ",arv->caractere);
    mostrar(arv->dir);
}



int main(){
    //chamada do Nodo
    NODO* raiz = NULL;
    char salvando_char;


    //lendo arquivo texto
    FILE* file = fopen("../Arquivos_Textos/arquivo.txt", "r");

    if(file == NULL){
        printf("Erro! Arquivo não encontrado!\n");
        exit(EXIT_FAILURE);
    }

    //lendo char por char
    char caractere;
    while((caractere = fgetc(file)) != EOF){
       // printf("char: %c\n", caractere);
       salvando_char = caractere;
       inserir(&raiz, &salvando_char);
    }

    mostrar(raiz);
    printf("\n");

    //fechando o arquivo
    fclose(file);
    return 0;
}