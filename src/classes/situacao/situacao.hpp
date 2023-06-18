#ifndef SITUCAO_H
#define SITUACAO_H

#include <decisao/decisao.hpp>

#include <string>
#include <map>

class Situacao : Decisao
{
private:
  std::string _contexto;
  std::map<char, Decisao> _decisoes;
  std::string _titulo;

public:
  Situacao(std::string contexto, std::map<char, Decisao> decisoes, std::string titulo);

  void setContexto(std::string contexto);

  void setDecisoes(char alternativa, Decisao decisao);

  void setTitulo(std::string titulo);

  void getContexto();

  void getDecisoes();

  void getTitulo();
};

#endif
