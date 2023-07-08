#ifndef FACTORY_DIA_H
#define FACTORY_DIA_H

#include "factory-item.hpp"
#include "factory-situacao.hpp"
#include "factory.hpp"
#include "../class/dia/dia.hpp"
#include "../class/situacao/situacao.hpp"

#include <map>
#include <string>
#include <vector>

class FactoryDia : public Factory<Dia>
{
public:
  std::shared_ptr<Dia> create(const std::vector<std::string> &instanceValues) override{};

  std::vector<Dia> Factory(std::string &filename);
  void populateDia(Situacao &situacao, Loja &loja);
  void addItem(const std::vector<std::string> &instanceValues);

private:
  std::map<TipoItem, std::vector<Item>> items = FactoryItem::items;
  std::map<unsigned, std::vector<Situacao>> situacoes_dias = FactorySituacao::situacoes_dias;
  std::vector<Item> itemList;
  static std::vector<Dia> dias;
  unsigned diaMax;
};

#endif
