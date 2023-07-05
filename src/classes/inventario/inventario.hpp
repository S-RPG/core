#ifndef inventario.hpp
#define inventario.hpp
#include <iostream>
#include <utility>
#include <vector>
#include "item.hpp"


class inventario {
   
    public:

        double getMoney();

    private:

        double _money;
        double _setMoney();
        

   
x = inventario->first()
x.first()
x.second()          

        //map <id,item item> inventario;  <quantidade,(nome, sanidade e vitalidade)> // mapa de <quantidade, variavel do tipo item>

       
        

        
        
        
}

      double getMoney(){
            return money;
      }

      double _setMoney(){
            this->money;
       }

      

    void armazenar(map item); // armazena itens comprados ou ganhos em eventos aleatórios


    string exibir(string ação); // exibe itens do inventário
    

    void remover(map item); // remove itens do inventário 


    void consumir(map item); // consome uma quantidade x de um item e ganha/perde atributos



     #endif