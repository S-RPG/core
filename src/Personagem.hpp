
/// @file personagem.h
/// @brief Definição da classe Personagem
/// Este arquivo contém a definição da classe Personagem, responsável por representar um personagem do jogo.
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

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "../item/item.hpp"
#include "../inventario/inventario.hpp"

#include <vector>
#include <string>


/// @brief Classe que representa um personagem do jogo
class Personagem {
private:
    std::string _nome; ///< Nome do personagem
    int _sanidade; ///< Nível de sanidade do personagem
    int _vitalidade; ///< Nível de vitalidade do personagem
    int _dinheiro; ///< Quantidade de dinheiro do personagem
    int _fome; ///< Nível de fome do personagem
    Inventario inventario; ///< Inventário do personagem

public:

    /// @brief Construtor da classe Personagem.
    ///
    /// @param nome Nome do personagem.
    /// @param sanidade Nível de sanidade do personagem.
    /// @param vitalidade Nível de vitalidade do personagem.
    /// @param dinheiro Quantidade de dinheiro do personagem.
    /// @param fome Nível de fome do personagem.
    Personagem(const std::string nome, int sanidade, int vitalidade, int dinheiro, int fome);

    /// @brief Interage com um item do inventário.
    /// @param item O item com o qual o personagem irá interagir.
    void interagirItem(const Item& item);

    /// @brief Exibe o status do personagem.
    void exibirStatus() const;
};

#endif