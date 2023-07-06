#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../src/classes/loja/loja.hpp"

TEST_CASE("Teste de compra com carrinho vazio lança exceção") {
    Loja loja;
    CHECK_THROWS_AS(loja.compra(), InvalidCarException);
}

TEST_CASE("Teste de compra com dinheiro insuficiente lança exceção") {
    Loja loja;
    loja.pedido(1, 2); // Adiciona um item com código 1 e quantidade 2
    CHECK_THROWS_AS(loja.compra(), InvalidMoneyException);
}

TEST_CASE("Teste de adição de item ao carrinho") {
    Loja loja;
    loja.pedido(1, 3);
    loja.pedido(2, 2);

    const auto& carrinho = loja.getCarrinho();
    CHECK(carrinho.size() == 2);
    CHECK(carrinho[1].quantidade == 3);
    CHECK(carrinho[2].quantidade == 2);
}

TEST_CASE("Teste de remoção de item do carrinho") {
    Loja loja;
    loja.pedido(1, 3);
    loja.pedido(2, 2);
    loja.removePedido(1, 1);

    const auto& carrinho = loja.getCarrinho();
    CHECK(carrinho.size() == 2);
    CHECK(carrinho[1].quantidade == 2);
    CHECK(carrinho[2].quantidade == 2);
}

TEST_CASE("Teste de entrega adiciona itens ao inventário") {
    Loja loja;
    loja.pedido(1, 3);
    loja.pedido(2, 2);
    loja.entrega();

    const auto& inventario = loja.getItens();
    CHECK(inventario.size() == 2);
    CHECK(inventario[1].quantidade == 3);
    CHECK(inventario[2].quantidade == 2);
}
