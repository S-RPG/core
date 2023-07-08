#include "factory.hpp"
#include "../class/dia/dia.hpp"
#include "factory-dia.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <memory>

/**
 * Função de fábrica que processa um arquivo e retorna um vetor de objetos Dia.
 *
 * @param filename o nome do arquivo a ser processado
 *
 * @return um vetor de objetos Dia representando os dados processados
 *
 * @throws std::exception se ocorrer um erro durante o processamento
 */
std::vector<Dia> FactoryDia::Factory(std::string &filename)
{
  std::ifstream file(filename);

  unsigned lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
  Factory::removeLine(filename);
  this->diaMax = 1;
  for (unsigned i = 0; i < lineCount; ++i)
  {
    std::vector<std::string> intanceValuesItem = Factory::factory(filename);
    this->addItem(intanceValuesItem);
  }

  for (int i = 1; i <= this->diaMax; ++i)
  {
    std::vector<Situacao> &situacoes = this->situacoes_dias[i];
    std::shared_ptr<Dia> _dia = std::make_shared<Dia>(i, situacoes, this->items);

    this->dias.push_back(static_cast<Dia>(*_dia));

    std::cout << "[+] Dia " << i << " adicionado com sucesso!" << std::endl;
  }

  return this->dias;
}

/**
 * Adiciona um item ao FactoryDia.
 *
 * @param instanceValues um vetor de strings contendo os valores para o item
 *
 * @throws std::invalid_argument se os valores fornecidos forem inválidos
 */
void FactoryDia::addItem(const std::vector<std::string> &instanceValues)
{
  auto it = instanceValues.begin();

  unsigned dia = std::stoul(*it++);
  unsigned itemId = std::stoul(*it++);
  std::string quantidadeStr = *it++;
  unsigned quantidade = NULL;

  if (!quantidadeStr.empty())
  {
    unsigned quantidade = std::stoul(quantidadeStr);
  }

  auto it2 = this->items.begin();
  for (; it2 != this->items.end(); ++it2)
  {
    auto item = it2->second.begin();
    if (item->id == itemId)
    {
      std::shared_ptr<Item> _item = std::make_shared<Item>(item->id, item->nome, item->tipo, item->preco, item->vitalidade, item->sanidade, item->consumivel, quantidade, item->opcoes);

      this->itemList.push_back(static_cast<Item>(*_item));
    }
  }

  if (dia > this->diaMax)
  {
    this->diaMax = dia;
  }
}
