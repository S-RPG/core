#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

enum TYPE_ENUM
{
  ALIMENTO = 1,
  ARMA,
  ENTRETERIMENTO,
  FERRAMENTA,
  HIGIENE,
  PRIMEIROS_SOCORROS
};

enum OPTIONS_ENUM
{
  USAR = 1,
  CONSUMIR = 2,
  REMOVER = 3,
  BEBER = CONSUMIR,
  COMER = CONSUMIR,
  ASSISTIR = USAR,
  JOGAR = USAR,
  LER = USAR,
  FUMAR = CONSUMIR,

};

typedef struct _Item
{
  bool available;
  bool consumible;
  float price;
  float sanity;
  float vitality;
  std::string name;
  unsigned id;
  unsigned quantity;
  bool operator==(const _Item &item)
  {
    return (id == item.id);
  }

} _Item;

typedef struct Item
{

  TYPE_ENUM type;
  bool available;
  bool consumible;
  float price;
  float sanity;
  float vitality;
  std::string name;
  std::vector<std::string> options;
  unsigned id;
  unsigned quantity;

    Item(){};

  Item(unsigned id, std::string name, TYPE_ENUM type, float price, float vitality, float sanity, bool consumible, std::vector<std::string> options)
      : id(id), name(name), type(type), price(price), sanity(sanity), vitality(vitality), consumible(consumible), options(options){};

  // Item(Item &other)
  // {
  //   Item(other.id, other.name, other.type, other.price, other.vitality, other.sanity, other.consumible, other.options);
  // };

  bool operator==(const Item &item)
  {
    return (id == item.id);
  }
} Item;

#endif
