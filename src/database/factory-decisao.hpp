#ifndef F_DECISAO_H
#define F_DECISAO_H

#include "factory.hpp"
#include "factory-situacao.hpp"
#include "../class/decisao.hpp"

#include <string>
#include <vector>
#include <map>

class FactoryDecisao : public IFactory<const std::string &>
{
public:
  void create(const std::string &filename) override;

  static std::map<std::size_t, std::map<char, Decisao *>> decisoes;

  friend class FactorySituacao;
};

#endif
