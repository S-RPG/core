#include "factory.hpp"
#include "../class/situacao/situacao.hpp"
#include "factory-situacao.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

Situacao *FactorySituacao::create(std::vector<std::string> *instanceValues)
{
  std::vector<std::string>::iterator it = instanceValues->begin();
  unsigned id = std::stoul(*it++, nullptr, 10);
  std::string titulo = *it++;
  std::string contexto = *it++;
  unsigned decisoesId = std::stoul(*it++, nullptr, 10);
  unsigned dia = std::stoul(*it++, nullptr, 10);
  unsigned situacaoConectadaId;
  std::string _situacaoConectadaId = *it++;
  if (!_situacaoConectadaId.empty())
    situacaoConectadaId = std::stoul(*it++, nullptr, 10);
  else
    situacaoConectadaId = 0;

  std::cout << "Situacao " << id << " - " << titulo << " criada com sucesso!" << std::endl;
  return new Situacao(id, titulo, contexto, decisoesId, dia, situacaoConectadaId);
};

void *FactorySituacao::populateDia(const Situacao &situacao)
{
  situacoes_dia.push_back(situacao);
}

std::map<unsigned, std::vector<Situacao>> FactorySituacao::Factory(std::string &filename)
{
  std::ifstream file(filename);

  unsigned lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
  this->removeLine(filename);

  unsigned diaAtual = 1;
  for (unsigned i = 0; i < lineCount; ++i)
  {

    std::vector<std::string> instanceValues = Factory::factory(filename);
    Situacao *situacao = this->create(&instanceValues);
    if (situacao->_dia == diaAtual)
    {
      this->populateDia(*situacao);
      situacoes_dias.insert_or_assign(diaAtual, situacoes_dia);
      std::cout << "[!] Situacao " << situacao->_id << " - " << situacao->_titulo << " atribuida ao dia " << situacao->_dia << " com sucesso!" << std::endl;
    }

    diaAtual = situacao->_dia;
    situacoes_dia.clear();
    this->populateDia(*situacao);
    situacoes_dias.insert_or_assign(diaAtual, situacoes_dia);
    std::cout << "[+] Dia " << diaAtual << "criado e situacao " << situacao->_id << " - " << situacao->_titulo << " atribuida ao dia " << situacao->_dia << " com sucesso !" << std::endl;
  }

  return situacoes_dias;
};
