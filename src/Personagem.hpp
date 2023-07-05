#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <vector>
#include "item.hpp"
#include "inventario.hpp"

class Personagem {
private:
     std::string _nome;
    int _sanidade;
    int _vitalidade;
    int _dinheiro;
    int _fome;
    Inventario inventario;

public:
    Personagem(const std::string nome, int sanidad, int vitalidad, int dinheir, int fom); //basicamente o personagem recebendo seus parametros iniciais

    void interagirItem(const Item& item); //metodo que faz com que o personagem interaja com os itens

    void exibirStatus() const; //status seria san,vit,fom

    bool StatusdoJogo //status do jogo basicamente é uma verificação se ainda da pra jogar ou nao, sera utilizado por exemplo se o personagem morrer

    
};

#endif  //termina o ifndef
