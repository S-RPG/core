<<<<<<< HEAD
/// @file factory_decisao.h
/// @brief Definição da classe FactoryDecisao
/// 
/// Este arquivo contém a definição da classe FactoryDecisao, responsável por criar instâncias da classe Decisao.
///
/// @version 1.0
/// @date 07/07/2023
/// 
/// @authors
/// - Alan Mota Calegari
/// - Davi de Carvalho Clark
/// - Gustavo Santiago de Magalhães
/// - Ricardo Augusto Costa Brito Moraes
/// - Washington Aparecido de Jesus Morais
///
#ifndef FACTORY_SITUACAO_H
#define FACTORY_SITUACAO_H
=======
#ifndef FACTORY_DECISAO_H
#define FACTORY_DECISAO_H
>>>>>>> eea5279892b944e5fd32b9ad4b93ceb73b93b764

#include "factory.hpp"
#include "factory-situacao.hpp"
#include "../class/decisao/decisao.hpp"

#include <map>
#include <string>
#include <vector>
#include <memory>

/// @brief Classe responsável por criar instâncias da classe Decisao.
class FactoryDecisao : public Factory<Decisao>
{
public:
<<<<<<< HEAD
    /// @brief Cria uma instância da classe Decisao com base nos valores fornecidos.
    /// @param instanceValues Os valores para criar a instância da classe Decisao.
    /// @return Um ponteiro único para a instância da classe Decisao criada.
    std::unique_ptr<Decisao> create(const std::vector<std::string> &instanceValues) override;

    /// @brief Cria um mapa de decisões com base em um arquivo.
    /// @param filename O nome do arquivo contendo as decisões.
    /// @return Um mapa de decisões, onde a chave externa é o ID da situação e a chave interna é a alternativa da decisão.
    std::map<unsigned, std::map<char, Decisao &>> Factory(std::string &filename);

    /// @brief Preenche as decisões com base em uma instância de Decisao.
    /// @param decisao A instância de Decisao a ser usada para preencher as decisões.
    void populateDecisoes(const Decisao &decisao);
=======
  std::shared_ptr<Decisao> create(const std::vector<std::string> &instanceValues) override;

  std::map<unsigned, std::map<char, Decisao>> Factory(std::string &filename);
  void populateDecisoes(const Decisao &decisao);
>>>>>>> eea5279892b944e5fd32b9ad4b93ceb73b93b764

  friend class FactorySituacao;

private:
<<<<<<< HEAD
    std::map<char, Decisao &> decisoes_dia;                    ///< Mapa de decisões por dia.
    std::map<unsigned, std::map<char, Decisao &>> decisoes;    ///< Mapa de todas as decisões.
=======
  std::map<char, Decisao &> decisoes_dia;
  static std::map<unsigned, std::map<char, Decisao>> decisoes;
>>>>>>> eea5279892b944e5fd32b9ad4b93ceb73b93b764
};

#endif
