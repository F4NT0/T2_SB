#!/bin/bash
gcc -o main ../src/main.c ../src/frequencia.c ../src/arvore.c ; mv main ../compilados/ ; cd .. ; cd compilados/ ; ./main
