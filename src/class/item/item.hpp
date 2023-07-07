/// @file item.h
/// @brief Definição da estrutura Item
///
/// Este arquivo contém a definição da estrutura Item, responsável pelo gerenciamento dos itens do jogo.
///
/// A estrutura Item possui informações sobre o nome, tipo, se é consumível ou utilitário,
/// preço, valores de vitalidade e sanidade proporcionados a um personagem, quantidade e ID de um item.
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
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>

///@brief Enumeração dos tipos de item.
enum TipoItem
{
    ALIMENTO,           /**< Item de alimento.                   */
    ARMA,               /**< Item de arma.                       */
    ENTRETENIMENTO,     /**< Item de entretenimento.             */
    FERRAMENTA,         /**< Item de ferramenta.                 */
    HIGIENE,            /**< Item de higiene.                    */
    PRIMEIROS_SOCORROS, /**< Item de primeiros socorros.         */
    NAO_IDENTIFICADO    /**< Item não identificado.              */
};

enum InteracaoItem
{
    USAR = 1,
    REMOVER = 2,
    REPARAR = 3,
    ADICIONAR_CARRINHO = USAR,
    REMOVER_CARRINHO = REMOVER,
    BEBER = USAR,
    COMER = USAR,
    LER = USAR,
    FUMAR = USAR,
    JOGAR = USAR,
    VESTIR = USAR,
    TIRAR = REMOVER,
};

///@brief Estrutura que representa um item.
typedef struct Item
{
    TipoItem tipo;                          /**< Tipo do item.                     */
    bool consumivel;                        /**< Indica se o item é consumível.    */
    float sanidade;                         /**< Valor de sanidade do item.        */
    float vitalidade;                       /**< Valor de vitalidade do item.      */
    float preco;                            /**< Preço do item.                    */
    std::string nome;                       /**< Nome do item.                     */
    unsigned id;                            /**< ID único do item.                 */
    unsigned quantidade;                    /**< Quantidade do item disponível.    */
    std::map<unsigned, std::string> opcoes; /**< Opções de interação com o item.   */

    Item(unsigned id, std::string nome, TipoItem tipo,
         float preco, float vitalidade, float sanidade,
         bool consumivel, unsigned quantidade,
         std::map<unsigned, std::string> opcoes)
        : id(id), nome(nome), tipo(tipo), preco(preco),
          vitalidade(vitalidade), sanidade(sanidade),
          consumivel(consumivel), quantidade(quantidade),
          opcoes(opcoes){};

    Item(unsigned id, std::string nome, TipoItem tipo,
         float preco, float vitalidade, float sanidade,
         bool consumivel, std::map<unsigned, std::string> opcoes)
        : id(id), nome(nome), tipo(tipo), preco(preco),
          vitalidade(vitalidade), sanidade(sanidade),
          consumivel(consumivel), opcoes(opcoes){};

    Item(Item &other)
        : id(other.id), nome(other.nome), tipo(other.tipo),
          preco(other.preco), vitalidade(other.vitalidade),
          sanidade(other.sanidade), consumivel(other.consumivel),
          quantidade(other.quantidade), opcoes(other.opcoes){};

    // Item &operator=(Item &other) = default;
};

#endif
