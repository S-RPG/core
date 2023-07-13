#include "./class/personagem.hpp"
#include "./class/inventario/inventario.hpp"
#include "./class/loja/loja.hpp"
#include "./database/data.cpp"

#include <iostream>
#include <algorithm>
#include <string>

#define TEXT_LEN_MAX 100

Personagem _personagem;
Inventario inventario;
Loja *loja = new Loja();

void startGame()
{

  std::cout << "                                  🌈 BEM-VINDO AO WAR-DG 🌈\n"
            << std::endl;
  std::cout << "Após o uso de uma arma biológica por parte do governo como último recurso de controle, " << std::endl;
  std::cout << "todos os indivíduos foram alertados a ficarem em suas casas até que os efeitos mais letais  " << std::endl;
  std::cout << "de tal arma fossem dissipados na atmosfera. Entretanto, em razão das necessidades humanas  " << std::endl;
  std::cout << "básicas, o governo forneceu o acesso a uma loja do próprio governo, de modo a suprir tais  " << std::endl;
  std::cout << "necessidades, porém claro, na conta e risco de tais indivíduos. Todos os indivíduos que tivessem  " << std::endl;
  std::cout << "bankers em suas casas se abrigaram neles. Incluindo você. Assim começa este novo governo e esta " << std::endl;
  std::cout << "nova era neste país. Seu objetivo é sobreviver até que o governo em conjunto com seus aliados  " << std::endl;
  std::cout << "consigam reverter o caos instaurado.\n\n"
            << std::endl;

  std::cout << "🪪  Criação do personagem" << std::endl;
  std::cout << "👤  Nome: ";
  std::cin >> _personagem.name;

  std::string policy;

  std::cout << "⚖️  Política (⚔️ [R]esistência ou 👑 [G]overno): " << std::endl;
  std::cin >> policy;

  _personagem.policy = policy == "R" ? POLITICA_ENUM::RESISTENCIA : POLITICA_ENUM::GOVERNO;

  std::cout << "🪪 Personagem criado com sucesso" << std::endl;

  // conforme a politica escolhida definir os valores de sanidade e vitalidade

  _personagem.sanity = 60;
  _personagem.vitality = 80;
};

void menu(char &choice, unsigned &dia)
{

  char _choice;
  std::cout << "[L]oja - [I]nventário - [P]ersonagem - [D]ormir" << std::endl;
  std::cin >> _choice;

  if (_choice == 'L')
  {
    std::cout << "🛍 Bem-vindo a Loja" << std::endl;
    loja->showShopItems();
  }
  else if (_choice == 'I')
  {
    char iChoice;
    inventario.showInventary();
    std::cout << "[S]elecionar um item - [D]eixar inventário" << std::endl;
    std::cin >> iChoice;

    while (iChoice == 'S' || iChoice == 's')
    {
      unsigned itemPos;
      unsigned itemQuantity;
      std::cout << "Qual item? ";
      std::cin >> itemPos;
      std::cout << "\nQuantidade: ";
      std::cin >> itemQuantity;

      inventario.interactItem(itemPos, itemQuantity);
      std::cout << "[S]elecionar um item - [D]eixar inventário" << std::endl;
      std::cin >> iChoice;
    }
    menu(choice, dia);
  }
  else if (_choice == 'P')
  {
    std::cout << "🩺 Sobre o seu personagem" << std::endl;
    std::string politica = _personagem.policy == POLITICA_ENUM::RESISTENCIA ? "⚔️ Resistência" : "👑 Governo";
    std::cout << "Politica: " << politica << std::endl;
    std::cout << "Sanidade: " << _personagem.sanity << std::endl;
    std::cout << "Vitalidade: " << _personagem.vitality << std::endl;
  }
  else if (_choice == 'D')
  {
    std::cout << "🛌 Indo dormir..." << std::endl;
    ++dia;
    return;
  }

  menu(choice, dia);
};

void choiceImpact(char &choice, Data &data, unsigned &situacaoId)
{
  auto decisoes_it = data.decisoes[situacaoId];
  Decisao *decisao;

  for (auto &p_choice : decisoes_it)
  {
    if (p_choice.first == choice)
      decisao = &p_choice.second;
  }

  _personagem.sanity += decisao->impactoSanidade;
  _personagem.vitality += decisao->impactoVitalidade;

  std::cout << "Status do personagem" << std::endl;
  std::cout << "Vitalidade: " << decisao->impactoVitalidade << std::endl;
  std::cout << "Sanidade: " << decisao->impactoSanidade << std::endl;
}

void supplyStore(Data &data, unsigned &dia)
{
  auto newItems = data.abastecimento[dia];

  std::pair<unsigned, unsigned> agua{1, 2};
  std::pair<unsigned, unsigned> pao{5, 2};
  std::pair<unsigned, unsigned> cafe{4, 1};
  std::pair<unsigned, unsigned> cereal{8, 1};

  std::vector<std::pair<unsigned, unsigned>> suppliesDefault{agua, pao, cafe, cereal};

  for (auto &suplly : suppliesDefault)
  {
    auto loja_it = Loja::shopItems.begin();
    for (; loja_it != Loja::shopItems.end(); ++loja_it)
      if (loja_it->id == suplly.first)
      {
        std::cout << "Loja atualizada" << std::endl;
        std::cout << loja_it->name << " foi de:  " << loja_it->quantity << " unidades" << std::endl;
        loja_it->quantity += suplly.second;
        loja_it->available = true;
        std::cout << "Para: " << loja_it->quantity << " unidades" << std::endl;
      };
  }

  for (auto &_item : newItems)
  {
    bool added = false;
    _Item newItem;
    newItem.id = _item.first;
    if (_item.second > 0)
      newItem.quantity = _item.second;

    auto loja_it = Loja::shopItems.begin();

    for (; loja_it != Loja::shopItems.end(); ++loja_it)
    {
      if (loja_it->id == newItem.id)
      {

        std::cout << "Loja atualizada" << std::endl;
        std::cout << loja_it->name << " foi de:  " << loja_it->quantity << " unidades" << std::endl;
        loja_it->quantity += newItem.quantity;
        loja_it->available = true;

        std::cout << "Para: " << loja_it->quantity << " unidades" << std::endl;

        added = true;
        break;
      };
    };
  }
}

int main()
{

  Data gameData = Data::factoryData();
  unsigned dia = 1;
  supplyStore(gameData, dia);

  startGame();

  Inventario inventario;
  inventario.createInventario(_personagem, 10.5f);

  unsigned lastDay = gameData.situacoes.rbegin()->first;
  auto actualDay_it = gameData.situacoes[1].begin();
  char choice;
  std::string dayAnnouncer(TEXT_LEN_MAX / 2 - 9, ' ');

  dayAnnouncer.append("[DIA: 1]");

  std::cout
      << dayAnnouncer << std::endl;
  std::cout << actualDay_it->getTitulo(TEXT_LEN_MAX) + '\n'
            << std::endl;
  std::cout << actualDay_it->getContexto(TEXT_LEN_MAX) << std::endl;
  std::cout << actualDay_it->getDecisoes(TEXT_LEN_MAX) << std::endl;
  std::cout << "\n\n"
            << std::endl;

  std::cin >> choice;
  Decisao *decisao;
  choiceImpact(choice, gameData, actualDay_it->_id);
  ++actualDay_it;

  dia += 1;

  while (_personagem.sanity > 0 && _personagem.vitality > 0 && dia <= lastDay)
  {
    supplyStore(gameData, dia);

    if (gameData.situacoes[dia].size() > 0)
    {

      actualDay_it = gameData.situacoes[dia].begin();

      auto situacoes_it = actualDay_it;

      dayAnnouncer.clear();
      std::string dayAnnouncer(TEXT_LEN_MAX / 2 - 9, ' ');
      dayAnnouncer.append("[DIA: " + std::to_string(dia) + "]");

      std::cout << dayAnnouncer << std::endl;
      while (situacoes_it != gameData.situacoes[dia].end())
      {
        std::cout << situacoes_it->getTitulo(TEXT_LEN_MAX) + '\n'
                  << std::endl;
        std::cout << situacoes_it->getContexto(TEXT_LEN_MAX) << std::endl;
        std::cout << situacoes_it->getDecisoes(TEXT_LEN_MAX) << std::endl;
        std::cout << "\n\n"
                  << std::endl;

        std::cin >> choice;
        choiceImpact(choice, gameData, situacoes_it->_id);

        if (_personagem.sanity > 0 && _personagem.vitality > 0)
          ++situacoes_it;
        else
          break;
      };
    }
    menu(choice, dia);
  };

  std::cout << "🎉 Parabéns por sobreviver aos " << lastDay << " dias 🎉" << std::endl;
  return 0;
}
