#include "loja.hpp"
#include <iostream>


//Aplicação das exeções
const char *InvalidOptionException::what() const noexcept {
  return "Opção inválida!!";
}

InvalidCodException::InvalidCodException(const std::string &message)
  : _message("Código inválido: " + message + "!") {}

const char *InvalidCodException::what() const noexcept {
  return _message.c_str();
}

InvalidQntException::InvalidQntException(const std::string &message)
  : _message("Quantidade inválida: " + message + "!") {}

const char *InvalidQntException::what() const noexcept {
  return _message.c_str();
}

InvalidCarException::InvalidCarException(const std::string &message)
  : _message(message + " carrinho está vazio!") {}

const char *InvalidCarException::what() const noexcept {
  return _message.c_str();
}

const char *InvalidMoneyException::what() const noexcept {
  return "Valor da compra é maior que o dinheiro que você possui!";
}

//Função responsável a atribuir a quantidade de dinheiro disponível (Aguardando a classe Inventario)
// void Loja::definirDinheiro(){
//     _dinheiro = _inventario.obterDinheiro();
// }

bool Loja::compra(){
    if(_carrinho.empty()){
        throw InvalidCarException("O");    //retorno de erro: carrinho vazio
        return false;
    }
    
    //clacula o preço total do carrinho
    auto it = _carrinho.begin();
    double total = 0.0;
    for (; it!=_carrinho.end(); it++) {
        total += (it->second.preco) * (it->second.quantidade);
    }
    
    Loja::mostrarCarrinho();

    if(total>_dinheiro){
        throw InvalidMoneyException();      //retorno de erro: dinheiro insuficiente
        return false;
    }

    _dinheiro -= total;           //como o dinheiro vai ser incluido? depois da classe inventário ser incluida isso vai ser feito
    Loja::entrega();              //função responsável por salvar os itens comprados no inventário
    return true;
}


void Loja::entrega(){
    //classe a ser pensada melhor por causa do funcionamento do programa
    //a ideia mais sensata é fazer essa função incluir os itens diretamente no inventário, mas para isso é preciso esperar a classe ser feita
    
    //código antigo (remover):
    /*std::map<unsigned,std::pair<unsigned,Item>>pedido;
    auto it = _carrinho.begin();
    for(;it!=_carrinho.end();it++){
        const auto& mapIn = it->first;
        const auto& parIn = mapIn.begin()->second;
        unsigned qnt = it->second;
        unsigned cod = parIn.first;
        std::string item = parIn.second;
        auto produto = std::make_pair(qnt,item);
        pedido.emplace(cod, produto);
    }*/

    //(definição atual)
    //_inventario.putItem(_carrinho->second);          //Chamada de função do inventário (a espera da classe inventário)
}

std::map<unsigned,Item> Loja::getCarrinho() const{
    return _carrinho;
}

std::map<unsigned,std::pair<Item,bool>> Loja::getItens() const{
    return _itens;
}

void Loja::mostrarCarrinho(){
    if(_carrinho.empty()){
        throw InvalidCarException("Nada para mostrar, o");    //retorno de erro carrinho vazio
        return;
    }

    std::size_t nomeTextLenMax = 0;

    for (auto it=_itens.begin(); it!=_itens.end(); it++){
        std::size_t nomeTextLen = it->second.first.nome.size();
        if (nomeTextLenMax < nomeTextLen){
            nomeTextLenMax = nomeTextLen;
        }
    }

    std::string cabeca = "Item";
    std::size_t cabecaTextLen = cabeca.size()/3;
    std::size_t tab = nomeTextLenMax + cabecaTextLen;
    
    std::string linhaHoriz = "";

    std::size_t totalSize = 5 + 6 + tab + 10 + 11;
    linhaHoriz.append(totalSize, '-');

    std::cout << linhaHoriz << std::endl;
    std::cout << std::left << std::setw(5) << "ID"
          << " | " << std::setw(tab) << cabeca
          << " | " << std::setw(8) << "Preço"
          << " | " << std::setw(11) << "Quantidade" 
          << " | " << std::setw(7) << "Quantidade"<< std::endl;
    std::cout << linhaHoriz << std::endl;

    double total = 0.0;
    for(auto it = _carrinho.begin(); it!=_carrinho.end(); it++){
        double valor = (it->second.preco)*(it->second.quantidade);                          //calcula o valor total de cada item e sua quantidade
        const auto& id = it->first;
        const auto& item = it->second;
 
        std::cout << std::left << std::setw(5) << id
                  << " | " << std::setw(tab) << item.nome
                  << " | @" << std::setw(6) << std::fixed << std::setprecision(2) << item.preco
                  << " | " << std::setw(11) << item.quantidade 
                  << " | " << std::setw(7) << valor << std::endl;

               
        total += valor;                                                                     //calcula o total do carrinho
    }
    std::cout << linhaHoriz << std::endl;
    
    std::cout<<"Total: @"<<total<<std::endl;
}


void Loja::mostrarItens(){
    std::size_t nomeTextLenMax = 0;

    for (auto it=_itens.begin(); it!=_itens.end(); it++){
        std::size_t nomeTextLen = it->second.first.nome.size();
        if (nomeTextLenMax < nomeTextLen){
            nomeTextLenMax = nomeTextLen;
        }
    }

    std::string cabeca = "Item";
    std::size_t cabecaTextLen = cabeca.size()/3;
    std::size_t tab = nomeTextLenMax + cabecaTextLen;
    
    std::string linhaHoriz = "";

    std::size_t totalSize = 5 + 6 + tab + 10 + 11;
    linhaHoriz.append(totalSize, '-');

    std::cout << linhaHoriz << std::endl;
    std::cout << std::left << std::setw(5) << "ID"
          << " | " << std::setw(tab) << cabeca
          << " | " << std::setw(8) << "Preço"
          << " | " << std::setw(11) << "Quantidade" << std::endl;
    std::cout << linhaHoriz << std::endl;

    for (auto it=_itens.begin(); it!=_itens.end(); it++) {
        const auto& id = it->first;
        const auto& item = it->second.first;
        const auto& disponivel = it->second.second;

        if (disponivel) {
            
            std::cout << std::left << std::setw(5) << id
                      << " | " << std::setw(tab) << item.nome
                      << " | @" << std::setw(6) << std::fixed << std::setprecision(2) << item.preco
                      << " | " << std::setw(11) << item.quantidade << std::endl;

        }
    }

    std::cout << linhaHoriz << std::endl;
}

void Loja::pedido(unsigned cod, unsigned qnt) {
    auto it = _carrinho.begin();
    auto Iit = _itens.begin();
    for (; Iit != _itens.end(); ++Iit) {
        auto& parIn = Iit->second;
        for(; it!=_carrinho.end(); it++){
            if(it->first==cod){                                     //Se o item já existe no carrinho, só é adicionado a quantidade desejada
                _carrinho[cod].quantidade += qnt;
                _itens[cod].first.quantidade -= qnt;
                return;

            } else if((Iit->first == cod)&&(parIn.second==true)&&(parIn.first.quantidade>=qnt)){    //item é válido e a quantidade é suficiente
                Item produto = parIn.first;                         //como o item é novo, é definir as propriedades do item a ser adicionado
                produto.quantidade = qnt;

                _itens[cod].first.quantidade -= qnt;                 //reduz do estoque a quantidade adicionada no carrinho

                _carrinho.emplace(cod,produto);           //adiciona o produto no carrinho

                return;

            } else if((Iit->first == cod)&&(parIn.second==true)&&(parIn.first.quantidade<qnt)){     //item é válido e a quantidade é insuficiente
                throw InvalidQntException("A quantidade de itens para ser adicionado ao carrinho é maior que a quantidade disponível no estoque");
                return;

            } else if((Iit->first == cod)&&(parIn.second==false)&&((parIn.first.quantidade>=qnt)||(parIn.first.quantidade<qnt))){   //item inválido
                throw InvalidCodException("Código de item indisponível");
                return;
            }
        }
    }

    throw InvalidCodException("Código inválido/não encontrado");
}

void Loja::removePedido(unsigned cod, unsigned qnt){
    if(_carrinho.empty()){
        throw InvalidCarException("O");    //retorno de erro carrinho vazio
        return;
    }

    auto it = _carrinho.begin();
    auto Iit = _itens.begin();
    for( ; it!=_carrinho.end(); it++){
        if((it->first)==cod){                                                   //se o código digitado for encontrado no carrinho
            for(; Iit!=_itens.end(); Iit++){                                    //vai ser procurado esse item na lista de itens
                if((it->second.quantidade)==qnt){                               //se a quantidade de itens a ser removido for igual a quantidade do carrinho
                std::cout<<"-"<<it->second.nome<<"totalmente removido!"<<std::endl;
                _itens[cod].first.quantidade += qnt;                            //O produto retorna para o estoque
                _carrinho.erase(it);                                            //O item é totalmente removido do carrinho
                return;

                } else if((it->second.quantidade)>qnt){                         //Quantidade a ser removida é menor que a do carrinho
                    _carrinho[cod].quantidade -= qnt;                           //Remove a quantidade de itens
                    _itens[cod].first.quantidade += qnt;                        //O produto retorna para o estoque
                    std::cout<<qnt<<"  "<<(it->second.nome)<<" removidos com sucesso!"<<std::endl;
                    return;

                } else if((it->second.quantidade)<qnt){                         //Quantidade a ser removida é maior que a do carrinho
                    //mensagem de erro, já que a quantidade a ser removida foi inválida
                    throw InvalidQntException("A quantidade de itens para ser removida é maior que a quantidade que está no carrinho");
                    return;
                }
            }
        }else{
            throw InvalidCodException("Código inválido/não encontrado");        //Erro de código errado
        }
    }
}

void Loja::showLoja(){
    Loja::mostrarItens();
    std::cout<<""<<std::endl;
    std::cout<<"Adicionar item ao carriho (add)"<<"   "
             <<"Remover item do carrinho (rmv)"<<"   "
             <<"Mostrar carrinho (show)"<<"   "
             <<"Sair (out)"<<std::endl;

    std::string opc;                            //opção
    unsigned cod=0;                             //código
    unsigned qnt=0;                             //quantidade

    compra:                                     //referência para o goto
    while(opc!="out"){
        std::cin>>opc;
        if(opc=="add"){                           //adiciona
            std::cin>>cod>>qnt;
            if(qnt>0){    //verificar se a quantidade é válida
                Loja::pedido(cod,qnt);
            }else{
                throw InvalidQntException("A quantidade de itens deve ser maior que 0");
            }
        } else if(opc=="rmv"){                    //remove
            std::cin>>cod>>qnt;
            if(qnt>0){    //verificar se a quantidade é válida
                Loja::removePedido(cod,qnt);
            }else{
                throw InvalidQntException("A quantidade de itens deve ser maior que 0");
            }
        }else if(opc=="show"){
            Loja::mostrarCarrinho();
            std::cout<<""<<std::endl;
            std::cout<<"Adicionar item ao carriho (add)"<<"   "
             <<"Remover item do carrinho (rmv)"<<"   "
             <<"Mostrar carrinho (show)"<<"   "
             <<"Sair (out)"<<std::endl;
        }else if(opc=="out"){                     //sai da interface
            break;
        }else {
            throw InvalidOptionException();    //erro de opção inválida
        }
    }
    std::cout<<"Carrinho:"<<std::endl;
    Loja::mostrarCarrinho();

    bool erro = true;
    bool erro2 = true;

    while(erro){
        char alt;                                 //alternativa
        std::cout<<"Deseja finalizar a compra?"<<"  "<<"S/N"<<std::endl;
        std::cin>>alt;

        switch(alt){
            case 'S':
            case 's':
                erro = !(Loja::compra());
                break;

            case 'N':
            case 'n':
                
                while(erro2){
                    std::cout<<"Alterar o carrinho (alt)"<<"   "<<"Cancelar a compra (dlt)"<<"  "<<"Finalizar (end)"<<std::endl;
                    std::cin>>opc;
                    if(opc=="alt"){                       //retorna ao while de edição do carrinho
                        erro2 = false;
                        goto compra;
                    }else if(opc=="dlt"){                //informa que o carrinho foi deletado para ele ser destruido direto no final do escopo da função
                        erro2 = false;
                    }else if(opc=="end"){                //vai para a seção de compra finalizar o pedido
                        erro2 = !(Loja::compra());
                        erro = !(Loja::compra());
                        
                    }else{
                        throw InvalidOptionException();
                    }
                }
                break;

            default:
                throw InvalidOptionException();     //erro de opção inválida
                break;
        }   
    }

    _carrinho.clear();    //destrutor do map
}
