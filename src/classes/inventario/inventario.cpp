#include "inventario.hpp"
#include <iostream>
#include <vector>
#include <utility>

 

    double Inventario::getDinheiro(){   //retorna dinheiro
        return _dinheiro;
      }


    double Inventario::_setDinheiro(){  //altera dinheiro
            this->_dinheiro;
       }



     void Inventario::exibir(map _inventario) { // exibe itens do inventário 
            
             for (auto it = _inventario.begin(); it != _inventario.end(); it++) {
                    
                    std::cout << it->first<<"(ID)"<< it->second.nome <<"(NOME)" << it->second.quantidade << "(QUANTIDADE)" << it->second.vitalidade <<"(VITALIDADE)" << it->second.sanidade << "(SANIDADE)" << std::endl;
    
            }

     std::cout<<"Escolha o número de uma opção:";
        std::cout<< "(1) consumir item";
        std::cout<< "(2) mostrar dinheiro";
        std::cout<< "(3) remover item do inventário";
        std::cout<< "(4) sair do inventário";


    std::cin>> int I;

      switch case(int I){
    
        case ( I == 3) {

             Inventario::remover(int ID, int QNT, map _inventario);
        }


        case (I == 2) {
                
             std::cout<<"$ = "; getDinheiro();
        }


        case(I == 1) {

            Inventario::consumir(int ID, int QNT, map _inventario);
        }


        case (I == 4) break;
    }
}






      void inventario::armazenar(std::vector<Item>novo) { // armazena itens comprados ou ganhos em eventos aleatórios 

        
    }  








    void inventario::remover(int ID, int QNT, map item) { // remove itens do inventário 
    
            std::cin >> "Escreva o ID do item que você quer remover:";
            
            std::cin >> int ID;

                for(auto it = inventario.begin(); it != inventario.end(); it++) {
                    
                    if(ID == it->first) {

                       std::cout << "Escreva a quantidade a remover:"    
                       
                       std::cin >> int QNT;

                    if(QNT < it->second.quantidade) {

                        it->second.quantidade = it->second.quantidade - QNT;

                    } else if (QNT == it->second.quantidade) {
                        
                        //não sei como deletar item inteiro

                    }
                }
            }  
         }





    void inventario::consumir(int ID, int QNT, map _inventario) { // consome uma quantidade x de um item e ganha/perde atributos

         std::cin >> "Escreva o ID do item que você quer consumir:";
            
            std::cin >> int ID;

                for(auto it = inventario.begin(); it != inventario.end(); it++) {
                    
                    if(ID == it->first) {

                       std::cout << "Escreva a quantidade a consumir:"    
                       
                       std::cin >> int QNT;

                    if(QTD < it->second.quantidade) {

                        it->second.quantidade = it->second.quantidade - QTD;

                           // implementar classe personagem an classe inventario tbm -  personagem.sanidade = personagem.sanidade + it->second.sanidade*QNT;
                           // implementar classe personagem an classe inventario tbm - personagem.vitalidade = personagem.vitalidade + it->second.vitalidade*QNT;



                    } else if (QTD == it->second.quantidade) {
                        
                         // implementar classe personagem an classe inventario tbm -  personagem.sanidade = personagem.sanidade + it->second.sanidade*QNT;
                         // implementar classe personagem an classe inventario tbm - personagem.vitalidade = personagem.vitalidade + it->second.vitalidade*QNT;
                         //não sei como deletar item inteiro

                    }
                }
            }  
         }
  
  

     


 

     
    