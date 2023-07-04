#include "inventario.hpp"
#include <iostream>
#include <vector>
#include <utility>

                         
  for(auto it:inventario){
   string inventario::exibir(string inventario){ 
       
        for(i=0; i < inventario.size();i++){
            std::cout<< it.first.first << it.first.second << it.second.first << it.second.second <<endl;

             }    
        }
    
    // IDEIA INICIAL 
    // if(string ação == "inventário" || "Inventário" || "inventario" || "Inventario") {
    //    do{
    //        std::cout<< struct Item;        //  pair<string item, int quantidade>; pair<string efeito, int efeito>;
    //        }
    //    }


    





    void inventario::remover (string item){
     
     if(*quantidade <= quantidade && *quantidade >= 0){
            
            
         for(i=0, i < inventario.size(); i++){
                if(string item == it.second.first){
                    delete pair[i];
                }
            }   quantidade = quantidade - *quantidade;
        }
    }  

        //IDEIA INICIAL
        //void remover (string){
        // if(string ação == "remover" || "Remover") {
        //    std::cin >> new Item;
        //    std::cin >> quantidade.Im;

  


    void inventario::consumir(string){
        
    if(quantidade >= *quantidade && *quantidade >= 0){
                quantidade = quantidade - *quantidade;
            
          for(i=0, i < par.size(); i++){
                if(string == it.first.first){
                    it.first.second = it.first.second - 1;
                }
            }       
                    quantidade = quantidade - *quantidade;

                    vitalidade = vitalidade + pair[i].second.first //(vit.Item)
             
                    sanidade = sanidade + pair[i].second.second //(san.Item)
        }
    }  
  }

     


        //IDEAL INICIAL
        //void consumir (string){
        // if(string ação == "usar" || "consumir" || "Usar" || "Consumir"){
        //    std::cin >> new Item;
        //    std::cin >> *quantidade.Item;



return 0;
    } 
    