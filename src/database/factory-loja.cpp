#include "factory-loja.hpp"
#include "../class/item.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::map<unsigned, std::vector<std::pair<unsigned, unsigned>>>
    FactoryLoja::abastecimento;

FactoryLoja::FactoryLoja(){};

typedef struct newItem
{
  unsigned itemId;
  unsigned quantity;

  std::pair<unsigned, unsigned> getPair()
  {
    return std::make_pair(itemId, quantity);
  }
} newItem;

void FactoryLoja::create(const std::string &filename)
{
  std::ifstream file(filename);

  if (!file)
  {
    std::cerr << "File not found: " << filename << std::endl;
    return;
  }

  std::string line;
  while (std::getline(file, line))
  {
    std::istringstream ss(line);
    std::string field;

    newItem item;
    unsigned dia;
    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid dia field" << std::endl;
      continue;
    }

    dia = std::stoul(field, nullptr, 10);
    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid id field" << std::endl;
      continue;
    }
    item.itemId = std::stoul(field, nullptr, 10);

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid quantity field" << std::endl;
      continue;
    }

    if (field != "-")
      item.quantity = std::stoul(field, nullptr, 10);
    else
      item.quantity = 0;

    auto it = abastecimento.find(dia);
    if (it == abastecimento.end())
    {
      std::vector<std::pair<unsigned, unsigned>> _item;
      _item.push_back(item.getPair());
      this->abastecimento.insert_or_assign(dia, _item);
    }
    else
    {
      std::vector<std::pair<unsigned, unsigned>> _item = it->second;
      _item.emplace_back(item.getPair());
      this->abastecimento[dia] = _item;
    }
  }
}
