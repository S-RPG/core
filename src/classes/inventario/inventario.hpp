#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "../item/item.hpp"
//#include "../personagem/personagem.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <exception>

class Inventario {
   
    public:
        
        double getDinheiro();
        
        void exibir(); // exibe itens do inventário
        
        void armazenar(unsigned QNT, unsigned ID); // armazena itens comprados ou ganhos em eventos aleatórios

        void remover(); // remove itens do inventário 

        void consumir(); // consome uma quantidade x de um item e ganha/perde atributos




private:
    

    std::map<unsigned, Item> _inventario; //map(ID, item - nome, quantidade, vitalidade, sanidade)
    
    double _setDinheiro();
    
    double _dinheiro; ///< Quantidade de dinheiro disponível
};


 #endif
