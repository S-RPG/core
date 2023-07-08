#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../src/class/loja/loja.hpp"

TEST_CASE("Teste de compra com carrinho vazio")
{
    Loja loja;
    CHECK_THROWS_AS(loja.compra(), InvalidCarException);
}

TEST_CASE("Teste de compra com dinheiro insuficiente")
{
    Loja loja;
    loja.pedido(1, 2); // Adicione um item ao carrinho
    CHECK_THROWS_AS(loja.compra(), InvalidMoneyException);
}

TEST_CASE("Teste de pedido com item inválido")
{
    Loja loja;
    CHECK_THROWS_AS(loja.pedido(10, 2), InvalidCodException);
}

TEST_CASE("Teste de pedido com quantidade insuficiente")
{
    Loja loja;
    loja.pedido(1, 5); // Adicione um item ao carrinho
    CHECK_THROWS_AS(loja.pedido(1, 10), InvalidQntException);
}

TEST_CASE("Teste de pedido com item válido")
{
    Loja loja;
    loja.pedido(1, 2); // Adicione um item ao carrinho
    auto carrinho = loja.getCarrinho();
    CHECK(carrinho.size() == 1);        // Verifique se o item foi adicionado ao carrinho corretamente
    CHECK(carrinho[1].quantidade == 2); // Verifique se a quantidade do item está correta
}

TEST_CASE("Teste de adição de item ao carrinho")
{
    Loja loja;
    // loja.setItens()={
    //     {1,{{"pao", TipoItem::ALIMENTO, true, 2.0, 5, 1, 10, 1},true}},
    //     {2,{{"queijo", TipoItem::ALIMENTO, true, 6.0, 5, 1, 2, 2},true}},
    //     {3,{{"faca", TipoItem::ARMA, false, 10.0, 0, 0, 3, 3},true}},
    //     {4,{{"fita adesiva", TipoItem::FERRAMENTA, false, 4.0, 0, 0, 2, 4},false}}
    // };
    loja.pedido(1, 3);
    loja.pedido(2, 2);

    const auto &carrinho = loja.getCarrinho();
    CHECK(carrinho.size() == 2);
    CHECK(carrinho.at(1).quantidade == 3);
    CHECK(carrinho.at(2).quantidade == 2);
}

TEST_CASE("Teste de remoção de item do carrinho")
{
    Loja loja;
    loja.pedido(1, 3);
    loja.pedido(2, 2);
    loja.removePedido(1, 1);

    const auto &carrinho = loja.getCarrinho();
    CHECK(carrinho.size() == 2);
    CHECK(carrinho.at(1).quantidade == 2);
    CHECK(carrinho.at(2).quantidade == 2);
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
