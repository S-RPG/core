#ifndef DECISAO_H
#define DECISAO_H

#include <string>

typedef struct Decisao
{
  double impactoSanidade;
  double impactoVitalidade;
  std::string texto;
  char alternativa;
  unsigned id;
  unsigned situacaoId;

  Decisao(unsigned id, unsigned situacaoId, char alternativa, std::string texto, double impactoSanidade, double impactoVitalidade)
      : id(id), situacaoId(situacaoId), alternativa(alternativa), texto(texto), impactoSanidade(impactoSanidade), impactoVitalidade(impactoVitalidade){};
};

#endif
