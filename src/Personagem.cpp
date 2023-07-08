#include <iostream>
#include "personagem.hpp"

Personagem::Personagem(const std::string nome, int sanidad, int vitalidad, int mone, int fom)
    : sanidade(sanidad), vitalidade(vitalidad), dinheiro(dinheir), fome(fom) {}

void Personagem::interagirItem(const Item& item) {
    _sanidade += item.sanidade;
    _vitalidade += item.vitalidade;
    _fome += item.fome;
  
}

void Personagem::exibirStatus() const {
    std::cout << "Sanidade: " << sanidade << ", Vitalidade: " << vitalidade <<  ", Fome: " << fome << "\n";
}

