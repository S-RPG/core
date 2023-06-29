#ifndef LOJA_H
#define LOJA_H
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>

template<typename T>
class Loja{
private:
    double _dinheiro;                                       //vai receber o valor do inventário
    std::vector<std::pair<double,std::string>>_pedido;      //O vetor de pedido vai salvar o nome do pedido e seu preço
    std::map<unsigned,std::pair<double,std::string>>_itens; //Cada item da lista vai ter um número referente a ele (unsigned), 
                                                            //um preço (double) e um nome (string)
    double _politica;                                       //alinhação política do personagem recebida pela classe Personagem (remover??)

public:
    void compra();
    void entrega();
    void pedido(T e);               //nenhuma dessas funções está bem definida ainda, os tipos e os parametros estão sendo pensados
    void mostrarItens();
};

#endif