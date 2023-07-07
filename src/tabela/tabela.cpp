// #include <iostream>
// #include <map>
// #include <string>
// #include <iomanip>

// int main() {
//     std::map<unsigned, std::string> lista = {{1, "pão"}, {2, "lambreta"}, {3, "maçarico"}};

//     std::cout << "--------------------------------------" << std::endl;

//     size_t maxIdLength = 0;
//     size_t maxItemLength = 0;

//     // Encontra o tamanho máximo do id e do item
//     for (const auto& entry : lista) {
//         maxIdLength = std::max(maxIdLength, std::to_string(entry.first).length());
//         maxItemLength = std::max(maxItemLength, entry.second.length());
//     }

//     // Calcula o tamanho total do cabeçalho
//     size_t totalHeaderLength = maxIdLength + maxItemLength + 8;

//     // Imprime o cabeçalho
//     std::cout << "|" << std::setw(totalHeaderLength / 2 + totalHeaderLength % 2) << "id";
//     std::cout << std::setw(totalHeaderLength / 2) << "|";
//     std::cout << std::setw(totalHeaderLength / 2 + totalHeaderLength % 2) << "item";
//     std::cout << std::setw(totalHeaderLength / 2) << "|" << std::endl;

//     // Imprime as linhas com itens e IDs centralizados
//     for (const auto& entry : lista) {
//         std::cout << "|" << std::setw(totalHeaderLength / 2 + maxIdLength % 2) << std::right << entry.first;
//         std::cout << std::setw(totalHeaderLength / 2) << "|";
//         std::cout << std::setw(totalHeaderLength / 2 + maxItemLength % 2) << std::left << entry.second;
//         std::cout << std::setw(totalHeaderLength / 2) << "|" << std::endl;
//     }
    
//     std::cout << "--------------------------------------" << std::endl;

//     return 0;
// }

#include <iostream>
#include <iomanip>
#include <map>

struct Item {
    std::string nome;
    double preco;
    int quantidade;
};

void printTable(const std::map<unsigned, std::pair<Item, bool>>& itens) {
    std::string itemStr;
    std::size_t nomeTextLenMax = 0;

    for (auto it=itens.begin(); it!=itens.end(); it++){
        std::size_t nomeTextLen = it->second.first.nome.size();
        if (nomeTextLenMax < nomeTextLen){
            nomeTextLenMax = nomeTextLen;
        }
    }

    std::string cabeca = "Nome";
    std::size_t cabecaTextLen = cabeca.size()/3;
    std::size_t tab = nomeTextLenMax + cabecaTextLen;
    
     std::string linhaHoriz = "";

    std::size_t totalSize = 5 + 6 + tab + 10 + 11;
    linhaHoriz.append(totalSize, '-');

    std::cout << linhaHoriz << std::endl;
    std::cout << std::left << std::setw(5) << "ID"
          << " | " << std::setw(tab) << "Nome"
          << " | " << std::setw(8) << "Preço"
          << " | " << std::setw(11) << "Quantidade" << std::endl;
    std::cout << linhaHoriz << std::endl;

    for (auto it=itens.begin(); it!=itens.end(); it++) {
        const auto& id = it->first;
        const auto& item = it->second.first;
        const auto& disponivel = it->second.second;

        if (disponivel) {
            std::size_t nomeTextLen = nomeTextLenMax;
            std::cout << std::left << std::setw(5) << id
                      << " | " << std::setw(tab) << item.nome
                      << " | @" << std::setw(6) << std::fixed << std::setprecision(2) << item.preco
                      << " | " << std::setw(11) << item.quantidade << std::endl;

        }
    }

    std::cout << linhaHoriz << std::endl;
}

int main() {
    std::map<unsigned, std::pair<Item, bool>> itens = {
        {1, {{ "Item 1", 10.0, 5 }, true}},
        {2, {{ "Itenzao fodinha", 15.0, 3 }, false}},
        {3, {{ "Item 3", 20.0, 7 }, true}},
        {4, {{ "Item 4", 12.0, 2 }, true}},
        {5,{{"PUTA QUE PARIU A", 23.0, 1},false}},
        {6,{{"CARAIO A QUATRO DE ASA", 666.0, 1},false}}
    };

    printTable(itens);

    return 0;
}
