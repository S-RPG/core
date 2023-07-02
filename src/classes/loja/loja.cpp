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

    //PRECISA SER ADICIONADO OPERAÇÃO QUE VERIFICA SE O DINHEIRO DO INVENTÁRIO É SUFICIENTE PARA O PEDIDO
    //Caso contrário, ele tem que voltar para a opção de alterar o carrinho
    //Pode ser que esssa função de remover seja feita nessa função mesmo

    std::cout<<"Total: @"<<total<<std::endl;

    _dinheiro -= total;           //como o dinheiro vai ser incluido? depois da classe inventário ser incluida isso vai ser feito
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
            //verificar se a quantidade é válida
            Loja::pedido(cod,qnt);
        } else if(opc=="rmv"){                    //remove
            std::cin>>cod>>qnt;
            Loja::removePedido(cod,qnt);
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
            //erro de opção inválida
        }
    }
    std::cout<<"Carrinho:"<<std::endl;
    Loja::mostrarCarrinho();

    char alt;                                 //alternativa
    std::cout<<"Deseja finalizar a compra?"<<"  "<<"S/N"<<std::endl;
    std::cin>>alt;

    if(alt=='S'){                             //vai para a seção de compra finalizar o pedido
        Loja::compra();
    }else if(alt=='N'){                       //encontra uma situação antes da operação ser finalizada
        std::cout<<"Alterar o carrinho (alt)"<<"   "<<"Cancelar a compra (dlt)"<<"  "<<"Finalizar (end)"<<std::endl;
        std::cin>>opc;
        if(opc=="alt"){                       //retorna ao while de edição do carrinho
            goto compra;
        } else if(opc=="dlt"){                //informa que o carrinho foi deletado para ele ser destruido direto no final do escopo da função
            //destrutor do map
        }else if(opc=="end"){                //vai para a seção de compra finalizar o pedido
            Loja::compra();
        }
    }else{
        //erro de opção inválida
    }

    //destrutor do map
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
                std::cout << "Item indisponível" << std::endl;
                return; // Saia da função, pois o item está indisponível
            }
        }
    }

    std::cout << "Código inválido" << std::endl;
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
        //retorno de erro carrinho vazio
    }

    auto it = _carrinho.begin();
    const auto& mapIn = it->first;
    for( ; it!=_carrinho.end(); it++){
        if(((mapIn.begin()->first)==cod)){
            break;
        }
    }

    //implementar a opção de se nenhuma opção apareceu, retornar erro

    if((it->second)==qnt){
        auto &name = mapIn.begin()->second;
        std::cout<<"-"<<&name<<"totalmente removido!"<<std::endl;
        _carrinho.erase(it);
    } else if((it->second)>qnt){
        auto &name = mapIn.begin()->second;
        (it->second)=(it->second)-qnt;
        std::cout<<qnt<<"  "<<&name<<"removidos com sucesso!"<<std::endl;
    } else if((it->second)<qnt){
        //mensagem de erro, já que a quantidade a ser removida foi inválida
    }
   
}