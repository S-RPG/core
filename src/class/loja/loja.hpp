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
// #include "../menu/menu.hpp"
//  #include "inventario.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <utility>
#include <string>
#include <exception>
#include <iomanip>

class Loja
{
private:
  float _dinheiro; // vai receber o valor do inventário
  // std::unordered_map<std::map<unsigned,std::pair<float,std::string>>,unsigned>_carrinho; //(remover) //O vetor de pedido vai salvar o nome do pedido e seu preço
  std::map<unsigned, Item> _carrinho; // map com o código do produto e o item
  // Inventario _inventario;         //Esperando a classe Inventário
  // std::map<std::map</*Item*/unsigned,std::pair<float,std::string>>,std::string>_itens;    //(remover)           //Cada item da lista vai ter um número referente a ele (unsigned),
  // um preço (float) e um nome (string)
  std::map<unsigned, std::pair<Item, bool>> _itens; // map com o código do produto e um par do item e sua disponibilidade

<<<<<<< HEAD
/// @brief Classe de exceção para opção inválida.
class InvalidOptionException : public std::exception {
=======
public:
  /// @brief Realiza a compra dos itens no carrinho.
  /// @return True se a compra foi realizada com sucesso, False caso contrário.
  bool compra();

  // void definirDinheiro();         //Esperando a classe Inventário

  /// @brief Realiza a entrega dos itens comprados.
  void entrega();
  std::map<unsigned, Item> getCarrinho() const;
  std::map<unsigned, std::pair<Item, bool>> getItens() const;
  void mostrarCarrinho();

  /// @brief Exibe os itens disponíveis na loja.
  void mostrarItens();
  void pedido(unsigned cod, unsigned qnt); // nenhuma dessas funções está bem definida ainda, os tipos e os parametros estão sendo pensados
  void removePedido(unsigned cod, unsigned qnt);
  void showLoja();
};

#endif

// tratamento de exceções da encontrados na Loja
class InvalidOptionException : public std::exception
{
>>>>>>> eea5279892b944e5fd32b9ad4b93ceb73b93b764
public:

  /// @brief Retorna uma mensagem de erro descrevendo a exceção.
  const char *what() const noexcept override;
};

<<<<<<< HEAD
/// @brief Classe de exceção para código inválido.
class InvalidCodException : public std::exception {
public:

  /// @brief Construtor da classe InvalidCodException.
  /// @param message Mensagem de erro da exceção.
=======
/// @brief Classe de exceção para código inválido
class InvalidCodException : public std::exception
{
public:
  /// @brief Construtor da classe InvalidCodException
  /// @param message Mensagem de erro da exceção
>>>>>>> eea5279892b944e5fd32b9ad4b93ceb73b93b764
  InvalidCodException(const std::string &message);

  /// @brief Retorna uma mensagem de erro descrevendo a exceção.
  const char *what() const noexcept override;

private:
  std::string _message; ///< Mensagem de erro da exceção.
};

<<<<<<< HEAD
/// @brief Classe de exceção para quantidade inválida.
class InvalidQntException : public std::exception {
public:

  /// @brief Construtor da classe InvalidQntException.
  /// @param message Mensagem de erro da exceção.
=======
/// @brief Classe de exceção para quantidade inválida
class InvalidQntException : public std::exception
{
public:
  /// @brief Construtor da classe InvalidQntException
  /// @param message Mensagem de erro da exceção
>>>>>>> eea5279892b944e5fd32b9ad4b93ceb73b93b764
  InvalidQntException(const std::string &message);

  /// @brief Retorna uma mensagem de erro descrevendo a exceção.
  const char *what() const noexcept override;

private:
  std::string _message; ///< Mensagem de erro da exceção.
};

<<<<<<< HEAD
/// @brief Classe de exceção para carrinho inválido.
class InvalidCarException : public std::exception {
public:

  /// @brief Construtor da classe InvalidCarException.
  /// @param message Mensagem de erro da exceção.
=======
/// @brief Classe de exceção para carrinho inválido
class InvalidCarException : public std::exception
{
public:
  /// @brief Construtor da classe InvalidCarException
  /// @param message Mensagem de erro da exceção
>>>>>>> eea5279892b944e5fd32b9ad4b93ceb73b93b764
  InvalidCarException(const std::string &message);

  /// @brief Retorna uma mensagem de erro descrevendo a exceção.
  const char *what() const noexcept override;

private:
  std::string _message; ///< Mensagem de erro da exceção.
};

<<<<<<< HEAD
/// @brief Classe de exceção para valor monetário inválido.
class InvalidMoneyException : public std::exception {
=======
/// @brief Classe de exceção para valor monetário inválido
class InvalidMoneyException : public std::exception
{
>>>>>>> eea5279892b944e5fd32b9ad4b93ceb73b93b764
public:

  /// @brief Retorna uma mensagem de erro descrevendo a exceção.
  const char *what() const noexcept override;
};
<<<<<<< HEAD

/// @brief Classe que representa uma loja.
class Loja{
private:

    double _dinheiro;  ///< Armazena o valor do dinheiro disponível na loja.      
    //vai receber o valor do inventário
    
    //std::unordered_map<std::map<unsigned,std::pair<double,std::string>>,unsigned>_carrinho; //(remover) //O vetor de pedido vai salvar o nome do pedido e seu preço
    
    std::map<unsigned,Item>_carrinho; ///< Mapa que armazena os itens adicionados ao carrinho. Chave: código do produto. Valor: item.
    
    //Inventario _inventario;         //Esperando a classe Inventário
    //std::map<std::map</*Item*/unsigned,std::pair<double,std::string>>,std::string>_itens;    //(remover)           //Cada item da lista vai ter um número referente a ele (unsigned), 
                                                                                                //um preço (double) e um nome (string)

    std::map<unsigned,std::pair<Item,bool>>_itens; ///< Mapa que armazena os itens disponíveis na loja. Chave: código do produto. Valor: par (item, disponibilidade).

public:

    /// @brief Realiza a compra dos itens no carrinho.
    /// @return True se a compra foi realizada com sucesso, False caso contrário.
    bool compra();

    //void definirDinheiro();         //Esperando a classe Inventário
    
    /// @brief Realiza a entrega dos itens comprados.
    void entrega();

    /// @brief Obtém o carrinho de compras.
    /// @return Mapa contendo o carrinho de compras.
    std::map<unsigned,Item> getCarrinho() const;

    /// @brief Obtém a lista de itens disponíveis na loja.
    /// @return Mapa contendo a lista de itens disponíveis na loja.
    std::map<unsigned,std::pair<Item,bool>> getItens() const;

    /// @brief Mostra os itens no carrinho.
    void mostrarCarrinho();

    /// @brief Exibe os itens disponíveis na loja.
    void mostrarItens();

    /// @brief Realiza um pedido de compra.
    ///
    /// @param cod Código do item a ser pedido.
    /// @param qnt Quantidade do item a ser pedido.
    void pedido(unsigned cod, unsigned qnt);        //nenhuma dessas funções está bem definida ainda, os tipos e os parametros estão sendo pensados

    /// @brief Remove um pedido do carrinho.
    ///
    /// @param cod Código do item a ser removido.
    /// @param qnt Quantidade do item a ser removido.
    void removePedido(unsigned cod, unsigned qnt);

    /// @brief Exibe as informações da loja.
    void showLoja();
};

#endif
=======
>>>>>>> eea5279892b944e5fd32b9ad4b93ceb73b93b764
