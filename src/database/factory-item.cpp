#include "factory-item.hpp"

#include "../class/item.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<Item> FactoryItem::items;
// std::map<_Item, Item> mapItems;

TYPE_ENUM typeItemParse(std::string &type)
{
  if (type == "alimento")
  {
    return TYPE_ENUM::ALIMENTO;
  }
  else if (type == "arma")
  {
    return TYPE_ENUM::ARMA;
  }
  else if (type == "ferramenta")
  {
    return TYPE_ENUM::FERRAMENTA;
  }
  else if (type == "higiene")
  {
    return TYPE_ENUM::HIGIENE;
  }
  else if (type == "primeiros socorros")
  {
    return TYPE_ENUM::PRIMEIROS_SOCORROS;
  }
  else if (type == "entreterimento")
  {
    return TYPE_ENUM::ENTRETERIMENTO;
  }
}

void FactoryItem::create(const std::string &filename)
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

    unsigned id;
    std::string name;
    TYPE_ENUM type;
    float price;
    float sanity;
    float vitality;
    bool consumible;
    unsigned quantity;
    std::vector<std::string> options;

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid id field" << std::endl;
      continue;
    }
    id = std::stoul(field, nullptr, 10);

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid name field" << std::endl;
      continue;
    }
    name = field;

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid type field" << std::endl;
      continue;
    }

    type = typeItemParse(field);

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid price field" << std::endl;
      continue;
    }
    price = std::stof(field);

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid sanity field" << std::endl;
      continue;
    }
    auto _field = field == "-" ? "0.0" : field;
    sanity = std::stof(_field, nullptr);

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid vitality field" << std::endl;
      continue;
    }
    _field = field == "-" ? "0.0" : field;
    vitality = std::stof(_field, nullptr);

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid consumible field" << std::endl;
      continue;
    }
    consumible = std::stoi(field == "VERDADEIRO" ? "1" : "0", nullptr, 10);

    while (std::getline(ss, field, ','))
    {
      options.push_back(field);
    }

    const Item item = Item(id, name, type, price, vitality, sanity, consumible, options);

    this->items.push_back(item);
  }

  for (auto &item : this->items)
  {
    _Item _item;
    _item.id = item.id;
    _item.name = item.name;
    _item.price = item.price;
    _item.sanity = item.sanity;
    _item.vitality = item.vitality;
    _item.consumible = item.consumible;
    _item.available = false;

    Loja::shopItems.push_back(_item);

    // this->mapItems[item.id] = item;
  }
}

bool FactoryItem::operator==(const _Item &item)
{
  for (auto &i : this->items)
  {
    if (i.id != item.id)
    {
      return true;
    }
  }
  return true;
}

Item &FactoryItem::operator[](const _Item &item)
{
  unsigned itemIdx = 0;
  for (auto &i : this->items)
  {
    if (i.id != item.id)
    {
      return this->items[itemIdx];
    }
    ++itemIdx;
  }
  return this->items[0];
}
