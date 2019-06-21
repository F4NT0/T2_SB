# Relatório do Programa Strange Compressor

## IDÉIA

A idéia do Programa é fazer:

* Leitura de um arquivo texto que possui uma String com letras
* Determinar quantas vezes cada letra aparece no arquivo
* Criar uma Tupla com a letra e a frequencia que ele aparece
* Colocar cada Tupla em um Nodo único
* Criar uma Lista de Nodos únicos
* Construir um Nodo pai, que a frequencia é a soma das frequencias dos outros Nodos
* Conectar todos os Nodos em uma Árvore
* Após construir a arvore, devemos verificar os bits de cada caminho
* Pegamos a string desses caminhos e criamos uma tabela com os valores com cada caractere verificado
* Pegamos o valor de bits criados e colocamos em um arquivo **.piz** para podermos colocar os bits 
* Nesse arquivo colocamos quantas vezes cara caractere irá aparecer no novo código construido

## ESTRUTURAÇÃO

### FREQUENCIA

* Foi criado um arquivo **frequencia.h** com as Structs e os Protótipos, para podermos fazer a modularização das Funções de Frequencia.

* Dentro do Arquivo de protótipos, utilizamos o código `ifndef` para podermos tomar cuidado para não existir outro arquivo com o mesmo nome

* Criamos o arquivo **frequencia.c** que irá ser construido todas as funções para se descobrir as frequencias de cara caractere

* o Arquivo **frequencia.h** será chamado no arquivo main para podermos utilizar as Funções de Frequencia na Main, com o seguinte código

```c
#include "frequencia.h"
```

### ARVORE

* Foi criado um arquivo **arvore.h** com as Structs e os Protótipos, para podermos fazer a modularização das Funções das Árvores.

* Dentro do Arquivo de protótipos, utilizamos o código `ifndef` para podermos tomar cuidado para não existir outro arquivo com o mesmo nome

* Criamos o arquivo **arvore.c** que irá ser construido todas as funções para podermos criar os Nodos e as arvores.

* o Arquivo **arvore.h** será chamado no arquivo main para podermos utilizar as Funções de Arvore na Main, com o seguinte código

```c
#include "arvore.h"
```

### BITS

* Foi criado um arquivo **bits.h** com as Structs e os Protótipos, para podermos fazer a modularização das Funções de leitura de bits.

* Dentro do Arquivo de protótipos, utilizamos o código `ifndef` para podermos tomar cuidado para não existir outro arquivo com o mesmo nome

* Criamos o arquivo **bits.c** que irá ser construido todas as funções para se descobrir o caminho pela arvore de Huffman para descobrir o código de cada caractere pelo caminho da raiz até o Nodo do caractere, que vai ser o novo código do caractere.

* o Arquivo **bits.h** será chamado no arquivo main para podermos utilizar as Funções de Arvore na Main, com o seguinte código

```c
#include "bits.h"
```

### START E START_LINUX

* Esses dois arquivos são arquivos em Shell Scripts que irão compilar todos os arquivos e iniciar o programa

### COMO FUNCIONA DE FORMA RÁPIDA

* O arquivo irá pedir o nome do arquivo que está armazenado no Diretório **arquivos**
* Ele irá construir o local do arquivo e irá ler o arquivo que esta no diretório e fazer as funções pedidas para determinar as frequencias e salvar os valores dos caracteres e das frequencias nas Tuplas.
* Após criado as Tuplas, irá ler cada posição da Tupla e criar Nodos únicos para cada caractere dentro das Tuplas
* Irá ser ordenado os valores dos Nodos em ordem crescente, onde ele irá colocar os caracteres com as menores frequencias no inicio.
* Será criado um Nodo pai com a soma das menores frequencias e será criado uma Arvore total com os Nodos com os caracteres e os Nodos pais de cada caractere
* Após criado toda a arvore ele irá ler cada caminho,onde os Nodos da esquerda deve ser adicionado a uma string com zeros e o da direita sera adicionado com uns, assim criamos o código de caminho da raiz até o Nodo do caractere e com isso criamos o código do caractere
* Será criado um arquivo externo com esse código de cada caractere sendo repetido pelo numero de vezes que o caractere se repete no arquivo original






