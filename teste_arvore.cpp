#define CATCH_CONFIG_MAIN
#define OPERACAO_SUCEDIDA 1

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "catch.hpp"
#include "arvore.hpp"

TEST_CASE("Criando a raiz da Arvore")
{
	REQUIRE(Cria_raiz("pergunta generica") != NULL);
}

TEST_CASE("Adicionar no a esquerda")
{
	No_Arvore * raiz = Cria_raiz("pergunta generica");
	REQUIRE(Add_no_esquerdo(raiz,"pergunta generica") == OPERACAO_SUCEDIDA);
}

TEST_CASE("Adicionar no a direita")
{
	No_Arvore * raiz = Cria_raiz("pergunta generica");	
	REQUIRE(Add_no_direito(raiz,"pergunta generica") == OPERACAO_SUCEDIDA);
}