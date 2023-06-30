#include "decisao.hpp"
#include <string>

Decisao::Decisao(char alternativa, double impactoSanidade, double impactoVitalidade, std::string texto)
    : _texto(texto), _alternativa(alternativa), _impactoSanidade(impactoSanidade), _impactoVitalidade(impactoVitalidade) {}

Decisao::Decisao(){};

void Decisao::setAlternativa(char alternativa)
{
  _alternativa = alternativa;
};

void Decisao::setImpactoSanidade(char impactoSanidade)
{
  _impactoSanidade = impactoSanidade;
};

void Decisao::setImpactoVitalidade(char impactoVitalidade)
{
  _impactoVitalidade = impactoVitalidade;
};

void Decisao::setTexto(std::string texto)
{
  _texto = texto;
};

char Decisao::getAlternativa()
{
  return _alternativa;
}

double Decisao::getImpactoSanidade()
{
  return _impactoSanidade;
}

double Decisao::getImpactoVitalidade()
{
  return _impactoVitalidade;
}

std::string Decisao::getTexto()
{
  return _texto;
}
