#ifndef F_ITEM_H
#define F_ITEM_H

#include "factory.hpp"
#include "../class/item.hpp"
#include "../class/inventario/inventario.hpp"
#include "factory-loja.hpp"
#include "../class/loja/loja.hpp"

#include <string>
#include <vector>

class FactoryItem : public IFactory<const std::string &>
{
public:
  void create(const std::string &filename) override;

  friend class Inventario;

  static std::vector<Item> items;
  // static std::map<unsigned, Item> mapItems;

  bool operator==(const _Item &item);
  Item &operator[](const _Item &item);
};

#endif
