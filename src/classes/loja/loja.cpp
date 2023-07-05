#include "loja.hpp"
#include <iostream>

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

// void Loja::definirDinheiro(){
//     _dinheiro = _inventario.obterDinheiro();
// }

bool Loja::compra(){
    if(_carrinho.empty()){
        throw InvalidCarException("O");    //retorno de erro carrinho vazio
        return false;
    }
    
    auto it = _carrinho.begin();
    double total = 0.0;

    for (; it != _carrinho.end(); it++) {
        const auto& mapIn = it->first;
        //(mapIn.begin()->first).qnt = (it->second);        //o unsigned do código passa a ser um tipo Item que armazenará o nome e uma quantidade
                                                            //se bem que na hora das verificações, essa ideia quebraria o código
        total += (mapIn.begin()->second.first) * (it->second);
    }
    //Saindo desse 'for', haverá um vector com todos os ID dos itens do pedido que aramazenarão a quantidade de itens a serem adicionados
    Loja::mostrarCarrinho();

    if(total>_dinheiro){
        throw InvalidMoneyException();
        return false;
    }

    _dinheiro -= total;           //como o dinheiro vai ser incluido? depois da classe inventário ser incluida isso vai ser feito
    Loja::entrega();
    return true;
}


void Loja::entrega(){
    //classe a ser pensada melhor por causa do funcionamento do programa
    //a ideia mais sensata é fazer essa função incluir os itens diretamente no inventário, mas para isso é preciso esperar a classe ser feita
}


void Loja::interfaceLoja(){
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

    while(erro){
        char alt;                                 //alternativa
        std::cout<<"Deseja finalizar a compra?"<<"  "<<"S/N"<<std::endl;
        std::cin>>alt;

        if(alt=='S' || alt=='s'){                             //vai para a seção de compra finalizar o pedido
            erro = !(Loja::compra());
            Loja::entrega();                                  //função que adiciona o pedido no inventário
        }else if(alt=='N' || alt=='n'){                       //encontra uma situação antes da operação ser finalizada
            bool erro2 = true;
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
                    Loja::entrega();                //função que adiciona o pedido no inventário
                }else{
                    throw InvalidOptionException();
                }
            }
        }else{
            throw InvalidOptionException();     //erro de opção inválida
        }
    }

    _carrinho.clear();    //destrutor do map
}


void Loja::pedido(unsigned cod, unsigned qnt) {
    for (auto it = _itens.begin(); it != _itens.end(); ++it) {
        const auto& mapIn = it->first;
        const auto& situaItem = it->second;
        auto innerIt = mapIn.find(cod);

        if (innerIt != mapIn.end()) {
            if ((innerIt->first == cod)&&(situaItem == "DISPONÍVEL")) {
                const auto& par = innerIt->second;
                _carrinho.emplace(innerIt, qnt);
                std::cout << qnt << " " << par.second << " adicionados com sucesso!" << std::endl;
                return; // Saia da função após a inserção no carrinho bem-sucedida
            } else if ((innerIt->first == cod)&&(situaItem == "INDISPONÍVEL")){
                throw InvalidCodException("Código de item indisponível");
                return; // Saia da função, pois o item está indisponível
            }
        }
    }

    throw InvalidCodException("Código inválido/não encontrado");
}


void Loja::mostrarCarrinho(){
    if(_carrinho.empty()){
        throw InvalidCarException("Nada para mostrar, o");    //retorno de erro carrinho vazio
        return;
    }
    auto it = _carrinho.begin();
    double total = 0.0;
    for( ; it!=_carrinho.end(); it++){
        const auto& mapIn = it->first;
        double valor = (mapIn.begin()->second.first)*(it->second);
        std::cout<<(mapIn.begin()->second.second)<<" - "<<(it->second)<<" - @"<<valor<<std::endl; //retorna o nome do item e a quantidade
        total += valor;
    }
    std::cout<<"Total: @"<<total<<std::endl;
}


void Loja::mostrarItens(){
    auto it = _itens.begin();                       //copia o map de itens 
    const auto& mapIn = _itens.begin()->first;      //separa a primeira parte do map de itens, já que é outro map
    const auto& par = mapIn.begin()->second;        //separa o pair do map separado

    for( ; it!=_itens.end(); it++){
        std::cout<<(mapIn.begin()->first)<<" - "<<(par.second)
        <<" - @"<<(par.first)<<"  "<<"("<<(it->second)<<")"<<std::endl;
    }
}


void Loja::removePedido(unsigned cod, unsigned qnt){
    if(_carrinho.empty()){
        throw InvalidCarException("O");    //retorno de erro carrinho vazio
        return;
    }

    auto it = _carrinho.begin();
    const auto& mapIn = it->first;
    for( ; it!=_carrinho.end(); it++){
        if(((mapIn.begin()->first)==cod)){
            if((it->second)==qnt){
            auto &name = mapIn.begin()->second;
            std::cout<<"-"<<&name<<"totalmente removido!"<<std::endl;
            _carrinho.erase(it);
            } else if((it->second)>qnt){
                auto &name = mapIn.begin()->second;
                (it->second)=(it->second)-qnt;
                std::cout<<qnt<<"  "<<&name<<"removidos com sucesso!"<<std::endl;
            } else if((it->second)<qnt){
                throw InvalidQntException("A quantidade de itens para ser removida é maior que a quantidade que está no carrinho");    //mensagem de erro, já que a quantidade a ser removida foi inválida
            }
            break;
        }else{
            throw InvalidCodException("Código inválido/não encontrado");
        }
    }
}