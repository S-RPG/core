/// @file factory_situacao.hpp
/// @brief Definição da classe FactorySituacao
/// 
/// Este arquivo contém a definição da classe FactorySituacao, responsável por criar instâncias da classe Situacao.
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

#ifndef FACTORY_SITUACAO_H
#define FACTORY_SITUACAO_H

#include "factory.hpp"
#include "../class/situacao/situacao.hpp"

#include <map>
#include <string>
#include <vector>
#include <memory>

/// @brief Classe responsável por criar instâncias da classe Situacao.
class FactorySituacao : public Factory<Situacao>, public Situacao
{
public:
    /// @brief Cria uma instância da classe Situacao com base nos valores fornecidos.
    /// @param instanceValues Os valores para criar a instância da classe Situacao.
    /// @return Um ponteiro único para a instância da classe Situacao criada.
    std::unique_ptr<Situacao> create(const std::vector<std::string> &instanceValues) override;

    /// @brief Cria um mapa de situações com base em um arquivo.
    /// @param filename O nome do arquivo contendo as situações.
    /// @return Um mapa de situações, onde a chave é o ID da situação e o valor é um vetor de instâncias de Situacao.
    std::map<unsigned, std::vector<Situacao>> Factory(std::string &filename);

    /// @brief Preenche o vetor de situações por dia com base em uma instância de Situacao.
    /// @param situacao A instância de Situacao a ser usada para preencher o vetor de situações por dia.
    void populateDia(const Situacao &situacao);

private:
    std::vector<Situacao> situacoes_dia;                         ///< Vetor de situações por dia.
    std::map<unsigned, std::vector<Situacao>> situacoes_dias;    ///< Mapa de todas as situações por dia.
};

#endif
