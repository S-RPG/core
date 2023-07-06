#include "factory.hpp"
#include "../class/decisao/decisao.hpp"
#include "factory-decisao.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

Decisao *FactoryDecisao::create(std::vector<std::string> *instanceValues)
{

  std::vector<std::string>::iterator it = instanceValues->begin();
  unsigned id = std::stoul(*it++, nullptr, 10);
  unsigned situacaoId = std::stoul(*it++, nullptr, 10);
  std::string s = *it++;
  char alternativa = s.at(0);
  std::string texto = *it++;
  double impactoSanidade = std::stod(*it++, nullptr);
  double impactoVitalidade = std::stod(*it++, nullptr);

  std::cout << "Decisao " << id << " - " << alternativa << ") " << texto << " criada com sucesso!" << std::endl;

  return new Decisao(id, situacaoId, alternativa, texto, impactoSanidade, impactoVitalidade);
};

void *FactoryDecisao::populateDecisoes(const Decisao &decisao)
{
  decisoes_dia.insert_or_assign(decisao.alternativa, decisao);
}

std::map<unsigned, std::map<char, Decisao &>> FactoryDecisao::Factory(std::string &filename)
{
  std::ifstream file(filename);

  unsigned lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
  this->removeLine(filename);

  unsigned situacaoAtual = 1;
  for (unsigned i = 0; i < lineCount; ++i)
  {

    std::vector<std::string> instanceValues = Factory::factory(filename);
    Decisao *decisao = this->create(&instanceValues);
    if (decisao->id == situacaoAtual)
    {
      this->populateDecisoes(*decisao);
      decisoes.insert_or_assign(situacaoAtual, decisoes_dia);
      std::cout << "[!] Decisao atribuida a situacao " << decisao->situacaoId << " com sucesso!" << std::endl;
    }

    situacaoAtual = decisao->id;
    decisoes_dia.clear();
    this->populateDecisoes(*decisao);
    decisoes.insert_or_assign(situacaoAtual, decisoes_dia);
    std::cout << "[+] Decisao criada para a situacao " << decisao->situacaoId << " com sucesso!" << std::endl;
  }

  return decisoes;
};
