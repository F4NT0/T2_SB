
#include<stdio.h>
#include<stdlib.h>

//=================== TESTE DE FREQUENCIA ======================

// VARIAVEIS GLOBAIS
int max_ascii = 256;

//STRUCT DA TUPLA
typedef struct{
    char caractere_tupla;
    int freq;
} Tupla;

//PROTOTIPO
int Verfrequencia(char caractere, Tupla* caracteres, int contador);


//FUNCAO
int Verfrequencia(char character, Tupla* caracteres, int contador){
    int add = 1; //adicionar um valor
    for(int i = 0 ; i < contador ; i++){
        if(caracteres[i].caractere_tupla == character){
            caracteres[i].freq += 1;
            add = 0;
            break;
        }
    }
    if (add){ // se for 1, significa que ainda não existia no vetor
        caracteres[contador].caractere_tupla = character;
        caracteres[contador].freq = 1;
         
    }
    return add; //retorna true(1) ou false(0)
}


int main(){

    /* VARIAVEIS */
    int contador = 0; //contador que vai poder 
    Tupla* caracteres = malloc(sizeof(Tupla) * (max_ascii + 1)); //vai alocar o espaço da memória com os valores do ASCII + 1

    /* LENDO ARQUIVO EXEMPLO */
    FILE* file = fopen("../Arquivos_Textos/arquivo.txt", "r");

    if(file == NULL){
        printf("Erro! Arquivo não encontrado!\n");
        exit(EXIT_FAILURE);
    }

    /* LENDO CHAR POR CHAR */
    char caractere;
    while((caractere = fgetc(file)) != EOF){
        contador = contador + Verfrequencia(caractere,caracteres,contador); //ele vai verificar a frequencia de cada um dos chars
    }
    for(int i = 0 ; i < sizeof(caracteres)-3 ; i++){
        printf("( %c , %d ) \n",caracteres[i].caractere_tupla,caracteres[i].freq);
    }

    fclose(file);
}

//=================================================================