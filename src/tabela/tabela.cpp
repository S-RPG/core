#include <iostream>
#include <map>
#include <string>
#include <iomanip>

int main() {
    std::map<unsigned, std::string> lista = {{1, "pão"}, {2, "lambreta"}, {3, "maçarico"}};

    std::cout << "--------------------------------------" << std::endl;

    size_t maxIdLength = 0;
    size_t maxItemLength = 0;

    // Encontra o tamanho máximo do id e do item
    for (const auto& entry : lista) {
        maxIdLength = std::max(maxIdLength, std::to_string(entry.first).length());
        maxItemLength = std::max(maxItemLength, entry.second.length());
    }

    // Calcula o tamanho total do cabeçalho
    size_t totalHeaderLength = maxIdLength + maxItemLength + 8;

    // Imprime o cabeçalho
    std::cout << "|" << std::setw(totalHeaderLength / 2 + totalHeaderLength % 2) << "id";
    std::cout << std::setw(totalHeaderLength / 2) << "|";
    std::cout << std::setw(totalHeaderLength / 2 + totalHeaderLength % 2) << "item";
    std::cout << std::setw(totalHeaderLength / 2) << "|" << std::endl;

    // Imprime as linhas com itens e IDs centralizados
    for (const auto& entry : lista) {
        std::cout << "|" << std::setw(totalHeaderLength / 2 + maxIdLength % 2) << std::right << entry.first;
        std::cout << std::setw(totalHeaderLength / 2) << "|";
        std::cout << std::setw(totalHeaderLength / 2 + maxItemLength % 2) << std::left << entry.second;
        std::cout << std::setw(totalHeaderLength / 2) << "|" << std::endl;
    }
    
    std::cout << "--------------------------------------" << std::endl;

    return 0;
}
