#include "factory.hpp"
#include "../class/situacao/situacao.hpp"
#include "factory-situacao.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <memory>

/**
 * Cria um novo objeto Situacao com base nos valores de instância fornecidos.
 *
 * @param instanceValues Um vector de strings contendo os valores de instância.
 *
 * @return Um ponteiro unico para um objeto Situacao.
 *
 * @throws std::invalid_argument Se os valores da instancia forem invalidos.
 */
std::shared_ptr<Situacao> FactorySituacao::create(const std::vector<std::string> &instanceValues)
{
  std::vector<std::string>::const_iterator it = instanceValues.begin();
  unsigned id = std::stoul(*it++, nullptr, 10);
  std::string titulo = *it++;
  std::string contexto = *it++;
  unsigned decisoesId = std::stoul(*it++, nullptr, 10);
  unsigned dia = std::stoul(*it++, nullptr, 10);
  unsigned situacaoConectadaId = 0;
  std::string _situacaoConectadaId = *it++;
  if (!_situacaoConectadaId.empty())
  {
    situacaoConectadaId = std::stoul(_situacaoConectadaId, nullptr, 10);
  }

  std::cout << "Situacao " << id << " - " << titulo << " criada com sucesso!" << std::endl;
  return std::make_shared<Situacao>(id, titulo, contexto, decisoesId, dia, situacaoConectadaId);
};

/**
 * Esta funcao adiciona um objeto 'situacao' ao vetor 'situacoes_dia'.
 *
 * @param situacao O objeto 'situacao' a ser adicionado.
 *
 * @return void
 *
 * @throws std::invalid_argument se o ponteiro 'this' for nulo.
 */
void FactorySituacao::populateDia(const Situacao &situacao)
{
  if (this == nullptr)
  {
    throw std::invalid_argument("FactorySituacao instance is null");
  }

  this->situacoes_dia.push_back(situacao);
}

/**
 * FactorySituacao::Factory e uma funcao C++ que recebe um parametro de string `filename` e retorna um `std::map<unsigned, std::vector<Situacao>>`.
 *
 * @param filename uma string representando o nome do arquivo a ser processado
 *
 * @return um map que associa um inteiro positivo representando um dia com um vector de objetos Situacao
 *
 * @throws None
 */
std::map<unsigned, std::vector<Situacao>> FactorySituacao::Factory(std::string &filename)
{
  std::ifstream file(filename);

  unsigned lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
  this->removeLine(filename);

  unsigned diaAtual = 1;
  for (unsigned i = 0; i < lineCount; ++i)
  {

    std::vector<std::string> instanceValues = Factory::factory(filename);
    auto situacao = this->create(instanceValues);
    if (situacao->_dia == diaAtual)
    {
      this->populateDia(*situacao);
      this->situacoes_dias.insert_or_assign(diaAtual, situacoes_dia);
      std::cout << "[!] Situacao " << situacao->_id << " - " << situacao->_titulo << " atribuida ao dia " << situacao->_dia << " com sucesso!" << std::endl;
    }
    else
    {
      diaAtual = situacao->_dia;
      situacoes_dia.clear();
      this->populateDia(*situacao);
      this->situacoes_dias.insert_or_assign(diaAtual, situacoes_dia);
      std::cout << "[+] Dia " << diaAtual << " criado e situacao " << situacao->_id << " - " << situacao->_titulo << " atribuida ao dia " << situacao->_dia << " com sucesso!" << std::endl;
    }
  }

  return situacoes_dias;
};
