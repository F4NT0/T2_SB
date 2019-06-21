#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//GLOBAL VARIABLES
int max_ascii = 256;
int tamanhoArvore = 0;

//STRUCTS

/*
------------ 
STRUCT TUPLA
------------
*/

 typedef struct Tupla{
    char caractere;
    int freq;
 }Tupla;

/*
 -------------
  CRIAR NODOS
 -------------
*/

typedef struct Nodo{
    char caractere;
    int frequencia;
    struct Nodo* esq;
    struct Nodo* dir;
    struct Nodo* pai;
}Nodo;

// INICIALIZANDO STRUCTS
typedef struct Tupla Tupla;
typedef struct Nodo Nodo;

//PROTOTYPES

//------- Lendo e tirando frequencia ------------
Tupla* lendoArquivo(char* arquivo);
int frequencia(char car,Tupla* tup,int contador);

//-------- Criando as arvores --------------------
Nodo* unicoNodo(Tupla tup);
Nodo** listaNodos(Tupla* tup);
void ordenarNodos(Nodo** nodos);
void listarNodos(Nodo** entrada);

//FUNCTIONS

/*
 -------------
 VERIFICANDO FREQUENCIA
 -------------
*/
int frequencia(char car,Tupla* tup,int contador){
    // VARIAVEIS
    int verificador = 1;

    for(int i = 0 ; i < contador ; i++ ){
        if(tup[i].caractere == car){
            tup[i].freq += 1;
            verificador = 0; //retorna false 
            break;
        }
    }

    if(verificador == 1){ //se n tiver sido iniciado
        tup[contador].caractere = car;
        tup[contador].freq = 1;
    }

    return verificador;
}

/*
 -------------
 LENDO ARQUIVO
 -------------
*/
 Tupla* lendoArquivo(char* arquivo){
     // VARIAVEL
     int contador = 0; //contador para saber se foi todos os valores
     Tupla* tupla = malloc(sizeof(Tupla) * (max_ascii + 1)); //alocação de memória

    
    // ABRINDO ARQUIVO
    FILE* file = fopen(arquivo, "r");

    if(file == NULL){
        printf("Erro! Arquivo não encontrado!\n");
        exit(EXIT_FAILURE);
    }

    // LENDO CHAR POR CHAR
    char caractere;
    while((caractere = fgetc(file)) != EOF){
        contador = contador + frequencia(caractere,tupla,contador);
    }

    fclose(file);

    return tupla;
 }

/*
 --------------------------
 CRIANDO ARVORES DE UM NODO
 --------------------------
*/ 
Nodo* unicoNodo(Tupla tup){
    Nodo* novo = malloc(sizeof(Nodo*)); //alocando memoria para a arvore

    // CRIANDO A ARVORE
    novo->caractere = tup.caractere;
    novo->frequencia = tup.freq;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;

    return novo;
}

/*
 --------------------------
 LISTA DE NODOS UNICOS
 --------------------------
*/ 
Nodo** listaNodos(Tupla* tup){
    Nodo** lista = malloc(sizeof(Nodo*) * (tamanhoArvore + 1)); //alocando memoria para a lista de Nodos
    for(int i = 0 ; i < tamanhoArvore ; i++){
        lista[i] = unicoNodo(tup[i]);
    }

    return lista;
}

/*
 --------------------------
 COLOCAR OS NODOS EM ORDEM
 --------------------------
*/
void ordenarNodos(Nodo** nodos){
    Nodo* auxOrgan = malloc(sizeof(Nodo));

    // Construindo Nodo auxiliar
    auxOrgan->esq = NULL;
    auxOrgan->dir = NULL;
    auxOrgan->frequencia = 0;
    auxOrgan->caractere = '0';

    for(int i = 0 ; i < tamanhoArvore ; i++){
        for(int j = 0 ; j < tamanhoArvore-1 ; i++){
            if(nodos[j]->frequencia > nodos[j+1]->frequencia){
                auxOrgan = nodos[j];
                nodos[j] = nodos[j+1];
                nodos[j+1] = auxOrgan;
            }
        }
    }
}

/*
 --------------------------
 LISTAR A LISTA DE NODOS
 --------------------------
*/
void listarNodos(Nodo** entrada){
    Nodo** aux = malloc(sizeof(Nodo**));
    for(int i = 0 ; i < sizeof(aux) ; i++){
        printf
    }
}




/*
 -------------
     MAIN
 -------------
*/
int main(){
    //VARIAVEIS
    char dir[] = "../Arquivos_Textos/"; //local onde se encontra os arquivos
    char extensao[] = ".txt"; //extensao dos arquivos
    char entrada[100];

    // ENTRADA DO NOME
    printf("Digite o nome do Arquivo: \n");
    scanf("%[^\n]s",entrada);

    // CONECTANDO TUDO EM UM UNICO VETOR
    strcat(dir,entrada);
    strcat(dir,extensao);

    // CHAMANDO A FUNCAO LENDOARQUIVO
    Tupla* chamandoTupla = lendoArquivo(dir);


}