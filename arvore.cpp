#include <iostream>
#include <cstdlib>
#include <cstring>
#include "arvore.hpp"

No_Arvore *Cria_raiz(char pergunta_da_raiz[])
{
	No_Arvore *raiz = (No_Arvore*) malloc(sizeof(No_Arvore));
	if(raiz == NULL)
		return NULL;
	else
	{
		strcpy(raiz->pergunta, pergunta_da_raiz);
		raiz->no_direito = NULL;
		raiz->no_esquedo = NULL;
		return raiz;
	}
}

No_Arvore *Remover_no(No_Arvore * no)
{
	if(no == NULL)
		return no;
	else
	{
		Remover_no(no->no_esquedo);
		Remover_no(no->no_direito);
		free(no);
		no = NULL;
		return no;
	}
}

int Add_no_esquerdo(No_Arvore *raiz,char pergunta_do_no[])
{
	raiz->no_esquedo = (No_Arvore*) malloc(sizeof(No_Arvore));
	if(raiz->no_esquedo == NULL)
		return 0;
	else
	{
		strcpy(raiz->no_esquedo->pergunta, pergunta_do_no);
		raiz->no_esquedo->no_esquedo = NULL;
		raiz->no_esquedo->no_direito = NULL;
		return 1;
	}
}

int Add_no_direito(No_Arvore *raiz,char pergunta_do_no[])
{
	raiz->no_direito = (No_Arvore*) malloc(sizeof(No_Arvore));
	if(raiz->no_direito == NULL)
		return 0;
	else
	{
		strcpy(raiz->no_direito->pergunta, pergunta_do_no);
		raiz->no_direito->no_esquedo = NULL;
		raiz->no_direito->no_direito = NULL;
		return 1;
	}
}