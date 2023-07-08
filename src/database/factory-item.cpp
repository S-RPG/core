#include "factory-item.hpp"
#include "../class/item/item.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <memory>

InteracaoItem parseInteracao(const std::string &interacao)
{
  if (interacao == "usar")
  {
    return USAR;
  }
  if (interacao == "remover")
  {
    return REMOVER;
  }
  if (interacao == "reparar")
  {
    return REPARAR;
  }
  if (interacao == "adicionar_carrinho")
  {
    return ADICIONAR_CARRINHO;
  }
  if (interacao == "remover_carrinho")
  {
    return REMOVER_CARRINHO;
  }
  if (interacao == "beber")
  {
    return BEBER;
  }
  if (interacao == "comer")
  {
    return COMER;
  }
  if (interacao == "ler")
  {
    return LER;
  }
  if (interacao == "fumar")
  {
    return FUMAR;
  }
  if (interacao == "jogar")
  {
    return JOGAR;
  }
  if (interacao == "vestir")
  {
    return VESTIR;
  }
  if (interacao == "tirar")
  {
    return TIRAR;
  }
  if (interacao == "nada")
  {
    return NADA;
  }
}

/**
 * Analisa a string de opções e retorna um mapa de InteracaoItem e seu valor de string correspondente.
 *
 * @param opcoes a string de opções a ser analisada
 *
 * @return um mapa de InteracaoItem e seu valor de string correspondente
 *
 * @throws std::invalid_argument se a string de opções não for válida
 */
std::map<InteracaoItem, std::string> parseOpcoes(const std::string &opcoes)
{
  std::map<InteracaoItem, std::string> _opcoes;

  std::string opcao;
  for (char c : opcoes)
  {
    if (c == ';')
    {
      InteracaoItem interacao = parseInteracao(opcao);
      _opcoes[interacao] = opcao;
      opcao.clear();
      continue;
    }
    opcao += c;
  }

  return _opcoes;
}
TipoItem parseTipo(const std::string &tipo)
{
  if (tipo == "alimento")
  {
    return ALIMENTO;
  }
  if (tipo == "arma")
  {
    return ARMA;
  }
  if (tipo == "entretenimento")
  {
    return ENTRETENIMENTO;
  }
  if (tipo == "ferramenta")
  {
    return FERRAMENTA;
  }
  if (tipo == "higiene")
  {
    return HIGIENE;
  }
  if (tipo == "primeiros socorros")
  {
    return PRIMEIROS_SOCORROS;
  }
  if (tipo == "nao identificado")
  {
    return NAO_IDENTIFICADO;
  }
  return NAO_IDENTIFICADO;
}

bool parseBool(std::string const &s)
{
  return s != "0";
}
/**
 * Cria um novo Item usando os valores de instância fornecidos.
 *
 * @param instanceValues um vetor de strings contendo os valores para cada atributo do Item.
 *
 * @return um ponteiro compartilhado para o objeto Item recém-criado.
 *
 * @throws std::invalid_argument se algum dos valores de instância não puder ser convertido nos tipos esperados.
 */
Item FactoryItem::create(const std::vector<std::string> &instanceValues)
{
  auto it = instanceValues.begin();

  unsigned id = std::stoul(*it++);
  std::cout << "ID: " << id << std::endl;

  std::string nome = *it++;
  std::cout << "Nome: " << nome << std::endl;

  TipoItem tipo = parseTipo(*it++);
  std::cout << "Tipo: " << tipo << std::endl;

  float preco = std::stoul(*it++);
  std::cout << "preco: " << preco << std::endl;

  int vitalidade = *it++ == "-" ? 0 : std::stoi(*it++, nullptr);
  std::cout << "vitalidade: " << vitalidade << std::endl;

  int sanidade = *it++ == "-" ? 0 : std::stoi(*it++, nullptr);
  std::cout << "sanidade: " << sanidade << std::endl;

  bool consumivel = parseBool(*it++);
  std::cout << "consumivel: " << consumivel << std::endl;

  // unsigned quantidade = consumivel ? std::stoul(*it++) : 0;
  unsigned quantidade = 1;
  std::cout << "quantidade: " << quantidade << std::endl;

  std::string opcoesStr = *it++;
  std::cout << "opcoesStr: " << opcoesStr << std::endl;
  std::map<InteracaoItem, std::string> opcoes = parseOpcoes(opcoesStr);

  std::cout << "Item " << id << " - " << nome << " criado com sucesso!" << std::endl;
  // return std::make_shared<Item>(&id, &nome, &tipo, &preco, &vitalidade, &sanidade, &consumivel, &quantidade, &opcoes);
  Item *_item = new Item(id, nome, tipo, preco, sanidade, vitalidade, consumivel, quantidade, opcoes);
  return *_item;
}

/**
 * Preenche os itens no FactoryItem.
 *
 * @param item o item a ser adicionado
 *
 * @throws std::invalid_argument se a instância FactoryItem for nula
 */
void FactoryItem::populateItems(Item &item)
{

  std::cout << item.id << " " << item.nome << " " << item.tipo << " " << std::endl;

  if (this == nullptr)
  {
    throw std::invalid_argument("FactoryItem instance is null");
  }

  auto itemIterator = this->items.find(item.tipo);

  if (itemIterator != this->items.end())
  {
    // auto &itemList = itemIterator->second;
    // //  emplace_back(item);

    // items[item.tipo].emplace_back(item);
    // // itemList.emplace_back(item);
    std::cout << "[!] Item " << item.nome << " adicionado aos itens de mesmo tipo com sucesso!" << std::endl;
  }
  else
  {
    // this->items.emplace(item.tipo, item);
    std::cout << "[+] Item " << item.nome << " adicionado e uma novo tipo cadastrado com sucesso!" << std::endl;
  }
}

FactoryItem::FactoryItem(std::string &_file)
{
  this->file = _file;
  std::cout << "Factory criada" << std::endl;
}

void FactoryItem::Factory(std::string &filename)
{
  std::ifstream file;
  std::cout << "File: " << filename << std::endl;
  file.open(filename);
  if (!file.is_open())
  {
    throw std::ifstream::failure("Falhou para abrir o arquivo");
  }

  unsigned lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');

  std::cout << "Line count: " << lineCount << std::endl;
  file.close();
  this->removeLine(filename);
  std::vector<std::string> instanceValues;
  for (unsigned i = 0; i < lineCount; ++i)
  {
    std::cout << "chegou aqui" << std::endl;
    try
    {
      Factory::factory(filename, instanceValues);
      auto item = this->create(instanceValues);

      std::cout << "Creating item: " << item.id << std::endl;

      this->populateItems(item);
    }
    catch (const std::exception &ex)
    {
      std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
  }
}
