#include <iostream>
#include <cstdlib>
#include <cstring>

#ifndef ARVORE
#define ARVORE

typedef struct No_Arvore
{
	char pergunta[100];/*tamanho maximo da pergunta igual a 100*/
	struct No_Arvore *no_esquedo, *no_direito;
}No_Arvore;

No_Arvore *Cria_raiz(char pergunta_da_raiz[]);
No_Arvore *Remover_no(No_Arvore * no);
int Add_no_esquerdo(No_Arvore *raiz,char pergunta_do_no[]);
int Add_no_direito(No_Arvore *raiz,char pergunta_do_no[]);

#endif