#ifndef inventario.hpp
#define inventario.hpp
#include <iostream>
#include <utility>
#include <vector>
#include "item.hpp"


class inventario {
   
    public:
        
        double getDinheiro();
        
        void exibir(char I); // exibe itens do inventário
        
        void armazenar(map item); // armazena itens comprados ou ganhos em eventos aleatórios

        void remover(map item); // remove itens do inventário 

        void consumir(map item); // consome uma quantidade x de um item e ganha/perde atributos


            

    private:
        
        map <unsigned,Item> inventario; // <id,(nome, quantidade, sanidade e vitalidade)>  mapa de <id do item, variavel do tipo item>
        
        double _dinheiro;
        
        double _setDinheiro();
        
        
}



     #endif