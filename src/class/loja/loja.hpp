/// @file loja.h
/// @brief Definição da estrutura Loja
/// Este arquivo contém a definição da estrutura Loja, responsável pelo gerenciamento do loja do jogo.
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

#ifndef LOJA_H
#define LOJA_H

#include "../item/item.hpp"
//#include "inventario.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <string>
#include <exception>


//tratamento de exceções da encontrados na Loja
class InvalidOptionException : public std::exception {
public:
  const char *what() const noexcept override;
};

/// @brief Classe de exceção para código inválido
class InvalidCodException : public std::exception {
public:

  /// @brief Construtor da classe InvalidCodException
  /// @param message Mensagem de erro da exceção
  InvalidCodException(const std::string &message);
  const char *what() const noexcept override;
  
private:
  std::string _message; ///< Mensagem de erro da exceção
};

/// @brief Classe de exceção para quantidade inválida
class InvalidQntException : public std::exception {
public:

  /// @brief Construtor da classe InvalidQntException
  /// @param message Mensagem de erro da exceção
  InvalidQntException(const std::string &message);
  const char *what() const noexcept override;
  
private:
  std::string _message; ///< Mensagem de erro da exceção
};

/// @brief Classe de exceção para carrinho inválido
class InvalidCarException : public std::exception {
public:

  /// @brief Construtor da classe InvalidCarException
  /// @param message Mensagem de erro da exceção
  InvalidCarException(const std::string &message);
  const char *what() const noexcept override;
  
private:
  std::string _message; ///< Mensagem de erro da exceção
};

/// @brief Classe de exceção para valor monetário inválido
class InvalidMoneyException : public std::exception {
public:
  const char *what() const noexcept override;
};



class Loja{
private:
    double _dinheiro;                                                                           //vai receber o valor do inventário
    //std::unordered_map<std::map<unsigned,std::pair<double,std::string>>,unsigned>_carrinho; //(remover) //O vetor de pedido vai salvar o nome do pedido e seu preço
    std::map<unsigned,Item>_carrinho;                     //map com o código do produto e o item
    //Inventario _inventario;         //Esperando a classe Inventário
    //std::map<std::map</*Item*/unsigned,std::pair<double,std::string>>,std::string>_itens;    //(remover)           //Cada item da lista vai ter um número referente a ele (unsigned), 
                                                                                                //um preço (double) e um nome (string)
    std::map<unsigned,std::pair<Item,bool>>_itens;       //map com o código do produto e um par do item e sua disponibilidade

public:

    /// @brief Realiza a compra dos itens no carrinho.
    /// @return True se a compra foi realizada com sucesso, False caso contrário.
    bool compra();

    //void definirDinheiro();         //Esperando a classe Inventário
    
    /// @brief Realiza a entrega dos itens comprados.
    void entrega();
    std::map<unsigned,Item> getCarrinho() const;
    std::map<unsigned,std::pair<Item,bool>> getItens() const;
    void mostrarCarrinho();

    /// @brief Exibe os itens disponíveis na loja.
    void mostrarItens();
    void pedido(unsigned cod, unsigned qnt);               //nenhuma dessas funções está bem definida ainda, os tipos e os parametros estão sendo pensados
    void removePedido(unsigned cod, unsigned qnt);
    void showLoja();
};

#endif