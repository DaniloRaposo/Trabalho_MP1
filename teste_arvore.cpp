#define CATCH_CONFIG_MAIN
#define OPERACAO_SUCEDIDA 1

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "catch.hpp"
#include "arvore.hpp"

TEST_CASE("Criando a raiz da Arvore")
{
	char pergunta_generica[] = "pergunta generica";

	REQUIRE(Cria_raiz(pergunta_generica) != NULL);
}

TEST_CASE("Adicionar no a esquerda")
{
	char pergunta_generica[] = "pergunta generica";
	No_Arvore * raiz = Cria_raiz(pergunta_generica);

	REQUIRE(Add_no_esquerdo(raiz,pergunta_generica) == OPERACAO_SUCEDIDA);
}

TEST_CASE("Adicionar no a direita")
{
	char pergunta_generica[] = "pergunta generica";
	No_Arvore * raiz = Cria_raiz(pergunta_generica);

	REQUIRE(Add_no_direito(raiz,pergunta_generica) == OPERACAO_SUCEDIDA);
}

TEST_CASE("Remover um no")
{
	char pergunta_generica[] = "pergunta generica";
	No_Arvore * raiz = Cria_raiz(pergunta_generica);
	Add_no_direito(raiz, pergunta_generica);
	Add_no_esquerdo(raiz, pergunta_generica);

	REQUIRE(Remover_no(raiz) == NULL);
}