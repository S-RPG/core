#ifndef DECISAO
#define DECISAO

#include <string>

class Decisao
{
private:
  char _alternativa;
  double _impactoSanidade;
  double _impactoVitalidade;
  std::string _texto;

public:
  Decisao(char alternativa, double impactoSanidade, double impactoVitalidade, std::string texto);

  void setAlternativa(char alternativa);

  void setImpactoSanidade(char impactoSanidade);

  void setImpactoVitalidade(char impactoVitalidade);

  void setTexto(std::string texto);

  char getAlternativa();

  double getImpactoSanidade();

  double getImpactoVitalidade();

  std::string getTexto();
};

#endif
