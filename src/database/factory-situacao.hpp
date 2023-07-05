#ifndef FACTORY_SITUACAO_H
#define FACTORY_SITUACAO_H

#include "factory.hpp"
#include "../class/situacao/situacao.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

class FactorySituacao : public Factory<Situacao>
{
public:
  Situacao *create(std::vector<std::string>) override;

  std::vector<std::string> getLine(FILE *file) override;

  std::vector<std::string> getHeader(FILE *file) override;

private:
  std::vector<Situacao> situacoes_dia;
  std::map<unsigned, std::vector<Situacao>> situacoes_dias;
};

#endif
