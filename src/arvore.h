#ifndef ARVORE_H
#define ARVORE_H

/*-----------------
  STRUCT DO NODO
-----------------*/

typedef struct Nodo{
    char caractere;
    int frequencia;
    struct Nodo* esq;
    struct Nodo* dir;
    struct Nodo* pai; 
}Nodo;



/*-------------
    PROTOTIPOS
 -------------*/

 Nodo* nodoUnico(Tupla tup);
 Nodo** listaNodos(Tupla* tup);
 Nodo** definindoTamanho(Tupla* tup);
 void ordenar(Nodo** lista);
 Nodo* determinandoPai(Nodo* primeiro, Nodo* segundo);
 void uniao(Nodo** lista);




#endif