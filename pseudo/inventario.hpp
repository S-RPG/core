#ifndef inventario.hpp
#define inventario.hpp
#include <iostream>
#include <utility>
#include <vector>
#include "item.hpp"


class inventario {
   
    public:
        int get.money();

    private:
        int tam;
        int money;
        std::pair<<pair<string nome, int quantidade>, pair<int sanidade, int vitalidade>> par[tam];
        
        // map<int quantidade,Item> inventario;  <quantidade,(nome, sanidade e vitalidade)>
        
        int set.money();
        
}

       get.money(int money){
            return money;
      }

       set.money(int money){
            this->money;
       }

    for(auto it:inventario){
   *string exibir(string ação);
    

    void remover (string item);


     void consumir (string);