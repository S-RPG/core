#ifndef F_LOJA_H
#define F_LOJA_H

#include "factory.hpp"
#include "../class/item.hpp"

#include <string>
#include <vector>
#include <map>

class FactoryLoja : public IFactory<const std::string &>
{
public:
  FactoryLoja();
  void create(const std::string &filename) override;

  static std::map<unsigned, std::vector<std::pair<unsigned, unsigned>>> abastecimento;
};

#endif
