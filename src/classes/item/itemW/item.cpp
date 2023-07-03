// item.cpp
#include "item.hpp"
//#include "personagem.hpp" // Inclua o arquivo de cabeçalho da classe Personagem aqui, caso exista

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

/*
void Item::utilizarItem(Personagem& personagem) {
    // Implemente a l�gica de intera��o do item com o personagem aqui, com base no n�mero de utiliza��es e nos valores padr�o de vitalidade e sanidade
}

void Item::utilizarItem(Personagem& personagem, int valorVitalidade, int valorSanidade) {
    // Implemente a l�gica de intera��o do item com o personagem aqui, com base nos valores personalizados de vitalidade e sanidade
}

void Item::exibirInfo() const {
    std::cout << nome << ": (V: " << int percentualVitalidade << "%, S: " << int valorSanidade << ")" << std::endl;
}
*/