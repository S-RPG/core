/// @file inventario.h
/// @brief Definição da classe Inventario
/// 
/// Este arquivo contém a definição da classe Inventario, responsável pelo gerenciamento do inventário de um personagem no jogo.
///
/// A classe Inventario possui funções para obter a quantidade de dinheiro disponível, exibir os itens presentes no inventário,
/// armazenar itens, remover itens e consumir itens, afetando os atributos do personagem.
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

#include "../item/item.hpp"
//#include "../personagem/personagem.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <map>
#include <exception>
#include <iomanip>
#include <algorithm>


/// @class InvalidConsumivelException
/// @brief Exceção lançada quando um item não consumível é usado para consumo
class InvalidConsumivelException : public std::exception{
public:
    const char *what() const noexcept override;
};


/// @class InvalidIdException
/// @brief Exceção lançada quando um ID inválido é fornecido
class InvalidIdException : public std::exception{
public:
    const char *what() const noexcept override;
};


/// @class InvalidOptionException
/// @brief Exceção lançada quando uma opção inválida é selecionada
class InvalidOptionException : public std::exception{
public:
    const char *what() const noexcept override;
};


/// @class InvalidQntException
/// @brief Exceção lançada quando uma quantidade inválida é fornecida
class InvalidQntException : public std::exception{
public:
    /// @brief Construtor da classe InvalidQntException
    /// @param message A mensagem de erro associada à exceção
    InvalidQntException(const std::string &message);

    const char *what() const noexcept override;

private:
    std::string _message; ///< A mensagem de erro associada à exceção
};


/// @class InvalidItemException
/// @brief Exceção lançada quando um item inválido é fornecido
class InvalidItemException : public std::exception{
public:
    /// @brief Construtor da classe InvalidItemException
    /// @param message A mensagem de erro associada à exceção
    InvalidItemException(const std::string &message);

    const char *what() const noexcept override;

private:
    std::string _message; ///< A mensagem de erro associada à exceção
};


/// @class Inventario
/// @brief Representa o inventário de um personagem
class Inventario {
public:
    /// @brief Obtém a quantidade de dinheiro disponível no inventário
    /// @return A quantidade de dinheiro
    double getDinheiro();

    /// @brief Exibe os itens presentes no inventário
    void exibir();

    /// @brief Armazena um item no inventário
    /// @param item O item a ser armazenado
    void armazenar(Item &item);

    /// @brief Remove um item do inventário
    void remover();

    /// @brief Consome uma quantidade específica de um item e afeta os atributos do personagem
    void consumir();

private:
    std::list<Item> _inventario; ///< Lista de itens no inventário
    double _setDinheiro(); ///< Define a quantidade de dinheiro disponível no inventário
    double _dinheiro; ///< Quantidade de dinheiro disponível
};

#endif // INVENTARIO_H
