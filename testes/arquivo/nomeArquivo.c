#include<stdio.h>
#include<string.h>

//==================== TESTE DE NOME DE ARQUIVO =================

int main(){
    char nomeArquivo[100];
    char restoInfo[] = "../Arquivos_Textos/";
    char estensao[] = ".txt";
    printf("Digite um nome: \n");
    scanf("%[^\n]s", nomeArquivo);
    strcat(restoInfo,nomeArquivo);
    printf("Concatenado o nome do arquivo com o caminho: %s\n\n", restoInfo);
    strcat(restoInfo,estensao);
    printf("Concatenado a extensao no fim do arquivo: %s\n\n", restoInfo);
    printf("Nome Arquivo: %s\n", restoInfo);
    
}
//==================================================================