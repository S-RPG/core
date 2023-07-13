#include "inventario.hpp"
#include "../personagem.hpp"
#include "../../database/factory-item.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

float Inventario::money = 0.0f;

Inventario::Inventario(){};

void Inventario::createInventario(Personagem &personagem, float money)
{
  this->personagem = &personagem;
  this->money = money;
}

// void Inventario::addItem(Item &item)
// {
//   bool itemAdded = false;
//   if (this->itemList.empty())
//   {
//     this->itemList.push_back(item);
//     itemAdded = true;
//     return;
//   }
//   else
//   {
//     auto it = this->itemList.begin();

//     while (it != this->itemList.end())
//     {
//       if (it->id == item.id)
//       {
//         it->quantity += item.quantity;
//         itemAdded = true;
//         return;
//       }
//       ++it;
//     }
//   }

//   if (!itemAdded)
//   {
//     this->itemList.push_back(item);
//     return;
//   }
// };

void Inventario::addItem(_Item &item)
{
  Item newItem;
  auto iit = FactoryItem::items.begin();

  for (; iit != FactoryItem::items.end(); ++iit)
  {
    if (iit->id == item.id)
    {
      newItem = *iit;
      return;
    }
  }

  if (newItem.consumible)
  {
    newItem.quantity = item.quantity;
  }

  bool itemAdded = false;
  if (this->itemList.empty())
  {
    this->itemList.push_back(newItem);
    itemAdded = true;
    return;
  }
  else
  {
    auto it = this->itemList.begin();

    while (it != this->itemList.end())
    {
      if (it->id == newItem.id)
      {
        it->quantity += newItem.quantity;
        itemAdded = true;
        return;
      }
      ++it;
    }
  }

  if (!itemAdded)
  {
    this->itemList.push_back(newItem);
    return;
  }
};

void Inventario::removeItem(unsigned itemPos, unsigned itemQuantity)
{
  auto it = this->itemList.begin();
  for (unsigned i = 0; i < itemPos; ++i)
    ++it;
  if (!it->consumible || it->quantity - itemQuantity == 0)
  {
    this->itemList.erase(it);
    return;
  }

  if (it->quantity - itemQuantity > 0)
  {
    it->quantity -= itemQuantity;
    return;
  }

  // TODO: error, cannot remove more than available
  // if (it->quantity - itemQuantity < 0)

  return;
};

void Inventario::removeItem(Item &item, unsigned itemQuantity = 1)
{

  if (!item.consumible || item.quantity - itemQuantity == 0)
  {
    Item *_item = new Item(item);
    auto itemFound = std::find(this->itemList.begin(), this->itemList.end(), *_item);
    this->itemList.erase(itemFound);
    return;
  }

  if (item.quantity - itemQuantity > 0)
  {
    item.quantity -= itemQuantity;
    return;
  }

  // TODO: error, cannot remove more than available
  // if (it->quantity - itemQuantity < 0)

  return;
};

OPTIONS_ENUM optionsEnum(std::string &s)
{
  if (s == "usar")
    return USAR;

  if (s == "consumir")
    return CONSUMIR;

  if (s == "remover")
    return REMOVER;

  if (s == "beber")
    return BEBER;

  if (s == "comer")
    return COMER;

  if (s == "assistir")
    return ASSISTIR;

  if (s == "jogar")
    return JOGAR;

  if (s == "ler")
    return LER;

  if (s == "fumar")
    return FUMAR;
};

std::string emojiMap(std::string &s)
{
  if (s == "beber")
  {
    return "🥛";
  }
  if (s == "comer")
  {
    return "🍕";
  }
  if (s == "assistir")
  {
    return "📺";
  }
  if (s == "jogar")
  {
    return "🎮";
  }
  if (s == "ler")
  {
    return "📖";
  }
  if (s == "fumar")
  {
    return "🚬";
  }
  if (s == "remover")
  {
    return "🗑️";
  }
  if (s == "usar")
  {
    return "⚙️";
  }
  return "🔹";
}

unsigned showIteractions(Item &item)
{
  unsigned choice;
  unsigned option = 1;
  for (auto it = item.options.begin(); it != item.options.end(); ++it)
  {
    std::cout << option << " - " << emojiMap(*it) << *it << std::endl;
    ++option;
  }

  std::cin >> choice;

  return choice;
};

void deadBySanityMSG()
{
  std::cout << "                       ☠ Você morreu ☠                   " << std::endl;
  std::cout << "🫨  Você perdeu toda a sanidade que ainda lhe restava  🫨" << std::endl;
  std::cout << "    Mesmo lutando pela sua sobrevivencia, você não se    " << std::endl;
  std::cout << "    enxergava mais vivendo naquilo que se tornou o mundo." << std::endl;
  std::cout << "    Bla Bla Bla..." << std::endl;
}

void deadByVitalityMSG()
{
  std::cout << "                       ☠ Você morreu ☠                   " << std::endl;
  std::cout << "🩸        Você não resistiu a sua sobrevivência.       🩸" << std::endl;
  std::cout << "    Bla Bla Bla..." << std::endl;
}

bool Inventario::interactions(OPTIONS_ENUM &option, Item &item)
{
  unsigned quantity;
  switch (option)
  {
  case USAR:
    if (this->personagem->sanity + item.sanity <= 0)
    {
      deadBySanityMSG();
      this->personagem->sanity = 0;
      return false;
    }

    if (this->personagem->vitality + item.vitality <= 0)
    {
      deadByVitalityMSG();
      this->personagem->vitality = 0;
      return false;
    }

    this->personagem->sanity += item.sanity;
    this->personagem->vitality += item.vitality;
    return true;

  case CONSUMIR:
    std::cout << "Quantidade: ";
    std::cin >> quantity;

    if (this->personagem->sanity + quantity * item.sanity <= 0)
    {
      deadBySanityMSG();

      this->personagem->sanity = 0;
      return false;
    }

    if (this->personagem->vitality + quantity * item.vitality <= 0)
    {
      deadByVitalityMSG();

      this->personagem->vitality = 0;
      return false;
    }

    removeItem(item, quantity);

    return true;
    break;

  case REMOVER:

    if (!item.consumible)
      removeItem(item);

    std::cout << "Quantidade: ";
    std::cin >> quantity;

    removeItem(item, quantity);
    break;
  }
}

bool Inventario::interactItem(unsigned itemPos, unsigned itemQuantity)
{
  auto it = this->itemList.begin();
  for (unsigned i = 0; i < itemPos; ++i)
    ++it;

  unsigned choice = showIteractions(*it);

  OPTIONS_ENUM option = optionsEnum(it->options[choice - 1]);

  bool isDead = this->interactions(option, *it);

  return isDead;
};

std::string inventaryHeader(std::size_t maxLen)
{
  std::string itemName = "ITEM(QNT?)";
  std::string itemType = "TIPO";
  std::string itemVitality = "VITALIDADE";
  std::string itemSanity = "SANIDADE";

  std::vector<std::string> headerItems = {itemName, itemType, itemVitality, itemSanity};

  std::size_t headerItemTab;

  std::size_t headerItemMaxLen = 0;

  for (auto &headerItem : headerItems)
  {
    if (headerItem.size() > headerItemMaxLen)
      headerItemMaxLen = headerItem.size();
  }
}

std::string typeItemParse(TYPE_ENUM &type)
{
  switch (type)
  {
  case TYPE_ENUM::ALIMENTO:
    return "Alimento";
  case TYPE_ENUM::ARMA:
    return "Arma";
  case TYPE_ENUM::FERRAMENTA:
    return "Ferramenta";
  case TYPE_ENUM::HIGIENE:
    return "Higiene";
  case TYPE_ENUM::PRIMEIROS_SOCORROS:
    return "Primeiros Socorros";
  }
}

std::string Inventario::showInventary()
{
  std::string inventaryTitle = "🎒 Inventário 🎒";
  std::size_t tab;

  std::cout << std::string(tab, ' ');
  std::cout << inventaryTitle;
  std::cout << std::string(tab, ' ') << std::endl;

  std::cout << inventaryTitle << std::endl;
  if (this->itemList.empty())
  {
    std::string message = "Você não possui nenhum item no inventário ";
    return message;
  }

  std::string itemName = "ITEM(QNT?)";
  std::string itemType = "TIPO";
  std::string itemVitality = "VITALIDADE";
  std::string itemSanity = "SANIDADE";

  std::vector<std::string> headerItems = {itemName, itemType, itemVitality, itemSanity};

  std::size_t itemMaxLen = 0;

  for (auto &item : this->itemList)
  {
    if (item.name.size() > itemMaxLen)
      itemMaxLen = item.name.size();
  }

  tab = itemMaxLen / 2;

  unsigned itemCount = 1;
  std::string inventaryStr(4, ' ');
  inventaryStr.append("|");

  std::size_t itemNameLenMax = 0;
  std::size_t itemTypeLenMax = 0;
  std::size_t itemVitalityLenMax = 0;
  std::size_t itemSanityLenMax = 0;

  for (auto &item : this->itemList)
  {
    if (item.name.size() > itemNameLenMax)
      itemNameLenMax = item.name.size();

    std::string itemTypeStr = typeItemParse(item.type);
    if (itemTypeStr.size() > itemTypeLenMax)
      itemTypeLenMax = itemTypeStr.size();

    std::string itemVitalityStr = std::to_string(item.vitality);
    std::string itemSanityStr = std::to_string(item.sanity);
    if (itemVitalityStr.size() > itemVitalityLenMax)
      itemVitalityLenMax = itemVitalityStr.size();

    if (itemSanityStr.size() > itemSanityLenMax)
      itemSanityLenMax = itemSanityStr.size();
  }

  std::size_t nameTab = itemNameLenMax / 2;
  std::size_t typeTab = itemTypeLenMax / 2;
  std::size_t vitalityTab = itemVitalityLenMax / 2;
  std::size_t sanityTab = itemSanityLenMax / 2;

  inventaryStr.append(nameTab - itemName.size() / 2, ' ');
  inventaryStr.append(itemName);
  inventaryStr.append(nameTab - itemName.size() / 2, ' ');
  inventaryStr.append("|");

  inventaryStr.append(typeTab - itemType.size() / 2, ' ');
  inventaryStr.append(itemType);
  inventaryStr.append(typeTab - itemType.size() / 2, ' ');
  inventaryStr.append("|");

  inventaryStr.append(vitalityTab - itemVitality.size() / 2, ' ');
  inventaryStr.append(itemVitality);
  inventaryStr.append(vitalityTab - itemVitality.size() / 2, ' ');
  inventaryStr.append("|");

  inventaryStr.append(vitalityTab - itemSanity.size() / 2, ' ');
  inventaryStr.append(itemSanity);
  inventaryStr.append(vitalityTab - itemSanity.size() / 2, ' ');

  inventaryStr.append("\n");

  std::string itemCountStr = std::to_string(itemCount);
  for (auto &item : this->itemList)
  {
    itemCountStr = std::to_string(itemCount);
    inventaryStr.append(2, ' ');
    inventaryStr.append(itemCountStr);
    inventaryStr.append("|");

    std::size_t itemNameLen = item.name.size();
    if (item.consumible)
    {
      std::size_t itemQuantityLen = std::to_string(item.quantity).size();
      itemNameLen += 2 + itemQuantityLen;
    }
    std::string itemTypeStr = typeItemParse(item.type);
    std::size_t itemTypeLen = itemTypeStr.size();
    std::size_t itemVitalityLen = std::to_string(item.vitality).size();
    std::size_t itemSanityLen = std::to_string(item.sanity).size();

    inventaryStr.append(nameTab - itemNameLen / 2, ' ');

    // inventaryStr.append(nameTab - itemNameLen / 2, ' ');
    inventaryStr.append(item.name);
    if (item.consumible)
    {
      inventaryStr.append("(");
      inventaryStr.append(std::to_string(item.quantity));
      inventaryStr.append(")");
    }

    inventaryStr.append(tab - itemNameLen / 2, ' ');
    inventaryStr.append("|");

    inventaryStr.append(typeTab - itemTypeLen / 2, ' ');
    inventaryStr.append(typeItemParse(item.type));
    inventaryStr.append(typeTab - itemTypeLen / 2, ' ');
    inventaryStr.append("|");

    std::string vitality = std::to_string(item.vitality);
    inventaryStr.append(vitalityTab - itemVitalityLen / 2, ' ');
    inventaryStr.append(vitality);
    inventaryStr.append(vitalityTab - itemVitalityLen / 2, ' ');
    inventaryStr.append("|");

    std::string sanity = std::to_string(item.sanity);

    inventaryStr.append(sanityTab - itemSanityLen / 2, ' ');
    inventaryStr.append(sanity);
    inventaryStr.append(sanityTab - itemSanityLen / 2, ' ');
    inventaryStr.append("\n");
    ++itemCount;
  }

  return inventaryStr;
}
