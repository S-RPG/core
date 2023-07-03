// item.hpp
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

//class Personagem; // Declara��o antecipada da classe Personagem
//class Loja; //Declara��o antecipada da classe Loja

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
    //void utilizarItem(Personagem& personagem);
    //void utilizarItem(Personagem& personagem, int valorVitalidade, int valorSanidade);
    void exibirInfo() const;

private:
    std::string nome;
    TipoItem tipo;
    bool consumivel;
    bool utilitario;
    int preco;
    int numUtilizacoes;
};

#endif
