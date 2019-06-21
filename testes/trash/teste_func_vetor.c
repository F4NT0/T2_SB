#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Criando o caminho para o arquivo
 */
char* nomeArquivo(char* nome){
    // VARIAVEIS
    char restoInfo[] = "../Arquivos_Textos/"; //local onde se encontra os arquivos
    char estensao[] = ".txt"; //extensao dos arquivos
    char saida[sizeof(nome)+sizeof(restoInfo)+sizeof(estensao)]; //novo vetor com o tamanho de tudo

    // CONECTANDO TUDO EM UM UNICO VETOR
    strcat(saida,restoInfo);
    strcat(saida,nome);
    strcat(saida,estensao);

    //PONTEIRO PARA PODER ALOCAR O VETOR
    char *ponteiro;
    ponteiro = (char*) malloc(strlen(saida)+1); //alocando o espaço para o vetor de saida

    //SAIDA
     return ponteiro;
}

int main(){

    char entrada[100];

    // ENTRADA DO NOME
    printf("Digite o nome do Arquivo: ");
    scanf("%[^\n]s",entrada);

    // COPIANDO O ENDEREÇO DA FUNCAO
    char *nome = nomeArquivo(entrada);
    printf("Nome: %s\n", (char*) nome);
}