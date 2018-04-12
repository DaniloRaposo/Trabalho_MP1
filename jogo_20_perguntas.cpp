#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "arvore.hpp"
#include "jogo.hpp"

int main(int argc, char *argv[])
{
	char char_auxiliar;
	if(argc == 1)
	{
		printf("Por favor, coloque o nome de um arquivo no terminal\n");
		return 0;
	}
	printf("Digite 'n' para novo jogo e 'c' continuar jogo\n");
	scanf("%c", &char_auxiliar);
	getchar();
	if(char_auxiliar == 'n')
		Novo_jogo(argv[1]);
	if(char_auxiliar == 'c')
		Continuar_jogo(argv[1]);
	return 0;
}