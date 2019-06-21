#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
typedef struct Tupla tupla;


//PROTÓTIPOS
Tupla* lendoArquivo(char* nomeArquivo);
NODO* nodoUnico(Tupla* tupla); //serve para criar ABP de um unico Nodo
void mostrar(NODO* arvore);


//FUNCOES

/*
 * Funcao que vai ler o arquivo desejado e cria as tuplas
 *
 */
Tupla* lendoArquivo(char* nomeArquivo){
    //variaveis
    int contador = 0; //vai controlar a saida da funcao verFrequencia
    Tupla* caracteres = malloc(sizeof(Tupla) * (max_ascii + 1)); //vai alocar o espaço da memória com os valores do ASCII + 1
    char nome[]


    //abrindo o arquivo
    FILE* file = fopen("../Arquivos_Textos/arquivo.txt", "r");
    if(file == NULL){
        printf("Erro! Arquivo não encontrado!\n");
        exit(EXIT_FAILURE);
    }

    //lendo char por char
    char caractere;
    while((caractere = fgetc(file)) != EOF){
        contador = contador + Verfrequencia(caractere,caracteres,contador);
    }

    fclose(file);

    return caracteres;
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
    // char nome[];
    // printf("Digite o nome do arquivo: ");
    // scanf(" %[^\n]s", nome);
    // printf("%s", nome); 

}









//==============================================================================================
