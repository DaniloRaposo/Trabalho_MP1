#define CATCH_CONFIG_MAIN
#define OPERACAO_BEM_SUCEDIDA 1

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "catch.hpp"
#include "arvore.hpp"

TEST_CASE("Criando a raiz da Arvore")
{
	char pergunta_generica[] = "pergunta generica", objeto_generico[] = "objeto generico";

	REQUIRE(Cria_raiz(pergunta_generica, objeto_generico) != NULL);
}

TEST_CASE("Adicionar no a esquerda")
{
	char pergunta_generica[] = "pergunta generica", objeto_generico[] = "objeto generico";
	No_Arvore * raiz = Cria_raiz(pergunta_generica, objeto_generico);

	REQUIRE(Add_no_esquerdo(raiz,pergunta_generica, objeto_generico) == OPERACAO_BEM_SUCEDIDA);
}

TEST_CASE("Adicionar no a direita")
{
	char pergunta_generica[] = "pergunta generica",objeto_generico[] = "objeto generico";
	No_Arvore * raiz = Cria_raiz(pergunta_generica, objeto_generico);

	REQUIRE(Add_no_direito(raiz,pergunta_generica, objeto_generico) == OPERACAO_BEM_SUCEDIDA);
}

TEST_CASE("Remover um no")
{
	char pergunta_generica[] = "pergunta generica", objeto_generico[] = "objeto generico";
	No_Arvore * raiz = Cria_raiz(pergunta_generica, objeto_generico);
	Add_no_direito(raiz, pergunta_generica, objeto_generico);
	Add_no_esquerdo(raiz, pergunta_generica, objeto_generico);

	REQUIRE(Remover_no(raiz) == NULL);
}