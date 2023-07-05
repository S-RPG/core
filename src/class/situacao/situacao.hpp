#ifndef SITUACAO_H
#define SITUACAO_H

#include "../decisao/decisao.hpp"

#include <string>
#include <map>

class Situacao
{
public:
  Situacao(std::string contexto, std::string titulo, unsigned decisoesId, unsigned dia, unsigned id, unsigned situacaoConectadaId);
  std::string getTitulo(std::size_t charMax);
  std::string getDecisoes(std::map<char, Decisao> *decisoes);

  unsigned _decisoesId;
  unsigned _dia;
  unsigned _id;
  unsigned _situacaoConectadaId;

private:
  std::string _contexto;
  std::string _titulo;
};

#endif
