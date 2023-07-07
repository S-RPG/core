#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <iostream>
#include <utility>
#include <vector>
#include "../item/item.hpp"
#include <map>
//#include "../personagem/personagem.hpp"

class Inventario {
   
    public:
        
        double getDinheiro();
        
        void exibir(); // exibe itens do inventário
        
        void armazenar(int QNT, int ID); // armazena itens comprados ou ganhos em eventos aleatórios

        void remover(); // remove itens do inventário 

        void consumir(); // consome uma quantidade x de um item e ganha/perde atributos




private:
    

    std::map<unsigned, Item> _inventario; //map(ID, item - nome, quantidade, vitalidade, sanidade)
    
    double _setDinheiro();
    
    double _dinheiro; ///< Quantidade de dinheiro disponível
};


 #endif
