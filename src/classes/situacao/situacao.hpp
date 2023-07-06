/// @file situacao.h
/// @brief Definição da classe Situacao
/// Este arquivo contém a definição da classe Situacao, responsável pelo gerenciamento da situação do jogo.
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

#ifndef SITUACAO_H
#define SITUACAO_H

#include "../decisao/decisao.hpp"

#include <string>
#include <map>

/// @brief Classe que representa uma situação no jogo.
class Situacao : Decisao
{
private:
  std::string _contexto;                  ///< O contexto da situação.
  std::map<char, Decisao> _decisoes;      ///< As decisões disponíveis na situação.
  std::string _titulo;                    ///< O título da situação.

public:
  
  /// @brief Construtor da classe Situacao.
  ///
  /// @param contexto O contexto da situação.
  /// @param decisoes As decisões disponíveis na situação.
  /// @param titulo O título da situação.
Situacao(std::string contexto, std::map<char, Decisao> decisoes, std::string titulo);

/// @brief Define o contexto da situação.
/// @param contexto O contexto da situação.
void setContexto(std::string contexto);

/// @brief Define uma decisão para a situação.
///
/// @param alternativa A alternativa da decisão.
/// @param decisao A decisão a ser definida.
void setDecisoes(char alternativa, Decisao decisao);

/// @brief Define o título da situação.
/// @param titulo O título da situação.
void setTitulo(std::string titulo);

/// @brief Obtém o contexto da situação.
/// @return O contexto da situação.
std::string getContexto();

/// @brief Obtém as decisões disponíveis na situação.
/// @return Um mapa com as decisões disponíveis, onde a chave é a alternativa da decisão e o valor é a própria decisão.
std::map<char, Decisao> getDecisoes();

/// @brief Obtém o título da situação.
/// @return O título da situação.
std::string getTitulo();
};

#endif
