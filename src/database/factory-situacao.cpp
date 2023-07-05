#include "factory.hpp"
#include "../class/situacao/situacao.hpp"
#include "factory-situacao.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

Situacao *FactorySituacao::create(std::vector<std::string> *instanceValues, std::vector<std::string> *instanceHeader)
{
  for (int index = 0; index < instanceValues->size(); index++)
  {
    std::string prop = instanceHeader->at(index);
    Situacao situacao = instanceValues->at(index);
  }
};

std::vector<std::string> FactorySituacao::getLine(FILE *file)
{
}

std::vector<std::string> FactorySituacao::getHeader(FILE *file) {}
