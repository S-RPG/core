#include "inventario.hpp"

    
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

        for(auto it = _inventario.begin(); it!=_inventario.end(); ++it) {
                 
            if(it->id == item.id ) {
                const auto Iit = it;
                it->quantidade += item.quantidade;
                _inventario.assign(Iit,it);
                return;

            } 
        }
        _inventario.push_back(item);
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
        unsigned ID = 0;
        std::cout << "Escreva o ID do item que você quer consumir:"<<std::endl;
        std::cin >> ID;

        for(int it=0; it < _inventario.size(); it++) {
                    
            if((_inventario[it].id == ID)&&(_inventario[it].consumivel==true)){
                
                unsigned QNT = 1;
                std::cout << "Escreva a quantidade a consumir:"<<std::endl;  
                       
                std::cin >> QNT;
                    
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

                else {throw InvalidConsumivelException(); }

            }
        }
        throw InvalidIdException();
    }








    void Inventario::remover() { // remove itens do inventário 

        unsigned ID = 0;
        std::cout << "Escreva o ID do item que você quer remover:";
            
        std::cin >> ID;

            for(auto it = _inventario.begin(); it!=_inventario.end(); it++) {
                    
                if(it->id == ID) {
                    unsigned QNT = 1;
                    std::cout << "Escreva a quantidade a remover:"<<std::endl;    
                       
                    std::cin >> QNT;

                if(QNT < it->quantidade && QNT > 0) {
                    const auto Iit = it;
                    it->quantidade -= QNT;
                    _inventario.assign(Iit,it);

                }  else if (QNT == 0) {throw InvalidQntException("Quantidade nula"); }


                else if (QNT == it->quantidade) {
                        
                    it=_inventario.erase(it);  //deleta o map do item com ID que foi passado
                   
                   
                } else {throw InvalidQntException("Quantidade acima da pertencida ao inventário");}

            } else {throw InvalidIdException(); }
        }  
    }










    void Inventario::exibir() { // exibe itens do inventário 

        std::size_t nomeTextLenMax = 0;


        for (auto it=_inventario.begin(); it!=_inventario.end(); it++){
                    
            std::size_t nomeTextLen = it->nome.size();
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
    
            if(it->consumivel == true) {


            std::cout << std::left << std::setw(5) << it->id
                    << " | " << std::setw(tab) << it->nome
                    << " | " << std::setw(11) << std::fixed << std::setprecision(2) << it->quantidade
                    << " | " << std::setw(11) << it->vitalidade
                    << " | " << std::setw(11) << it->sanidade << std::endl;
        
            } else if(it->consumivel == false) {
        
            std::cout << std::left << std::setw(5) << it->id
                    << " | " << std::setw(tab) << it->nome
                    << " | " << std::setw(11) << std::fixed << std::setprecision(2) <<" "
                    << " | " << std::setw(11) <<" "
                    << " | " << std::setw(11) <<" "<< std::endl;


            }
            
                                                                            
        }
        std::cout << linhaHoriz << std::endl;
    

        int I = 0;
        std::cout<<"Escolha o número de uma opção:"<<std::endl;
        std::cout<<" (1) consumir item"<<std::endl;
        std::cout<<" (2) mostrar dinheiro"<<std::endl;
        std::cout<<" (3) remover item do inventário"<<std::endl;
        std::cout<<" (4) sair do inventário"<<std::endl;



        std::cin>> I;
    
            
        bool sair = false;
                
        while(sair!= true){

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

            default:
                throw InvalidOptionException();
                break;
            }
            
         }
    }




     








  


    
  

     


 

     
    