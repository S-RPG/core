/// @file decisao.hpp
/// @brief Definição da estrutura Decisao 
/// Este arquivo contém a definição da estrutura Decisao, responsável pelo gerenciamento das decisões do jogo.
///
/// A estrutura Decisao possui informações sobre a alternativa, impacto na sanidade, impacto na vitalidade e texto de uma decisão.
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
#ifndef DECISAO_H
#define DECISAO_H

#include <string>

/// @brief Estrutura que representa uma decisão no jogo.
struct Decisao
{
private:
  char _alternativa;                ///< A alternativa da decisão.
  double _impactoSanidade;          ///< O impacto na sanidade da decisão.
  double _impactoVitalidade;        ///< O impacto na vitalidade da decisão.
  std::string _texto;               ///< O texto da decisão.

public:
  /// @brief Construtor padrão da estrutura Decisao.
  Decisao();

  /// @brief Construtor da estrutura Decisao.
  /// 
  /// @param alternativa A alternativa da decisão.
  /// @param impactoSanidade O impacto na sanidade da decisão.
  /// @param impactoVitalidade O impacto na vitalidade da decisão.
  /// @param texto O texto da decisão.
  Decisao(char alternativa, double impactoSanidade, double impactoVitalidade, std::string texto);

  /// @brief Define a alternativa da decisão.
  /// @param alternativa A alternativa da decisão.
  void setAlternativa(char alternativa);

  /// @brief Define o impacto na sanidade da decisão.
  /// @param impactoSanidade O impacto na sanidade da decisão.
  void setImpactoSanidade(char impactoSanidade);

  /// @brief Define o impacto na vitalidade da decisão.
  /// @param impactoVitalidade O impacto na vitalidade da decisão.
  void setImpactoVitalidade(char impactoVitalidade);

  /// @brief Define o texto da decisão.
  /// @param texto O texto da decisão.
  void setTexto(std::string texto);

  /// @brief Obtém a alternativa da decisão.
  /// @return A alternativa da decisão.
  char getAlternativa();

  /// @brief Obtém o impacto na sanidade da decisão.
  /// @return O impacto na sanidade da decisão.
  double getImpactoSanidade();

  /// @brief Obtém o impacto na vitalidade da decisão.
  /// @return O impacto na vitalidade da decisão.
  double getImpactoVitalidade();

  /// @brief Obtém o texto da decisão.
  /// @return O texto da decisão.
  std::string getTexto();
};

#endif
