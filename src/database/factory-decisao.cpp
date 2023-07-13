#include "factory-decisao.hpp"

#include <string>
#include <vector>
#include <map>

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <initializer_list>

std::map<unsigned, std::vector<std::pair<char, Decisao>>> FactoryDecisao::decisoes;

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

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid id field" << std::endl;
      continue;
    }
    id = std::stoul(field, nullptr, 10);

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid situacaoId field" << std::endl;
      continue;
    }
    situacaoId = std::stoul(field, nullptr, 10);

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid alternativa field" << std::endl;
      continue;
    }
    alternativa = field[0];

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid texto field" << std::endl;
      continue;
    }
    texto = field;

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid impactoSanidade field" << std::endl;
      continue;
    }
    auto _field = field == "-" ? "0.0" : field;
    impactoSanidade = std::stof(_field, nullptr);

    if (!std::getline(ss, field, ';'))
    {
      std::cerr << "Invalid impactoVitalidade field" << std::endl;
      continue;
    }
    _field = field == "-" ? "0.0" : field;
    impactoVitalidade = std::stof(_field, nullptr);

    Decisao decisao;
    decisao.id = id;
    decisao.situacaoId = situacaoId;
    decisao.alternativa = alternativa;
    decisao.texto = texto;
    decisao.impactoSanidade = impactoSanidade;
    decisao.impactoVitalidade = impactoVitalidade;

    auto decisoes_it = this->decisoes.find(situacaoId);

    std::pair<char, Decisao> _decisao{alternativa, decisao};

    if (!decisoes_it->second.empty())
    {
      std::vector<std::pair<char, Decisao>> decisao_situacao = decisoes_it->second;
      decisao_situacao.emplace_back(_decisao);
      this->decisoes[situacaoId] = decisao_situacao;
    }
    else
    {
      std::vector<std::pair<char, Decisao>> decisao_situacao;
      decisao_situacao.assign(1, _decisao);
      this->decisoes.insert_or_assign(situacaoId, decisao_situacao);
      this->decisoes.emplace(situacaoId, decisao_situacao);
    }
  }
}
