#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class TipoItem {
    ALIMENTO,
    ARMA,
    ENTRETENIMENTO,
    FERRAMENTA,
    HIGIENE,
    PRIMEIROS_SOCORROS
};

struct Item {

    std::string nome;
    TipoItem tipo;
    bool consumivel;
    float preco;
    double vitalidade;
    unsigned sanidade;
    unsigned quantidade;
    unsigned id;
    
};

#endif