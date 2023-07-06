/// @file inventario.h
/// @brief Definição da estrutura Inventario
/// 
/// Este arquivo contém a definição da estrutura Inventario, responsável pelo gerenciamento do inventario do personagem.
///
/// A estrutura Inventario possui informações sobre o dinheiro disponível, os itens armazenados e os métodos para exibir,
/// armazenar, remover e consumir itens.
///
/// @version 1.0
/// @date 07/07/2023
///
/// @authors
/// - Alan Mota Calegari
/// - Davi de Carvalho Clark
/// - Gustavo Santiago de Magalhães
/// - Ricardo Augusto Costa Brito Moraes
/// - Washington Aparecido de Jesus Morais

#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <iostream>
#include <utility>
#include <vector>
#include "../item/item.hpp"

/// @brief Estrutura que representa o Inventário do Jogador
class Inventario {
public:

    /// @brief Obtém o dinheiro disponível no inventário.
    /// @return O valor do dinheiro disponível.
    double getDinheiro();

    /// @brief Exibe os itens do inventário.
    /// @param item O mapa de itens a ser exibido.
    void exibir(std::map<unsigned, Item> item);

    /// @brief Armazena um item no inventário.
    /// @param item O item a ser armazenado.
    void armazenar(std::map<unsigned, Item> item);

    /// @brief Remove um item do inventário.
    /// @param item O item a ser removido.
    void remover(std::map<unsigned, Item> item);

    /// @brief Consome uma quantidade de um item e atualiza os atributos do jogador.
    /// @param item O item a ser consumido.
    void consumir(std::map<unsigned, Item> item);

private:
    std::map<unsigned, Item> _inventario; ///< Mapa de itens do inventário
    double _dinheiro; ///< Quantidade de dinheiro disponível
};

#endif