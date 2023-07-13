#include "factory-situacao.hpp"
#include "factory-decisao.hpp"

#include <string>
#include <vector>
#include <map>

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

std::map<unsigned, std::vector<Situacao>> FactorySituacao::situacoes;

void FactorySituacao::operator=(Situacao &situacao)
{
}

void FactorySituacao::create(const std::string &filename)
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

    unsigned id;
    std::string titulo;
    std::string contexto;
    unsigned dia;
    std::vector<std::pair<char, Decisao>> decisoes;
    // unsigned situacaoConectadaId;

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
      titulo = field;
    }
    else
    {
      std::cerr << "Invalid titulo field" << std::endl;
      continue;
    }

    if (std::getline(ss, field, ';'))
    {
      contexto = field;
    }
    else
    {
      std::cerr << "Invalid contexto field" << std::endl;
      continue;
    }

    if (std::getline(ss, field, ';'))
    {
      dia = std::stoul(field, nullptr, 10);
    }
    else
    {
      std::cerr << "Invalid dia field" << std::endl;
      continue;
    }

    auto decisoes_it = FactoryDecisao::decisoes.find(id);
    if (!decisoes_it->second.empty())
    {
      decisoes = decisoes_it->second;
    }

    Situacao situacao;

    situacao._id = id;
    situacao._titulo = titulo;
    situacao._contexto = contexto;
    situacao._decisoes = decisoes;
    situacao._dia = dia;

    auto situacao_dia = this->situacoes.find(dia);

    if (!situacao_dia->second.empty())
    {
      std::vector<Situacao> _situacao = situacao_dia->second;
      _situacao.emplace_back(situacao);
      this->situacoes.emplace(dia, _situacao);
    }
    else
    {
      std::vector<Situacao> _situacao;
      _situacao.assign(1, situacao);
      this->situacoes.insert_or_assign(dia, _situacao);
    }
  }
}
