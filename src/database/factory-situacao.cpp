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

std::map<std::size_t, std::vector<Situacao *>> FactorySituacao::situacoes;

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
    std::map<char, Decisao *> decisoes;
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

    decisoes = FactoryDecisao::decisoes[dia];

    Situacao *situacao = new Situacao(id, titulo, contexto, decisoes, dia);

    this->situacoes[dia].push_back(situacao);
  }
}
