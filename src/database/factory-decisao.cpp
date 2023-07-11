#include "factory-decisao.hpp"

#include <string>
#include <vector>
#include <map>

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

std::map<std::size_t, std::map<char, Decisao *>> FactoryDecisao::decisoes;

void FactoryDecisao::create(const std::string &filename)
{

  std::ifstream file(filename);

  if (!file)
  {
    std::cerr << "File not found: " << filename << std::endl;
  }

  std::string line;
  while (std::getline(file, line))
  {
    std::istringstream ss(line);
    std::string field;

    float impactoSanidade;
    float impactoVitalidade;
    std::string texto;
    char alternativa;
    unsigned id;
    unsigned situacaoId;

    if (std::getline(ss, field, ';'))
    {
      id = std::stoul(field, nullptr, 10);
    }
    else
    {
      std::cerr << "Invalid id field" << std::endl;
      continue;
    }

    if (std::getline(ss, field, ';'))
    {
      situacaoId = std::stoul(field, nullptr, 10);
    }
    else
    {
      std::cerr << "Invalid situacaoId field" << std::endl;
      continue;
    }

    if (std::getline(ss, field, ';'))
    {
      alternativa = field[0];
    }
    else
    {
      std::cerr << "Invalid alternativa field" << std::endl;
      continue;
    }

    if (std::getline(ss, field, ';'))
    {
      texto = field;
    }
    else
    {
      std::cerr << "Invalid texto field" << std::endl;
      continue;
    }

    if (std::getline(ss, field, ';'))
    {
      auto _field = field == "-" ? "0.0" : field;

      impactoSanidade = std::stof(_field, nullptr);
    }
    else
    {
      std::cerr << "Invalid impactoSanidade field" << std::endl;
      continue;
    }

    if (std::getline(ss, field, ';'))
    {
      auto _field = field == "-" ? "0.0" : field;
      impactoVitalidade = std::stof(_field, nullptr);
    }
    else
    {
      std::cerr << "Invalid impactoVitalidade field" << std::endl;
      continue;
    }

    Decisao *decisao = new Decisao(id, situacaoId, alternativa, texto, impactoSanidade, impactoVitalidade);

    this->decisoes[situacaoId][alternativa] = decisao;
  }
}
