#include "factory-item.hpp"
#include "factory-decisao.hpp"
#include "factory-situacao.hpp"
#include "factory-loja.hpp"

#include "../class/situacao/situacao.hpp"
#include "../class/item.hpp"

#include <iostream>

typedef struct Data
{
  std::map<unsigned, std::vector<Situacao>> &situacoes;
  std::vector<Item> &items;
  std::map<unsigned, std::vector<std::pair<char, Decisao>>> &decisoes;
  std::map<unsigned, std::vector<std::pair<unsigned, unsigned>>> &abastecimento;

  static Data factoryData()
  {
    {

      FactoryItem *fItem = new FactoryItem();

      fItem->create("src/database/itens_factory.csv");

      // std::cout << "ITENS: " << std::endl;
      // for (const auto &item : fItem->items)
      //   std::cout << item.id << " " << item.name << std::endl;

      FactoryDecisao *fDecisao = new FactoryDecisao();

      fDecisao->create("src/database/decisoes_factory.csv");

      // std::cout << "--- DECISOES ---" << std::endl;
      // for (auto decisoes : fDecisao->decisoes)
      // {
      //   std::cout << "D: " << decisoes.first << std::endl;
      //   std::cout << decisoes.second.size() << std::endl;
      //   for (auto it = decisoes.second.begin(); it != decisoes.second.end(); ++it)
      //     std::cout << "situacaoId: " << it->second.situacaoId << " - " << it->first << " " << it->second.texto << std::endl;
      // }

      FactorySituacao *fSituacao = new FactorySituacao();

      fSituacao->create("src/database/situacoes_factory.csv");
      std::size_t titleLenMax = 100;

      // std::cout << "--- SITUACOES ---" << std::endl;
      // for (auto dia : fSituacao->situacoes)
      // {
      //   std::cout << " -+-+-+-+ [DIA: " << dia.first << "] +-+-+-+- " << std::endl;
      //   for (auto situacoes : dia.second)
      //   {
      //     std::cout << "SITUACAO " << situacoes._id << " : " << std::endl;
      //     std::cout << situacoes.getTitulo(titleLenMax) + '\n'
      //               << std::endl;
      //     std::cout << situacoes.getContexto(titleLenMax) << std::endl;
      //     std::cout << situacoes.getDecisoes(titleLenMax) << std::endl;
      //     std::cout << "\n\n"
      //               << std::endl;
      //   }
      // }

      FactoryLoja *fLoja = new FactoryLoja();

      fLoja->create("src/database/abastecimento-loja.csv");

      Data data = {fSituacao->situacoes, fItem->items, fDecisao->decisoes, fLoja->abastecimento};

      // std::cout << "--- ABASTECIMENTO ---" << std::endl;
      // for (auto abastecimento : fLoja->abastecimento)
      // {
      //   std::cout << "Dia: " << abastecimento.first << std::endl;
      //   std::cout << abastecimento.second.size() << std::endl;
      //   for (auto it = abastecimento.second.begin(); it != abastecimento.second.end(); ++it)
      //     std::cout << "ItemId: " << it->first << " - Quantidade: " << it->second << std::endl;
      // }

      return data;
    }
  }
} Data;
