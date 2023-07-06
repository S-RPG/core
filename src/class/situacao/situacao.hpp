#ifndef SITUACAO_H
#define SITUACAO_H

#include "../decisao/decisao.hpp"

#include <string>
#include <map>

class Situacao
{
public:
  Situacao(unsigned id, std::string titulo, std::string contexto, unsigned decisoesId, unsigned dia, unsigned situacaoConectadaId);
  std::string getTitulo(std::size_t charMax);
  std::string getDecisoes(std::map<char, Decisao> *decisoes);

  unsigned _decisoesId;
  unsigned _dia;
  unsigned _id;
  unsigned _situacaoConectadaId;
  std::string _titulo;

private:
  std::string _contexto;
};

#endif
