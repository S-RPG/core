#ifndef FACTORY_SITUACAO_H
#define FACTORY_SITUACAO_H

#include "factory.hpp"
#include "../class/decisao/decisao.hpp"

#include <map>
#include <string>
#include <vector>

class FactoryDecisao : public Factory<Decisao>
{
public:
  Decisao *create(std::vector<std::string> *instanceValues) override;

private:
  std::vector<Decisao> situacoes_dia;
  std::map<unsigned, std::vector<Decisao>> situacoes_dias;
};

#endif
