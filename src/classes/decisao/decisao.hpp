#ifndef DECISAO_H
#define DECISAO_H

#include <string>

struct Decisao
{
  char alternativa;
  double impactoSanidade;
  double impactoVitalidade;
  std::string texto;
};

#endif
