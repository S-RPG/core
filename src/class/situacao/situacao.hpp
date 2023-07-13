#ifndef SITUACAO_H
#define SITUACAO_H

#include "../decisao.hpp"

#include <string>
#include <map>
#include <vector>

class Situacao
{
public:
  Situacao();

  Situacao(unsigned id, std::string titulo, std::string contexto, std::vector<std::pair<char, Decisao>> decisoes, unsigned dia, unsigned situacaoConectadaId);
  Situacao(unsigned id, std::string titulo, std::string contexto, std::vector<std::pair<char, Decisao>> decisoes, unsigned dia);
  std::string getTitulo(std::size_t charMax);
  std::string getDecisoes(std::size_t charMax);
  std::string getContexto(std::size_t charMax);

  unsigned _dia;
  unsigned _id;
  unsigned _situacaoConectadaId;
  std::string _titulo;
  std::string _contexto;

  std::vector<std::pair<char, Decisao>> _decisoes;

  bool operator==(const Situacao &situacao);
};

#endif
