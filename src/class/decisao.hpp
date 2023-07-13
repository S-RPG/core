#ifndef DECISAO_H
#define DECISAO_H

#include <string>

typedef struct Decisao
{
  float impactoSanidade;
  float impactoVitalidade;
  std::string texto;
  char alternativa;
  unsigned id;
  unsigned situacaoId;

  Decisao(unsigned id, unsigned situacaoId, char alternativa, std::string texto, float impactoSanidade, float impactoVitalidade)
      : id(id), situacaoId(situacaoId), alternativa(alternativa), texto(texto), impactoSanidade(impactoSanidade), impactoVitalidade(impactoVitalidade){};

  Decisao(){};

  bool operator==(const Decisao &decisao)
  {
    return this->alternativa == decisao.alternativa;
  };

} Decisao;

#endif
