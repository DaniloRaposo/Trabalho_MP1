#include <iostream>
#include <cstdlib>
#include <cstring>

#ifndef ARVORE
#define ARVORE

typedef struct No_Arvore
{
	char pergunta[100], objeto[100];/*tamanho maximo da pergunta e do objeto igual a 100*/
	struct No_Arvore *no_esquerdo, *no_direito;
}No_Arvore;

No_Arvore *Cria_no(char pergunta_do_no[], char objeto_do_no[]);
No_Arvore *Remover_no(No_Arvore ** no);
int Add_no_esquerdo(No_Arvore **pai, char pergunta_do_no[], char objeto_do_no[]);
int Add_no_direito(No_Arvore **pai, char pergunta_do_no[], char objeto_do_no[]);

#endif