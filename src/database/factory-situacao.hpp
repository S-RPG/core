#ifndef F_SITUACAO_H
#define F_SITUACAO_H

#include "factory.hpp"
#include "../class/situacao/situacao.hpp"
#include "../class/decisao.hpp"

#include <string>
#include <vector>
#include <map>

class FactorySituacao : public IFactory<const std::string &>
{
public:
  void create(const std::string &filename) override;

  void populate();

  static std::map<std::size_t, std::vector<Situacao *>> situacoes;

  // friend class FactoryDecisao;

  // private:
  // std::map<std::size_t, std::map<char, Decisao *>> _decisoes = FactoryDecisao::decisoes;
};

#endif
