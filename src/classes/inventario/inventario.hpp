#ifndef inventario.hpp
#define inventario.hpp
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
        
        map <unsigned,Item> _inventario; // <id,(nome, quantidade, sanidade e vitalidade)>  mapa de <id do item, variavel do tipo item>
        
        double _dinheiro;

        double _setDinheiro();
        
        
}



 #endif