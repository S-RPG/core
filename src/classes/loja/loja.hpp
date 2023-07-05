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

class InvalidOptionException : public std::exception {
public:
  const char *what() const noexcept override;
};

class InvalidCodException : public std::exception {
public:
  InvalidCodException(const std::string &message);
  const char *what() const noexcept override;
  
private:
  std::string _message;
};

class InvalidQntException : public std::exception {
public:
  InvalidQntException(const std::string &message);
  const char *what() const noexcept override;
  
private:
  std::string _message;
};

class InvalidCarException : public std::exception {
public:
  InvalidCarException(const std::string &message);
  const char *what() const noexcept override;
  
private:
  std::string _message;
};

class InvalidMoneyException : public std::exception {
public:
  const char *what() const noexcept override;
};

class Loja{
private:
    double _dinheiro;                                                                           //vai receber o valor do inventário
    //std::unordered_map<std::map<unsigned,std::pair<double,std::string>>,unsigned>_carrinho;     //O vetor de pedido vai salvar o nome do pedido e seu preço
    std::map<unsigned,Item>_carrinho;
    //Inventario _inventario;         //Esperando a classe Inventário
    //std::map<std::map</*Item*/unsigned,std::pair<double,std::string>>,std::string>_itens;               //Cada item da lista vai ter um número referente a ele (unsigned), 
                                                                                                //um preço (double) e um nome (string)
    std::map<unsigned,std::pair<Item,bool>>_itens;

public:
    bool compra();
    //void definirDinheiro();         //Esperando a classe Inventário
    void entrega();
    void interfaceLoja();
    void pedido(unsigned cod, unsigned qnt);               //nenhuma dessas funções está bem definida ainda, os tipos e os parametros estão sendo pensados
    void mostrarCarrinho();
    void mostrarItens();
    void removePedido(unsigned cod, unsigned qnt);
};

#endif