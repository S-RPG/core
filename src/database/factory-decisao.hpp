#ifndef FACTORY_SITUACAO_H
#define FACTORY_SITUACAO_H

#include "factory.hpp"
#include "../class/decisao/decisao.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

class FactoryDecisao : public Factory<Decisao>
{
public:
  Decisao *create(std::vector<std::string>) override;

  std::vector<std::string> getLine(FILE *file) override;

  std::vector<std::string> getHeader(FILE *file) override;

private:
  std::vector<Decisao> situacoes_dia;
  std::map<unsigned, std::vector<Decisao>> situacoes_dias;
};

#endif
