#include "inventario.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <exception>
 

    double Inventario::getDinheiro(){   //retorna dinheiro
        return _dinheiro;
      }


    double Inventario::_setDinheiro(){  //altera dinheiro
            this->_dinheiro;
       }





    void Inventario::armazenar(unsigned ID, unsigned QNT) { // armazena itens comprados ou ganhos em eventos aleatórios 

         for(auto it = _inventario.begin(); it != _inventario.end(); it++) {
                 
                 if(it->first == ID ) {
                    
                    it->second.quantidade = it->second.quantidade + QNT;

                 } else if (ID != it->first) {

                    //_inventario.insert(make_pair<unsigned,Item>(ID, item));
                    //_inventario[Item]=ID;

                    it->first = ID;
                    it->second.nome = item.nome;
                    it->second.quantidade = QNT;
                    it->second.vitalidade = item.vitalidade;
                    it->second.sanidade = item.sanidade;
             } 
         }







    void Inventario::consumir() { // consome uma quantidade x de um item e ganha/perde atributos

        Personagem personagem;

         std::cout << "Escreva o ID do item que você quer consumir:";
            
            std::cin >> unsigned ID;

                for(auto it = inventario.begin(); it != inventario.end(); it++) {
                    
                    if(it->first == ID && it->second.consumivel=true) {

                       std::cout << "Escreva a quantidade a consumir:"    
                       
                       std::cin >> unsigned QNT;

                    if(QNT < it->second.quantidade) {

                        it->second.quantidade = it->second.quantidade - QNT;

                                personagem.getVitalidade()+=it->second.vitalidade*QNT;
                                
                                personagem.getSanidade()+=it->second.sanidade*QNT;

                    } else if (QNT == it->second.quantidade) {
                        
                            _inventario.erase(ID); //deleta o map do item com ID que foi passado
                                
                                personagem.getVitalidade()+=it->second.vitalidade*QNT;
                         
                                personagem.getSanidade()+=it->second.sanidade*QNT;
                    }
                }
            }  
         }
  








      void inventario::remover() { // remove itens do inventário 
    
            std::cout << "Escreva o ID do item que você quer remover:";
            
            std::cin >> unsigned ID;

                for(auto it = inventario.begin(); it != inventario.end(); it++) {
                    
                    if(it->first == ID) {

                       std::cout << "Escreva a quantidade a remover:"    
                       
                       std::cin >> unsigned QNT;

                    if(QNT < it->second.quantidade) {

                        it->second.quantidade = it->second.quantidade - QNT;

                    } else if (QNT == it->second.quantidade) {
                        
                        _inventario.erase(ID);  //deleta o map do item com ID que foi passado
                    }
                }
            }  
         }










     void Inventario::exibir() { // exibe itens do inventário 
            
             for (auto it = _inventario.begin(); it != _inventario.end(); it++) {
                    if(it->second.consumivel == true){
                    std::cout << it->first<<"(ID)"<< it->second.nome <<"(NOME)" << it->second.quantidade << "(QUANTIDADE)" << it->second.vitalidade <<"(VITALIDADE)" << it->second.sanidade << "(SANIDADE)" << std::endl;
                    } else 
                    std::cout <<it->first<<"(ID)"<< it->second.nome<<"(NOME)"
            }

     std::cout<<"Escolha o número de uma opção:";
        std::cout<< "(1) consumir item";
        std::cout<< "(2) mostrar dinheiro";
        std::cout<< "(3) remover item do inventário";
        std::cout<< "(4) sair do inventário";



        std::cin>> int I;
    
            
            bool sair = false;
            
                
                while(sair != true){



                    switch (I){
        
                        case (1) {

                         Inventario::consumir();
                         } break;

                        case (2) {
                
                        std::cout<<"$ = "; getDinheiro();
                         } break;


                        case (3) {

                        Inventario::remover();
                        } break;


                        case (4) {
                        
                        sair = true} break;
             }
        }
     }




     








  


    
  

     


 

     
    