#include <iostream>
#include <cstdlib>
#include <cstring>
#include "arvore.hpp"

#ifndef JOGO
#define JOGO

int Novo_jogo(char nome_do_jogo[]);
int Cria_arquivo_jogo(FILE ** arquivo, No_Arvore * raiz);
int Ler_arquivo_jogo(FILE * arquivo, No_Arvore ** raiz);
int Continuar_jogo(char nome_do_jogo[]);

#endif