#ifndef FACTORY_ITEM_H
#define FACTORY_ITEM_H

#include "./factory.hpp"
#include "../class/item/item.hpp"

#include <map>
#include <string>
#include <vector>
#include <memory>

class FactoryItem : public Factory<Item>
{
public:
  FactoryItem(std::string &_file);
  FactoryItem() = delete;
  FactoryItem(const FactoryItem &) = delete;
  FactoryItem(FactoryItem &&) = default;

  // ~FactoryItem();

  Item create(const std::vector<std::string> &instanceValues) override;

  // std::map<TipoItem, std::vector<Item>> Factory(std::string &filename);
  void Factory(std::string &filename);
  void populateItems(Item &item);

  friend class FactoryDia;
  std::map<TipoItem, std::vector<Item>> items;

private:
  std::string file;
};

#endif
