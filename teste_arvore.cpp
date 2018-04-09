#define CATCH_CONFIG_MAIN
#define OPERACAO_SUCEDIDA 1

#include "catch.hpp"
#include "arvore.hpp"
#include <iostream>

TEST_CASE("Criando a raiz da Arvore")
{
	REQUIRE(Cria_raiz("pergunta generica") != NULL);
}

TEST_CASE("Adicionar no a esquerda")
{
	No_Arvore * raiz;
	REQUIRE(Add_no_esquerda(raiz,"pergunta generica") == OPERACAO_SUCEDIDA);
}

TEST_CASE("Adicionar no a direita")
{
	No_Arvore * raiz;	
	REQUIRE(Add_no_direita(raiz,"pergunta generica") == OPERACAO_SUCEDIDA);
}