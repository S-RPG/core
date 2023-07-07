#include "factory.hpp"
#include "../class/decisao/decisao.hpp"
#include "factory-decisao.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <memory>

/**
 * Crie um objeto de Decisão com base nos valores da instância.
 *
 * @param instanceValues - Um ponteiro para um vetor de strings contendo os valores de instância.
 * @return Um ponteiro para um objeto de Decisão criado.
 */
std::shared_ptr<Decisao> FactoryDecisao::create(const std::vector<std::string> &instanceValues)
{
  auto it = instanceValues.begin();
  unsigned id = std::stoul(*it++);
  unsigned situacaoId = std::stoul(*it++);
  std::string s = *it++;
  char alternativa = s.at(0);
  std::string texto = *it++;
  float impactoSanidade = std::stof(*it++);
  float impactoVitalidade = std::stof(*it++);

  std::cout << "Decisao " << id << " - " << alternativa << ") " << texto << " criada com sucesso!"
            << std::endl;

  return std::make_shared<Decisao>(id, situacaoId, alternativa, texto, impactoSanidade, impactoVitalidade);
}

/**
 * Essa funcao popula o map 'decisoes_dia' na classe 'FactoryDecisao' com um objeto de Decisao.
 *
 * @param decisao O objeto de Decisao a ser inserido ou atribuido ao map.
 * @return None
 */
void FactoryDecisao::populateDecisoes(const Decisao &decisao)
{
  decisoes_dia[decisao.alternativa] = decisao;
}

/**
 * FactoryDecisao::Factory - Crie um map de decisoes com base em um arquivo .csv (;)
 *
 * Essa funcao le um arquivo e cria um map de decisoes com base no
 * conteudo do arquivo. O map esta estruturado da seguinte forma:
 *   - As chaves do map externo sao inteiros positivos que representam
 *     IDs das situacoes.
 *   - Os valores do map externo sao maps internos.
 *   - As chaves dos maps internos sao caracteres que representam alternativas.
 *   - Os valores dos maps internos sao referencias aos objetos de Decisao.
 *
 * @param filename O nome do arquivo para ser lido
 * @return Um map de decisoes
 */
std::map<unsigned, std::map<char, Decisao>> FactoryDecisao::Factory(std::string &filename)
{
  std::ifstream file(filename);

  // Conta o numero de linhas () do arquivo
  unsigned lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
  this->removeLine(filename);

  unsigned situacaoAtual = 1;
  for (unsigned i = 0; i < lineCount; ++i)
  {
    // Crie uma instância de Decisao com base no conteúdo do arquivo
    std::vector<std::string> instanceValues = Factory::factory(filename);
    auto decisao = this->create(instanceValues);

    if (decisao == nullptr)
    {
      continue;
    }

    // Verifica se o ID da decisao correspondente ao ID da situacao atual existe
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
}
