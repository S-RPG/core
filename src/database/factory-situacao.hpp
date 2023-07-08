#ifndef FACTORY_SITUACAO_H
#define FACTORY_SITUACAO_H

#include "factory.hpp"
#include "../class/situacao/situacao.hpp"

#include <map>
#include <string>
#include <vector>
#include <memory>

class FactorySituacao : public Factory<Situacao>, public Situacao
{
public:
  std::shared_ptr<Situacao> create(const std::vector<std::string> &instanceValues) override;
  std::map<unsigned, std::vector<Situacao>> Factory(std::string &filename);

  void populateDia(const Situacao &situacao);

  friend class FactoryDia;

private:
  std::vector<Situacao> situacoes_dia;
  static std::map<unsigned, std::vector<Situacao>> situacoes_dias;
};

#endif
