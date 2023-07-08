#ifndef FACTORY_DECISAO_H
#define FACTORY_DECISAO_H

#include "factory.hpp"
#include "factory-situacao.hpp"
#include "../class/decisao/decisao.hpp"

#include <map>
#include <string>
#include <vector>
#include <memory>

class FactoryDecisao : public Factory<Decisao>
{
public:
  std::shared_ptr<Decisao> create(const std::vector<std::string> &instanceValues) override;

  std::map<unsigned, std::map<char, Decisao>> Factory(std::string &filename);
  void populateDecisoes(const Decisao &decisao);

  friend class FactorySituacao;

private:
  std::map<char, Decisao &> decisoes_dia;
  static std::map<unsigned, std::map<char, Decisao>> decisoes;
};

#endif
