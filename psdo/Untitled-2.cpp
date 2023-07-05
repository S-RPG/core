#include <iostream>
#include <string>

class Personagem {
private:
    double sanidade;
    double vitalidade;
    std::string _nome;
    int politicaId;
    int sanidadeMax;
    int vitalidadeMax;

public:
    Personagem(std::string nome, int sanidadeMax, int vitalidadeMax) {
        sanidadeMax = sanidadeMax;
        vitalidadeMax = vitalidadeMax;
        sanidade = sanidadeMax;
        vitalidade = vitalidadeMax;
        nome = nome;
    }

    void adicionarItem(Item item) {
        std::cout << "Item coletado." << std::endl;
    }

    void setFome(int valorFome) {
        fome = valorFome;
    }

    int getFome() {
        return fome;
    }

    void setSanidade(int valorSanidade) {
        sanidade = valorSanidade;
    }

    int getSanidade() {
        return sanidade;
    }
};

int main() {
    Personagem personagem("Nome", 100, 100);
    personagem.adicionarItem(item);
    personagem.setFome(100);
    int fome = personagem.getFome();
    personagem.setSanidade(100);
    int sanidade = personagem.getSanidade();

    return 0;
}
