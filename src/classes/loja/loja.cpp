#include "loja.hpp"
#include <iostream>


void Loja::compra(){
    if(_carrinho.empty()){
        //retorno de erro carrinho vazio
    }
    
    auto it = _carrinho.begin();
    double total = 0.0;

    for (; it != _carrinho.end(); it++) {
        const auto& mapIn = it->first;
        total += (mapIn.begin()->second.first) * (it->second);
    }

    std::cout<<"Total: @"<<total<<std::endl;

    _dinheiro= _dinheiro - total;
}


void Loja::entrega(){
    //classe a ser pensada melhor por causa do funcionamento do programa
}


void Loja::interface(){
    Loja::mostrarItens();

    std::string opc;                            //opção
    unsigned cod=0;                             //código
    unsigned qnt=0;                             //quantidade
    while(opc!="esc"){
        std::cin>>opc;
        if(opc=="add"){                           //adiciona
            std::cin>>cod>>qnt;
            Loja::pedido(cod,qnt);
        } else if(opc=="rmv"){                    //remove
            std::cin>>cod>>qnt;
            Loja::removePedido(cod,qnt);
        }else if(opc=="show"){
            Loja::mostrarCarrinho();
        }else if(opc=="esc"){                     //sai da interface
            break;
        }else {
            //erro de opção inválida
        }
    }
    std::cout<<"Carrinho:"<<std::endl;
    Loja::mostrarCarrinho();

    char alt;                                   //alternativa
    std::cout<<"Deseja finalizar a compra?"<<"  "<<"S/N"<<std::endl;
    std::cin>>alt;

    if(alt=='S'){
        Loja::compra();
    }else if(alt=='N'){
        //voltar para a escolha
    }else{
        //erro de opção inválida
    }
}


void Loja::pedido(unsigned cod, unsigned qnt) {
    //std::map<unsigned, std::pair<double, std::string>> chaveItem = _itens; // Copia o mapa de itens

    auto it = _itens.find(cod); // Procura o item pelo código

    if (it != _itens.end()) {
        // Insere o item no carrinho junto com a quantidade
        _carrinho.emplace(it, qnt);
    } else {
        // Implemente a ação para o caso de código de item inválido
        // return; // ou outro tratamento de erro
    }
}


void Loja::mostrarCarrinho(){
    if(_carrinho.empty()){
        //retorno de erro carrinho vazio
    }
    auto it = _carrinho.begin();

    for( ; it!=_carrinho.end(); it++){
        const auto& mapIn = it->first;
        std::cout<<(mapIn.begin()->second.second)<<" - "<<(it->second)<<std::endl; //retorna o nome do item e a quantidade
    }
}


void Loja::mostrarItens(){
    auto it = _itens.begin();

    for( ; it!=_itens.end(); it++){
        std::cout<<(it->first)<<" - "<<(it->second.second)<<" - @"<<(it->second.first)<<std::endl;
    }
}


void Loja::removePedido(unsigned cod, unsigned qnt){
    if(_carrinho.empty()){
        //retorno de erro carrinho vazio
    }

    auto it = _carrinho.begin();

    for( ; it!=_carrinho.end(); it++){
        const auto& mapIn = it->first;
        if(((mapIn.begin()->first)==cod)){
            break;
        }
    }

    //implementar a opção de se nenhuma opção apareceu, retornar erro

    if((it->second)==qnt){
        _carrinho.erase(it);
    } else if((it->second)>qnt){
        (it->second)=(it->second)-qnt;
    } else if((it->second)<qnt){
        //mensagem de erro, já que a quantidade a ser removida foi inválida
    }
   
}