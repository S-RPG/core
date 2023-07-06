#ifndef FACTORY_SITUACAO_H
#define FACTORY_SITUACAO_H

#include "factory.hpp"
#include "../class/situacao/situacao.hpp"

#include <map>
#include <string>
#include <vector>

class FactorySituacao : public Factory<Situacao>, public Situacao
{
public:
  Situacao *create(std::vector<std::string> *instanceValues) override;
  std::map<unsigned, std::vector<Situacao>> Factory(std::string &filename);

  void *populateDia(std::vector<Situacao> *situacoes_dia, const Situacao &situacao);

private:
  std::vector<Situacao> situacoes_dia;
  std::map<unsigned, std::vector<Situacao>> situacoes_dias;
};

#endif
