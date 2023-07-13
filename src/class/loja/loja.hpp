#ifndef LOJA_H
#define LOJA_H

#include "../item.hpp"
#include "../inventario/inventario.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <utility>
#include <string>
#include <exception>
#include <iomanip>

class Loja
{
public:
  Loja();

  bool buy();

  void delivery();

  void addItemToCart(_Item &item, unsigned itemQuantity);

  void removeItemFromCart(unsigned itemPos, unsigned itemQuantity);

  void showItems();

  void showCart();

  void showShopItems();

  static std::list<_Item> shopItems;

private:
  std::list<_Item>
      cart;
  Inventario inventario;
};

#endif
