#include "loja.hpp"
#include <iostream>

void Loja<void>::mostrarItens(){
    auto it = _itens.begin();

    for( ; it!=_itens.end(); it++){
        std::cout<<(it->first)<<" - "<<(it->second.second)<<" - @"<<(it->second.first)<<std::endl;
    }
}