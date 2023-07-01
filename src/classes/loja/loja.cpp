#include "loja.hpp"
#include <iostream>

//template <typename T>
void Loja::compra(){
    if(_carrinho.empty()){
        //retorno de erro carrinho vazio
    }
    auto ite = _carrinho.begin();
    double total;
    for( ; ite!=_carrinho.end(); ite++){
        total= total + ((ite->first.second.first)*(ite->second)); //retorna o nome do item e a quantidade
    }

    std::cout<<"Total: @"<<total<<std::endl;

    _dinheiro= _dinheiro - total;
}

//template <typename T>
void Loja::entrega(){
    //classe a ser pensada melhor por causa do funcionamento do programa
}

//template <typename T>
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
        }else if(opc=="esc"){                     //sai da interface
            break;
        }else {
            //erro de opção inválida
        }
        Loja::mostrarCarrinho();
    }
    std::cout<<"Carrinho:"<<std::endl;
    std::cout<<Loja::mostrarCarrinho();

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

//template <typename T>
void Loja::pedido(unsigned cod, unsigned qnt){  
    auto it = _itens.begin();

    for( ; it!=_itens.end(); it++){
        if((it->first==cod)){
            break;
        }
    }

    //implementar a opção de se nenhuma opção apareceu, retornar erro

    _carrinho.insert(it,qnt);
}

//template <typename T>
void Loja::mostrarCarrinho(){
    if(_carrinho.empty()){
        //retorno de erro carrinho vazio
    }
    auto it = _carrinho.begin();

    for( ; it!=_carrinho.end(); it++){
        std::cout<<(it->first->second.second)<<" - "<<(it->second)<<std::endl; //retorna o nome do item e a quantidade
    }
}

//template <typename T>
void Loja::mostrarItens(){
    auto it = _itens.begin();

    for( ; it!=_itens.end(); it++){
        std::cout<<(it->first)<<" - "<<(it->second.second)<<" - @"<<(it->second.first)<<std::endl;
    }
}

//template <typename T>
void Loja::removePedido(unsigned cod, unsigned qnt){
    if(_carrinho.empty()){
        //retorno de erro carrinho vazio
    }

    auto it = _carrinho.begin();

    for( ; it!=_carrinho.end(); it++){
        if(((it->first.first)==cod)){
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