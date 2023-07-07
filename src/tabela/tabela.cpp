#include <iostream>
#include <iomanip>
#include <map>

struct Item {
    std::string nome;
    double preco;
    int quantidade;
};

void printTable(std::map<unsigned,Item>& _itens) {

    std::size_t nomeTextLenMax = 0;

    for (auto it=_itens.begin(); it!=_itens.end(); it++){
        std::size_t nomeTextLen = it->second.nome.size();
        if (nomeTextLenMax < nomeTextLen){
            nomeTextLenMax = nomeTextLen;
        }
    }

    std::string cabeca = "Item";
    std::size_t cabecaTextLen = cabeca.size()/3;
    std::size_t tab = nomeTextLenMax + cabecaTextLen;
    
    std::string linhaHoriz = "";

    std::size_t totalSize = 5 + 11 + tab + 8 + 11 + 7;
    linhaHoriz.append(totalSize, '-');

    std::cout << linhaHoriz << std::endl;
    std::cout << std::left << std::setw(5) << "ID"
          << " | " << std::setw(tab) << cabeca
          << " | " << std::setw(8) << "Preço"
          << " | " << std::setw(11) << "Quantidade" 
          << " | " << std::setw(7) << "Total"<< std::endl;
    std::cout << linhaHoriz << std::endl;

    double total = 0.0;
    for(auto it = _itens.begin(); it!=_itens.end(); it++){
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
    
    std::cout<<"Total do carrinho: @"<<total<<std::endl;
}

int main() {
    std::map<unsigned,Item> itens = {
        {1, { "Item 1", 10.0, 5 }},
        {2, { "Itenzao fodinha", 15.0, 3}},
        {3, { "Item 3", 20.0, 7 }},
        {4, { "Item 4", 12.0, 2 }},
        {5,{"PUTA QUE PARIU A", 23.0, 1}},
        {6,{"CARAIO A QUATRO DE ASA", 666.0, 1}}
    };

    printTable(itens);

    return 0;
}
