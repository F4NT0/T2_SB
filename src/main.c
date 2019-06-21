#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "frequencia.h"
#include "arvore.h"


/*
 -------------
     MAIN
 -------------
*/
int main(){
    //VARIAVEIS
    char dir[] = "../arquivos/"; //local onde se encontra os arquivos
    char extensao[] = ".txt"; //extensao dos arquivos
    char entrada[100];

 
    // ======================== FREQUENCIA ========================
    
    // ENTRADA DO NOME
    printf("Digite o nome do Arquivo: \n");
    scanf("%[^\n]s",entrada);

    // CONECTANDO TUDO EM UM UNICO VETOR
    strcat(dir,entrada);
    strcat(dir,extensao);

    // CHAMANDO A FUNCAO LENDOARQUIVO
    Tupla* chamandoTupla = lendoArquivo(dir);


    //TESTANDO A FREQUENCIA
    
    printf("== FREQUENCIA ==\n\n");
    for(int i = 0 ; i < sizeof(chamandoTupla) ; i++){
        if(chamandoTupla[i].caractere == '\0'){
            break;
        }
        printf("( %c , %d) \n",chamandoTupla[i].caractere,chamandoTupla[i].freq);
    }

    // ====================== ARVORES ================================
    printf("== ARVORES ==\n\n");
    Nodo** lista = listaNodos(chamandoTupla);
    uniao(lista);
    mostrar(lista[0]);
    


}