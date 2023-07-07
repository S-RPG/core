#include <iostream>
#include "personagem.hpp"

Personagem::Personagem(const std::string nome, int sanidad, int vitalidad, int mone, int fom)
    : sanidade(sanidad), vitalidade(vitalidad), dinheiro(dinheir), fome(fom) {}

void Personagem::interagirItem(const Item& item) {
    _sanidade += item.sanidade;
    _vitalidade += item.vitalidade;
    _fome += item.fome;
  
}
 if (StatusdoJogo()) { //minha ideia é : mostrar que morreu e depois o motivo, nao sei se essa estrutura vai funcionar ou nao
        std::cout << "Você perdeu" << _nome << "estava em um estado tenebroso e nao resistiu. Motivo:";
        if (_sanidade < 10 ) { //nao sei o valor ainda, coloquei qualquer valor depois a gente muda
            std::cout << "Sanidade muito baixa.++\n";
        }
        if (_vitalidade < 10) {
            std::cout << "Vitalidade baixa.\n";
        }
        if (_fome < 10) {
            std::cout << "Não comeu o necessario nos ultimos dias.\n";
        }
        
    }

void Personagem::exibirStatus() const {
    std::cout << "Sanidade: " << sanidade << ", Vitalidade: " << vitalidade <<  ", Fome: " << fome << "\n";
}

