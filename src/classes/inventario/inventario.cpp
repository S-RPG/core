#include "inventario.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <exception>
#include <iomanip>
 
    
    const char *InvalidConsumivelException::what() const noexcept {
        
        return "O item não é consumível. Escolha um item do inventário que evidencie sua quantidade e seus efeitos (consumivel)";
    }


    const char *InvalidIdException::what() const noexcept {
        
        return "Id inválido. Digite o Id de um item que esteja no inventário";
    }


    const char *InvalidOptionException::what() const noexcept {
        
        return "Opção inválida. Escolha uma das disponíveis";
    }




    InvalidQntException::InvalidQntException(const std::string &message)
            
    : _message("Quantidade inválida: " + message) {}

            const char *InvalidQntException::what() const noexcept {
       
                 return _message.c_str();
             }




    InvalidItemException::InvalidItemException(const std::string &message)
  
    : _message("Item inválido: " + message) {}

             const char *InvalidItemException::what() const noexcept {
        
                return _message.c_str();
    }








    double Inventario::getDinheiro(){   //retorna dinheiro
        return _dinheiro;
      }


    double Inventario::_setDinheiro(){  //altera dinheiro
            this->_dinheiro;
       }





    void Inventario::armazenar(Item &item) { // armazena itens comprados ou ganhos em eventos aleatórios 

         for(auto it = _inventario.begin(); it != _inventario.end(); it++) {
                 
                 if(it->second.id == item.id ) {
                    
                    it->second.quantidade = it->second.quantidade + item.quantidade;

                 } else if (it->second.id != item.id) {

                   _inventario.insert(make_pair<unsigned, Item>);
                    
                    it->second.nome = item.nome;
                    it->second.id = item.id;
                    it->second.quantidade = item.quantidade;
                    it->second.vitalidade = item.vitalidade;
                    it->second.sanidade = item.sanidade;
            } 
        }
    }
         //unsigned itemInventarioId;
         
         //for(auto it = _inventario.begin(); it != _inventario.end(); it++) {
                 
                 //if(it->second.id == item.id ) {
                    
                    //it->second.quantidade = it->second.quantidade + item.quantidade;
                    //item.quantidade = 0;
                    //itemInventarioId = it->first;
                    //break;
                 //}  
            //}
         
         //if(!itemInventarioId = 0){
            
            //_inventario[_inventario.end()->first+1] = item;
         
         //}
    //}    







    void Inventario::consumir() { // consome uma quantidade x de um item e ganha/perde atributos

        Personagem personagem;

         std::cout << "Escreva o ID do item que você quer consumir:";
            
            std::cin >> unsigned ID;

                for(auto it = _inventario.begin(); it != _inventario.end(); it++) {
                    
                    if(it->second.id == ID){
                      
                      if(it->second.consumivel=true) {

                       std::cout << "Escreva a quantidade a consumir:"    
                       
                       std::cin >> unsigned QNT;
                    
                    if(QNT < it->second.quantidade && QNT != 0) {

                        it->second.quantidade = it->second.quantidade - QNT;

                                personagem.getVitalidade()+=it->second.vitalidade*QNT;
                                
                                personagem.getSanidade()+=it->second.sanidade*QNT;

                    
                    } else if(QNT == 0) {throw InvalidQntException("Quantidade nula"); }

                    
                     else if (QNT == it->second.quantidade) {
                        
                            _inventario.erase(ID); //deleta o map do item com ID que foi passado
                                
                                personagem.getVitalidade()+=it->second.vitalidade*QNT;
                         
                                personagem.getSanidade()+=it->second.sanidade*QNT;
                    
                    } else {throw InvalidQntException("Quantidade acima da pertencida ao inventário");}

                }  else {throw InvalidConsumivelException(); }

            }  else {throw InvalidIdException(); }
         }
     }








      void inventario::remover() { // remove itens do inventário 
    
            std::cout << "Escreva o ID do item que você quer remover:";
            
            std::cin >> unsigned ID;

                for(auto it = _inventario.begin(); it != _inventario.end(); it++) {
                    
                    if(it->second.id == ID) {

                       std::cout << "Escreva a quantidade a remover:"    
                       
                       std::cin >> unsigned QNT;

                    if(QNT < it->second.quantidade && QNT !=0) {

                        it->second.quantidade = it->second.quantidade - QNT;

                    }  else if (QNT == 0) {throw InvalidQntException("Quantidade nula"); }


                    else if (QNT == it->second.quantidade) {
                        
                        _inventario.erase(ID);  //deleta o map do item com ID que foi passado
                   
                   
                   } else {throw InvalidQntException("Quantidade acima da pertencida ao inventário");}

                } else {throw InvalidIdException(); }
            }  
         }










     void Inventario::exibir() { // exibe itens do inventário 
                        
            void printTable(std::map<unsigned,Item> _inventario) {

                 std::size_t nomeTextLenMax = 0;


            for (auto it=_inventario.begin(); it!=_inventario.end(); it++){
                    
                    std::size_t nomeTextLen = it->second.nome.size();
                        if (nomeTextLenMax < nomeTextLen){
                         nomeTextLenMax = nomeTextLen;
        }
    }


                     std::string cabeca = "Item";
                     std::size_t cabecaTextLen = cabeca.size()/3;
                     std::size_t tab = nomeTextLenMax + cabecaTextLen;
   
                        std::string linhaHoriz = "";


            std::size_t totalSize = 5 + 11 + tab + 11 + 11 + 11;
            linhaHoriz.append(totalSize, '-');


    std::cout << linhaHoriz << std::endl;
    std::cout << std::left << std::setw(5) << "ID"
          << " | " << std::setw(tab) << cabeca
          << " | " << std::setw(11) <<  "Quantidade"
          << " | " << std::setw(11) << "Vitalidade"
          << " | " << std::setw(11) << "Sanidade"<< std::endl;
    std::cout << linhaHoriz << std::endl;


   
    for(auto it = _inventario.begin(); it!=_inventario.end(); it++){
                               
        const auto& id = it->first; //!!!!
        const auto& item = it->second;
   
        if(item.use == true) {


        std::cout << std::left << std::setw(5) << item.id
                  << " | " << std::setw(tab) << item.nome
                  << " | " << std::setw(11) << std::fixed << std::setprecision(2) << item.quantidade
                  << " | " << std::setw(11) << item.vitalidade
                  << " | " << std::setw(11) << item.sanidade << std::endl;
       
        } else if(item.use == false) {
       
        std::cout << std::left << std::setw(5) << item.id
                  << " | " << std::setw(tab) << item.nome
                  << " | " << std::setw(11) << std::fixed << std::setprecision(2) <<" "
                  << " | " << std::setw(11) <<" "
                  << " | " << std::setw(11) <<" "<< std::endl;


        }
         
                                                                           
    }
    std::cout << linhaHoriz << std::endl;
   
 }


     std::cout<<"Escolha o número de uma opção:";
        std::cout<<" (1) consumir item";
        std::cout<<" (2) mostrar dinheiro";
        std::cout<<" (3) remover item do inventário";
        std::cout<<" (4) sair do inventário";



        std::cin>> int I;
    
            
            bool sair = false;
            
                
                while(sair != true){
                    
                  if(I==1 || I==2 || I==3 || I==4){

                    switch (I){
        
                        case 1: 

                         Inventario::consumir();
                          break;

                        case 2:
                
                        std::cout<<"$ = "; getDinheiro();
                          break;


                        case 3:

                        Inventario::remover();
                        break;


                        case 4:
                        sair = true; 
                        break;
                    }
                
                } else {
                    throw InvalidOptionException(); }
         }
     }




     








  


    
  

     


 

     
    