#ifndef DIA_H
#define DIA_H

#include "../item/item.hpp"
#include "../loja/loja.hpp"
#include "../menu/menu.hpp"
#include "../situacao/situacao.hpp"

#include <string>
#include <vector>

class Dia : public Menu
{
public:
  unsigned dia;
  std::vector<Situacao> situacoes;
  std::vector<Item> newItemsByDay;

  Dia(unsigned dia, std::vector<Situacao> situacoes, std::vector<Item> newItemsByDay);

  void updateLoja(Loja &loja);
  void showMenu(std::size_t maxLen) override;
  char getChoice() override;
};

#endif
