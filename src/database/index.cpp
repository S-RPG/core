// #include "./factory-decisao.hpp"
// #include "./factory-dia.hpp"
#include "./factory-item.hpp"
// #include "./factory-situacao.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <memory>

// void startFactory(std::string &situacaoPath, std::string &decisoesPath, std::string &itemPath, std::string &diaPath)
void startFactory(std::string &itemPath)
{

  // std::ifstream file(situacaoPath);
  // if (!file.is_open())
  // {
  //   throw std::ifstream::failure("Falhou para abrir o arquivo de situacao");
  // }

  // std::shared_ptr factoryItem = std::make_shared<FactoryItem>();
  // std::shared_ptr factoryDecisao = std::make_shared<FactoryDecisao>();
  // std::shared_ptr factorySituacao = std::make_shared<FactorySituacao>();
  // std::shared_ptr factoryDia = std::make_shared<FactoryDia>();

  // factoryItem->Factory(itemPath);
  // factoryDecisao->Factory(decisoesPath);
  // factorySituacao->Factory(situacaoPath);
  // factoryDia->Factory(diaPath);
  FactoryItem factoryItem = FactoryItem(itemPath);

  factoryItem.Factory(itemPath);

  for (auto &item : factoryItem.items)
  {
    std::cout << "[+] Item " << item.first << " adicionado com sucesso!" << std::endl;
  }

  std::cout << "[+] Dados processados com sucesso!" << std::endl;
}

int main()
{
  std::string situacaoPath = "./documents/item_factory1.csv";
  startFactory(situacaoPath);
  return 0;
}
