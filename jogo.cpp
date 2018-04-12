#define TEMP_MAX_JOGO 20

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "arvore.hpp"
#include "jogo.hpp"

int Novo_jogo(char nome_do_jogo[])
{
	printf("Ola, bem vindo ao jogo das 20 rodadas\n");
	printf("Ao ser feita uma pergunta responda com 's' para sim e 'n' para nao\n");
	printf("Bom jogo\n");
	FILE * ponteiro_arquivo = fopen(nome_do_jogo, "w");
	if(ponteiro_arquivo == NULL)
	{
		printf("erro\n");
		return 1;
	}
	char pergunta_do_no[100], objeto_do_no[100], char_auxiliar, pergunta_auxiliar[100], objeto_auxiliar[100];
	printf("Insira uma pergunta a raiz\n");
	scanf("%[^\n]", pergunta_do_no);
	getchar();
	printf("Insira um objeto a raiz\n");
	scanf("%[^\n]", objeto_do_no);
	getchar();
	No_Arvore *raiz = Cria_no(pergunta_do_no, objeto_do_no), *no_auxiliar;
	no_auxiliar = raiz;
	for(int index = 0; index < TEMP_MAX_JOGO; index++)
	{
		printf("%s\n",no_auxiliar->pergunta);
		scanf("%c", &char_auxiliar);
		getchar();
		if(char_auxiliar == 's')
		{
			if(no_auxiliar->no_esquerdo == NULL)
			{
				printf("Seu objeto e %s?\n", no_auxiliar->objeto);
				scanf("%c", &char_auxiliar);
				getchar();
				if(char_auxiliar == 's')
				{
					printf("Parabens, fim de jogo\n");
					break;
				}/*if*/
				if(char_auxiliar == 'n')
				{
					printf("Escreve uma pergunta que diferencie o seu objeto do objeto anterior\n");
					scanf("%[^\n]", pergunta_auxiliar);
					getchar();
					printf("Escreva o seu objeto\n");
					scanf("%[^\n]", objeto_auxiliar);
					getchar();
					Add_no_esquerdo(&no_auxiliar, pergunta_auxiliar, objeto_auxiliar);
					printf("Seu objeto nao foi encontrado na arvore, mas acabou de ser adicionado\n");
					printf("Fim de jogo\n");
					break;
				}/*if*/
				else
				{
					printf("Opcao nao valida, fim de jogo\n");
					break;				
				}/*else*/
			}/*if*/
			else
				no_auxiliar = no_auxiliar->no_esquerdo;
		}/*if*/
		if(char_auxiliar == 'n')
		{
			if(no_auxiliar->no_direito == NULL)
			{
				printf("Seu objeto e %s?\n", no_auxiliar->objeto);
				scanf("%c", &char_auxiliar);
				getchar();
				if(char_auxiliar == 's')
				{
					printf("Parabens, fim de jogo\n");
					break;
				}/*if*/
				if(char_auxiliar == 'n')
				{
					printf("Escreve uma pergunta que diferencie o seu objeto do objeto anterior\n");
					scanf("%[^\n]", pergunta_auxiliar);
					getchar();
					printf("Escreva o seu objeto\n");
					scanf("%[^\n]", objeto_auxiliar);
					getchar();
					Add_no_direito(&no_auxiliar, pergunta_auxiliar, objeto_auxiliar);
					printf("Seu objeto nao foi encontrado na arvore, mas acabou de ser adicionado\n");
					printf("Fim de jogo\n");
					break;
				}/*if*/
				else
				{
					printf("Opcao nao valida, fim de jogo\n");
					break;				
				}/*else*/	
			}/*if*/
			else
				no_auxiliar = no_auxiliar->no_direito;
		}/*if*/
		else
		{
			printf("Opcao nao valida, fim de jogo\n");
			break;		
		}/*else*/
	}/*for*/
	Cria_arquivo_jogo(&ponteiro_arquivo, raiz);
	fclose(ponteiro_arquivo);
	return 1;
}

int Cria_arquivo_jogo(FILE ** arquivo, No_Arvore *raiz)
{
	No_Arvore * no_auxiliar = raiz;
	if(*arquivo == NULL)
		return 0;
	if(no_auxiliar == NULL)
	{
		fprintf(*arquivo, "0\n");
		return 1;
	}
	else
	{
		fflush(*arquivo);
		fprintf(*arquivo, "1%s£%s\n", no_auxiliar->pergunta, no_auxiliar->objeto);/* o simbolo £ é um simbolo para delimitar os campos no arquivo*/
		Cria_arquivo_jogo(arquivo, no_auxiliar->no_esquerdo);
		Cria_arquivo_jogo(arquivo, no_auxiliar->no_direito);
		return 1;
	}
}

int Ler_arquivo_jogo(FILE * arquivo, No_Arvore ** raiz)
{
	char pergunta_auxiliar[100], objeto_auxiliar[100];
	if(arquivo == NULL)
		return 0;
	if((char)fgetc(arquivo) == '1')
	{
		fscanf(arquivo,"%[^£]", pergunta_auxiliar);
		fgetc(arquivo);
		fgetc(arquivo);	
		fscanf(arquivo,"%[^\n]", objeto_auxiliar);
		fgetc(arquivo);
		*raiz = Cria_no(pergunta_auxiliar, objeto_auxiliar);
		Ler_arquivo_jogo(arquivo, &(*raiz)->no_esquerdo);
		Ler_arquivo_jogo(arquivo, &(*raiz)->no_direito);
		return 1;
	}
	if((char)fgetc(arquivo) == '0' )
	{
		fgetc(arquivo);
		return 1;
	}
	else
		return 1;
}

int Continuar_jogo(char nome_do_jogo[])
{
	FILE * ponteiro_arquivo = fopen(nome_do_jogo, "r");
	if(ponteiro_arquivo == NULL)
	{
		printf("save nao encontrado\n");
		return 1;
	}
	printf("Ola, bem vindo ao jogo das 20 rodadas\n");
	printf("Ao ser feita uma pergunta responda com 's' para sim e 'n' para nao\n");
	printf("Bom jogo\n");
	char char_auxiliar, pergunta_auxiliar[100], objeto_auxiliar[100];
	No_Arvore *raiz = NULL, *no_auxiliar;
	Ler_arquivo_jogo(ponteiro_arquivo,&raiz);
	no_auxiliar = raiz;
	for(int index = 0; index < TEMP_MAX_JOGO; index++)
	{
		printf("%s\n",no_auxiliar->pergunta);
		printf("Deseja alterar essa pergunta?(caso ela nao faca sentido)\n");
		scanf("%c", &char_auxiliar);
		getchar();
		if(char_auxiliar == 's')
		{
			printf("digite uma nova pergunta\n");
			scanf("%[^\n]", no_auxiliar->pergunta);
			getchar();
		}
		if(char_auxiliar != 's' && char_auxiliar != 'n')
		{
			printf("Opcao nao valida, fim de jogo\n");
			break;	
		}
		printf("Agora responda a nova pergunta\n");	
		scanf("%c", &char_auxiliar);
		getchar();
		if(char_auxiliar == 's')
		{
			if(no_auxiliar->no_esquerdo == NULL)
			{
				printf("Seu objeto e %s?\n", no_auxiliar->objeto);
				scanf("%c", &char_auxiliar);
				getchar();
				if(char_auxiliar == 's')
				{
					printf("Parabens, fim de jogo\n");
					break;
				}/*if*/
				if(char_auxiliar == 'n')
				{
					printf("Escreve uma pergunta que diferencie o seu objeto do objeto anterior\n");
					scanf("%[^\n]", pergunta_auxiliar);
					getchar();
					printf("Escreva o seu objeto\n");
					scanf("%[^\n]", objeto_auxiliar);
					getchar();
					Add_no_esquerdo(&no_auxiliar, pergunta_auxiliar, objeto_auxiliar);
					printf("Seu objeto nao foi encontrado na arvore, mas acabou de ser adicionado\n");
					printf("Fim de jogo\n");
					break;
				}/*if*/
				else
				{
					printf("Opcao nao valida, fim de jogo\n");
					break;				
				}/*else*/
			}/*if*/
			else
				no_auxiliar = no_auxiliar->no_esquerdo;
		}/*if*/
		if(char_auxiliar == 'n')
		{
			if(no_auxiliar->no_direito == NULL)
			{
				printf("Seu objeto e %s?\n", no_auxiliar->objeto);
				scanf("%c", &char_auxiliar);
				getchar();
				if(char_auxiliar == 's')
				{
					printf("Parabens, fim de jogo\n");
					break;
				}/*if*/
				if(char_auxiliar == 'n')
				{
					printf("Escreve uma pergunta que diferencie o seu objeto do objeto anterior\n");
					scanf("%[^\n]", pergunta_auxiliar);
					getchar();
					printf("Escreva o seu objeto\n");
					scanf("%[^\n]", objeto_auxiliar);
					getchar();
					Add_no_direito(&no_auxiliar, pergunta_auxiliar, objeto_auxiliar);
					printf("Seu objeto nao foi encontrado na arvore, mas acabou de ser adicionado\n");
					printf("Fim de jogo\n");
					break;
				}/*if*/
				else
				{
					printf("Opcao nao valida, fim de jogo\n");
					break;				
				}/*else*/	
			}/*if*/
			else
				no_auxiliar = no_auxiliar->no_direito;
		}/*if*/
		else
		{
			printf("Opcao nao valida, fim de jogo\n");
			break;		
		}/*else*/
	}/*for*/
	fclose(ponteiro_arquivo);
	ponteiro_arquivo = fopen(nome_do_jogo, "w");
	Cria_arquivo_jogo(&ponteiro_arquivo, raiz);
	fclose(ponteiro_arquivo);
	return 1;
}