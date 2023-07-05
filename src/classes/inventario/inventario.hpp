#ifndef inventario.hpp
#define inventario.hpp
#include <iostream>
#include <utility>
#include <vector>
#include "item.hpp"


class inventario {
   
    public:
        
        double getMoney();
        void exibir(char);

    private:
        
        map <unsigned,Item> inventario; // <id,(nome, quantidade, sanidade e vitalidade)>  mapa de <id do item, variavel do tipo item>
        
        double _money;
        double _setMoney();
        

   

inventario->first()
inventario->second().nome
inventario->second().vitalidade       

    
    
       

       
        

        
        
        
}

      double getMoney(){
            return money;
      }

      double _setMoney(){
            this->money;
       }

      

    void armazenar(map item); // armazena itens comprados ou ganhos em eventos aleatórios
            

    void exibir(char I); // exibe itens do inventário
       
        cout << inventario->first() "(ID)" << inventario->second().nome "(NOME)" << inventario->second().quantidade "(QTD)" << inventario->second().sanidade"(SAN)" << inventario->second().vitalidade"(VIT)" << endl;

    void remover(map item); // remove itens do inventário 


    void consumir(map item); // consome uma quantidade x de um item e ganha/perde atributos



     #endif