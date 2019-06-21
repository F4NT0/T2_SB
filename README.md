![](https://img.shields.io/github/languages/code-size/F4NT0/T2_SB.svg?style=plastic) 
![](https://img.shields.io/github/repo-size/F4NT0/T2_SB.svg?style=plastic)

# Repositório de Trabalho 2 de Software Básico

**COMO FUNCIONA ESSE REPOSITÓRIO**

* Arquivo [`start.sh`]() : este arquivo serve para poder rodar o programa

* Para poder executar o programa no **BASH** [`start.sh`]():
* Para poder executar o programa no **LINUX** [`start_linux.sh`]():

```shell
chmod +x start.sh
chmod +x start_linux.sh
```

* Para poder rodar os arquivos em Shell Script

```shell
./start.sh
./start_linux.sh
```

## Diretórios

Nome do Diretório|Para que serve|
|---|---|
arquivos| Este diretório serve para guardar os arquivos textos para usar
compilando| Este diretório serve para compilar o programa, rodando o programa [`start.sh`]() 
src| Este diretório é onde estão os arquivos em C
compilados| Este diretório é onde ficam os arquivos compilados após o **gcc**
Info_Trabalho| Este diretório é onde fica o arquivo pdf do trabalho

## Arquivos

Nome do Arquivo|Para que serve|
|---|---|
`src/arvore.h` | Protótipos das Funções das Árvores
`src/arvore.c` | Funções sobre as Árvores
`src/frequencia.h` | Protótipos das Funções de Frequência
`src/frequencia.c` | Funções sobre a Frequência
`src/main.c` | Arquivo para compilar(**main**)
`compilando/start_linux.sh` | Para compilar todos os arquivos no Linux
`compilando/start.sh` | Para compilar no **BASH** do Windows (_Ubuntu_)
`compilados/main` | Arquivo compilado do trabalho(roda automatico nos scripts)
`arquivos/*` | Arquivos textos para testar

## ARQUIVOS FUNCIONANDO

Nome Arquivo|Status
|---|---|
`start.sh` | :heavy_check_mark:
`start_linux.sh`|:heavy_check_mark:
`main.c`|:heavy_check_mark:
`frequencia.c`|:heavy_check_mark:
`arvores.c`|:heavy_check_mark: 