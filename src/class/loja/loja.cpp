#include "loja.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

std::list<_Item> Loja::shopItems;

Loja::Loja(){};

void Loja::addItemToCart(_Item &item, unsigned itemQuantity = 0)
{
  _Item newItem;

  newItem.id = item.id;
  newItem.name = item.name;
  newItem.price = item.price;
  if (itemQuantity > 0)
  {
    newItem.quantity = itemQuantity;
  }

  auto it = std::find(this->cart.begin(), this->cart.end(), newItem);

  if (it != this->cart.end() && newItem.consumible)
  {
    std::cout << "->>>>> QUANTIDADE: " << it->quantity << std::endl;
    it->quantity += itemQuantity;
    std::cout << "->>>>> QUANTIDADE: " << it->quantity << std::endl;

    return;
  }
  else
  {

    this->cart.push_back(newItem);
  }

  // auto it = this->cart.begin();

  // while (it != this->cart.end())
  // {
  //   if (it->id == item.id)
  //   {
  //     it->quantity += itemQuantity;
  //     return;
  //   }
  //   ++it;
  // }
}

void Loja::removeItemFromCart(unsigned itemPos, unsigned itemQuantity)
{

  // TODO: error, cannot remove an item that is not in the cart
  if (itemPos > this->cart.size())
  {
    return;
  }
  auto it = this->cart.begin();

  std::advance(it, itemPos - 1);

  if (!it->consumible || it->quantity - itemQuantity == 0)
  {
    this->cart.erase(it);
    return;
  }

  if (it->quantity - itemQuantity > 0)
  {
    it->quantity -= itemQuantity;
    return;
  }

  // TODO: error, cannot remove more than available
  // if (it->quantity - itemQuantity < 0)
}

void Loja::delivery()
{
  for (auto it = this->cart.begin(); it != this->cart.end(); ++it)
  {
    this->inventario.addItem(*it);
  }
  this->cart.clear();
}

bool Loja::buy()
{
  if (this->cart.size() == 0)
    return false;

  float cartPrice = 0.0f;

  for (auto it = this->cart.begin(); it != this->cart.end(); ++it)
  {
    cartPrice += it->price;
  }

  if (Inventario::money < cartPrice)
  {
    std::cout << "💳 Você não tem dinheiro suficiente 🚫" << std::endl;
    std::cout << "🏦 Seu saldo atual é: R$ " << Inventario::money << std::endl;
    return false;
  }

  Inventario::money -= cartPrice;
  delivery();

  return true;
}

void Loja::showItems()
{
  auto it = Loja::shopItems.begin(); // copia o map de itens
  // const auto& mapIn = Loja::shopItems.begin()->first;      //separa a primeira parte do map de itens, já que é outro map

  std::size_t nomeTextLenMax = 0;

  for (auto it = Loja::shopItems.begin(); it != Loja::shopItems.end(); it++)
  {
    std::size_t nomeTextLen = it->name.size();
    if (nomeTextLenMax < nomeTextLen)
    {
      nomeTextLenMax = nomeTextLen;
    }
  }

  std::string cabeca = "Item";
  std::size_t cabecaTextLen = cabeca.size() / 3;
  std::size_t tab = nomeTextLenMax + cabecaTextLen;

  std::string linhaHoriz = "";

  std::size_t totalSize = 5 + 6 + tab + 10 + 11;
  linhaHoriz.append(totalSize, '-');

  std::cout << linhaHoriz << std::endl;
  std::cout << std::left << std::setw(5) << "ID"
            << " | " << std::setw(tab) << cabeca
            << " | " << std::setw(8) << "Preço"
            << " | " << std::setw(11) << "Quantidade" << std::endl;
  std::cout << linhaHoriz << std::endl;

  unsigned id = 1;
  for (auto it = Loja::shopItems.begin(); it != Loja::shopItems.end(); it++)
  {
    const auto &item = it;
    const auto &disponivel = it->available;

    if (disponivel)
    {

      std::cout << std::left << std::setw(5) << id
                << " | " << std::setw(tab) << item->name
                << " | R$ " << std::setw(6) << std::fixed << std::setprecision(2) << item->price
                << " | " << std::setw(11) << item->quantity << std::endl;
    }
    ++id;
  }

  std::cout << linhaHoriz << std::endl;
}

char menu()
{
  std::cout << "[A]dicionar items ao carrinho - [R]emover items do carrinho - [M]ostrar carrinho - [S]air" << std::endl;
  return std::cin.get();
}

void Loja::showCart()
{
  if (this->cart.empty())
  {
    // throw InvalidCarException("Nada para mostrar, o"); // retorno de erro carrinho vazio
    std::cout << "🛒 Seu carrinho ainda está vazio..." << std::endl;
    return;
  }

  std::size_t nomeTextLenMax = 0;

  for (auto it = this->cart.begin(); it != this->cart.end(); it++)
  {
    std::size_t nomeTextLen = it->name.size();
    if (nomeTextLenMax < nomeTextLen)
    {
      nomeTextLenMax = nomeTextLen;
    }
  }

  std::string cabeca = "Item";
  std::size_t cabecaTextLen = cabeca.size() / 3;
  std::size_t tab = nomeTextLenMax + cabecaTextLen;

  std::string linhaHoriz = "";

  std::size_t totalSize = 5 + 11 + tab + 8 + 11 + 7;
  linhaHoriz.append(totalSize, '-');

  std::cout << linhaHoriz << std::endl;
  std::cout << std::left << std::setw(5) << "ID"
            << " | " << std::setw(tab) << cabeca
            << " | " << std::setw(8) << "Preço"
            << " | " << std::setw(11) << "Quantidade"
            << " | " << std::setw(7) << "Total" << std::endl;
  std::cout << linhaHoriz << std::endl;

  double total = 0.0;

  unsigned posItem = 0;
  for (auto it = this->cart.begin(); it != this->cart.end(); it++)
  {
    ++posItem;

    float valor = (it->price) * (it->quantity); // calcula o valor total de cada item e sua quantidade

    std::cout << std::left << std::setw(5) << posItem
              << " | " << std::setw(tab) << it->name
              << " | R$ " << std::setw(6) << std::fixed << std::setprecision(2) << it->price
              << " | " << std::setw(11) << it->quantity
              << " | " << std::setw(7) << valor << std::endl;

    total += valor; // calcula o total do carrinho
  }
  std::cout << linhaHoriz << std::endl;

  std::cout << "Total do carrinho: R$ " << total << std::endl;
}

void Loja::showShopItems()
{
  Loja::showItems();

  char opc = menu();

  unsigned posItem = 0; // código
  unsigned qnt = 0;     // quantidade

compra: // referência para o goto
  while (opc != 's' && opc != 'S')
  {
    std::cin >> opc;
    if (opc == 'a' || opc == 'A')
    { // adiciona
      std::cout << "Item: ";
      std::cin >> posItem;
      auto it = Loja::shopItems.begin();

      for (auto i = 0; i < posItem - 1; i++)
      {
        ++it;
      }

      if (it->quantity > 0)
      {
        std::cout << "\nQuantidade: ";
        std::cin >> qnt;
      }

      // if (qnt > 0)
      // { // verificar se a quantidade é válida
      //   Loja::pedido(posItem, qnt);
      // }
      // else
      // {
      //   throw InvalidQntException("A quantidade de itens deve ser maior que 0");
      // }

      this->addItemToCart(*it, qnt);
    }
    else if (opc == 'r' || opc == 'R')
    { // remove
      std::cout << "Item: ";
      std::cin >> posItem;
      auto it = cart.begin();

      for (auto i = 0; i < posItem - 1; i++)
      {
        ++it;
      }

      if (it->quantity > 0)
      {
        std::cout << "\nQuantidade: ";
        std::cin >> qnt;
      }

      this->removeItemFromCart(posItem, qnt);
    }
    else if (opc == 'm' || opc == 'M')
    {
      this->showCart();
    }
    else if (opc == 's' || opc == 'S')
    {
      opc = menu();
    }
    else
    {
      std::cout << "Opção inválida" << std::endl;
      // throw InvalidOptionException(); // erro de opção inválida
    }
    opc = menu();
  }

  std::cout << "🛒 Seu carrinho de compras: " << std::endl;
  this->showCart();

  bool erro = true;
  bool erro2 = true;

  while (erro)
  {
    char alt; // alternativa
    std::cout << "Deseja finalizar a compra [S/N]?";
    std::cin >> alt;

    switch (alt)
    {
    case 'S':
    case 's':
      erro = !(this->buy());
      break;

    case 'N':
    case 'n':
      while (erro2)
      {
        std::cout << "Deseja limpar o carrinho [S/N]? ";
        std::cin >> opc;
        if (opc == 'N' || opc == 'n')
        { // retorna ao while de edição do carrinho
          erro2 = false;
          opc = menu();
          goto compra;
        }
        else if (opc == 'S' || opc == 's')
        { // informa que o carrinho foi deletado para ele ser destruido direto no final do escopo da função
          erro2 = false;
        }
        // else
        // {
        //   throw InvalidOptionException();
        // }
      }
      break;

    default:
      // throw InvalidOptionException(); // erro de opção inválida
      break;
    }
  }

  this->cart.clear(); // destrutor do map
}
