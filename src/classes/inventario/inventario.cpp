#include "inventario.hpp"
#include <iostream>
#include <vector>
#include <utility>

   

    double getDinheiro(){
            return dinheiro;
      }


    double _setDinheiro(){
            this->dinheiro;
       }


                         
  for(auto it:inventario){
    

    void inventario::armazenar(map item) { // armazena itens comprados ou ganhos em eventos aleatórios 

        
    }       






    
       



    void inventario::exibir(char I) { // exibe itens do inventário 
      
        if(char == "I"){
            
             for (auto it = inventario.begin(); it != inventario.end(); it++) {
                    
                    std::cout << it->first<<"(ID)"<< it->second.nome <<"(NOME)" << it->second.quantidade << "(QUANTIDADE)" << it->second.vitalidade <<"(VITALIDADE)" << it->second.sanidade << "(SANIDADE)" << std::endl;
    
            }
        }
    }

    void inventario::void remover(map item) { // remove itens do inventário 
    

        if(string == "rmv") {
           
           std::cin >> int ID;

                for(auto it = map.begin(); it != map.end(); it++) {
                    
                    if(int ID == it->first) {

                       std::cout << "Escreva a quantidade a remover"    
                       
                       std::cin >> int QTD;




            }

        }  

    }





    void inventario::consumir(map item) { // consome uma quantidade x de um item e ganha/perde atributos

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
  
  

     



return 0;
     
    