#include <iostream>
#include <cstdlib>
#include <cstring>
#include "arvore.hpp"

No_Arvore *Cria_no(char pergunta_do_no[], char objeto_do_no[])
{
	No_Arvore *no = (No_Arvore*) malloc(sizeof(No_Arvore));
	if(no == NULL)
		return NULL;
	else
	{
		strcpy(no->pergunta, pergunta_do_no);
		strcpy(no->objeto, objeto_do_no);
		no->no_direito = NULL;
		no->no_esquerdo = NULL;
		return no;
	}
}

No_Arvore *Remover_no(No_Arvore ** no)
{
	if(*no == NULL)
		return *no;
	else
	{
		Remover_no(&(*no)->no_esquerdo);
		Remover_no(&(*no)->no_direito);
		free(*no);
		*no = NULL;
		return *no;
	}
}

int Add_no_esquerdo(No_Arvore **pai,char pergunta_do_no[], char objeto_do_no[])
{
	(*pai)->no_esquerdo = (No_Arvore*) malloc(sizeof(No_Arvore));
	if((*pai)->no_esquerdo == NULL)
		return 0;
	else
	{
		strcpy((*pai)->no_esquerdo->pergunta, pergunta_do_no);
		strcpy((*pai)->no_esquerdo->objeto, objeto_do_no);
		(*pai)->no_esquerdo->no_esquerdo = NULL;
		(*pai)->no_esquerdo->no_direito = NULL;
		return 1;
	}
}

int Add_no_direito(No_Arvore **pai,char pergunta_do_no[], char objeto_do_no[])
{
	(*pai)->no_direito = (No_Arvore*) malloc(sizeof(No_Arvore));
	if((*pai)->no_direito == NULL)
		return 0;
	else
	{
		strcpy((*pai)->no_direito->pergunta, pergunta_do_no);
		strcpy((*pai)->no_direito->objeto, objeto_do_no);
		(*pai)->no_direito->no_esquerdo = NULL;
		(*pai)->no_direito->no_direito = NULL;
		return 1;
	}
}