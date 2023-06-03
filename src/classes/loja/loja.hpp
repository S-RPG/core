#ifndef LOJA_H
#define LOJA_H
#include <vector>
#include <map>
#include <utility>
#include <string>

template<typename T>
class Loja{
public:
    void pedido(T e);               //nenhuma dessas funções está bem definida ainda, os tipos e os parametros estão sendo pensados
    _pedido = pedido(_itens);
    void compra();
    void entrega();

private:
    double _dinheiro;
    std::vector<std::pair<double,std::string>>_pedido;      //O vetor de pedido vai salvar o nome do edido e seu preço
    std::map<unsigned,std::pair<double,std::string>>_itens; //Cada item da lista vai ter um número referente a ele (unsigned), 
                                                            //um preço (double) e um nome (string)
    double _politica;                                       //alinhação política do personagem

};

#endif