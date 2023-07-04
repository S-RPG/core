#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

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
    float vitalidade;
    unsigned sanidade;
    float preco;
    int numUtilizacoes;
};

#endif