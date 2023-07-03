#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

enum class TipoItem {
    ALIMENTO,
    ENTRETENIMENTO,
    ARMA,
    PRIMEIROS_SOCORROS,
    HIGIENE
};

class Item {
public:
    Item(const std::string& nome, TipoItem tipo, bool consumivel, bool utilitario, int preco, int numUtilizacoes);
    TipoItem getTipo() const;
    bool isConsumivel() const;
    bool isUtilitario() const;
    int getPreco() const;
    int getNumUtilizacoes() const;
    void incrementarUtilizacao();
    void exibirInfo() const; 
    //exibir as informações do item, incluindo o percentual de vitalidade e o valor de sanidade no formato (V: ; S:)

private:
    std::string nome;
    TipoItem tipo;
    bool consumivel;
    bool utilitario;
    int preco;
    int numUtilizacoes;
};

#endif
