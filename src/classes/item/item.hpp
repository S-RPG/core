#ifndef ITEM_H
#define ITEM_H

#include <string>

/**
 * @brief Enumeração dos tipos de item.
 */
enum class TipoItem {
    ALIMENTO,               /**< Item de alimento. */
    ARMA,                   /**< Item de arma. */
    ENTRETENIMENTO,         /**< Item de entretenimento. */
    FERRAMENTA,             /**< Item de ferramenta. */
    HIGIENE,                /**< Item de higiene. */
    PRIMEIROS_SOCORROS      /**< Item de primeiros socorros. */
};

/**
 * @brief Estrutura que representa um item.
 */
struct Item {
    std::string nome;       ///< Nome do item.
    TipoItem tipo;          ///< Tipo do item.
    bool consumivel;        ///< Indica se o item é consumível.
    float preco;            ///< Preço do item.
    double vitalidade;      ///< Valor de vitalidade do item.
    double sanidade;        ///< Valor de sanidade do item.
    unsigned quantidade;    ///< Quantidade do item disponível.
    unsigned id;            ///< ID único do item.
};

#endif