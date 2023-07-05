#ifndef DECISAO_H
#define DECISAO_H

#include <string>

struct Decisao
{
  double impactoSanidade;
  double impactoVitalidade;
  std::string texto;
  unsigned char alternativa;
  unsigned id;
  unsigned situacaoId;
};

#endif
