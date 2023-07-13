// compile with: /EHsc
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "../item.hpp"
#include "../personagem.hpp"

#include <string>
#include <map>
#include <list>

class Inventario
{
public:
  Inventario();

  void createInventario(Personagem &personagem, float money);

  // void addItem(Item &item);
  void addItem(_Item &item);

  void removeItem(unsigned itemPos, unsigned itemQuantity);
  void removeItem(Item &item, unsigned itemQuantity);

  bool interactItem(unsigned itemPos, unsigned itemQuantity);

  bool interactions(OPTIONS_ENUM &option, Item &item);

  std::string showInventary();

  friend class Loja;

private:
  std::list<Item> itemList;
  static float money;
  Personagem *personagem;
};

#endif
