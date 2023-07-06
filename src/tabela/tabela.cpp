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

void printTable(const std::map<unsigned, std::pair<Item, bool>>& items) {
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(5) << "ID"
              << " | " << std::setw(16) << "Nome"
              << " | " << std::setw(8) << "Preço"
              << " | " << std::setw(11) << "Quantidade" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for (const auto& entry : items) {
        const auto& id = entry.first;
        const auto& item = entry.second.first;
        const auto& disponivel = entry.second.second;

        if (disponivel) {
            std::cout << std::left << std::setw(5) << id
                      << " | " << std::setw(16) << item.nome
                      << " | @" << std::setw(6) << std::fixed << std::setprecision(2) << item.preco
                      << " | " << std::setw(11) << item.quantidade << std::endl;
        }
    }

    std::cout << "--------------------------------------------------" << std::endl;
}

int main() {
    std::map<unsigned, std::pair<Item, bool>> items = {
        {1, {{ "Item 1", 10.0, 5 }, true}},
        {2, {{ "Itenzão foda ", 15.0, 3 }, true}},
        {3, {{ "Item 3", 20.0, 7 }, false}},
        {4, {{ "Item 4", 12.0, 2 }, true}}
    };

    printTable(items);

    return 0;
}
