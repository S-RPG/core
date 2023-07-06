#ifndef DECISAO_H
#define DECISAO_H

#include <string>

struct Decisao
{
<<<<<<< HEAD
  char alternativa;
  double impactoSanidade;
  double impactoVitalidade;
  std::string texto;
=======
private:
  char _alternativa;
  double _impactoSanidade;
  double _impactoVitalidade;
  std::string _texto;

public:
  Decisao();

  Decisao(char alternativa, double impactoSanidade, double impactoVitalidade, std::string texto);

  void setAlternativa(char alternativa);

  void setImpactoSanidade(char impactoSanidade);

  void setImpactoVitalidade(char impactoVitalidade);

  void setTexto(std::string texto);

  char getAlternativa();

  double getImpactoSanidade();

  double getImpactoVitalidade();

  std::string getTexto();
>>>>>>> 2b08b1dec2ab14d157fca7afc1c160546620c5e1
};

#endif
