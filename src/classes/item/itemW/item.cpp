#include "item.hpp"

Item::Item(const std::string& nome, TipoItem tipo, bool consumivel, bool utilitario, int preco, int numUtilizacoes)
    : nome(nome), tipo(tipo), consumivel(consumivel), utilitario(utilitario), preco(preco), numUtilizacoes(numUtilizacoes) {}

TipoItem Item::getTipo() const {
    return tipo;
}

bool Item::isConsumivel() const {
    return consumivel;
}

bool Item::isUtilitario() const {
    return utilitario;
}

int Item::getPreco() const {
    return preco;
}

int Item::getNumUtilizacoes() const {
    return numUtilizacoes;
}

void Item::incrementarUtilizacao() {
    numUtilizacoes++;
}

