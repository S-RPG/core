#ifndef ITEM_H
#define ITEM_H

#include <string>

<<<<<<< HEAD
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
=======
enum class TipoItem {
    ALIMENTO,
    ARMA,
    ENTRETENIMENTO,
    FERRAMENTA,
    HIGIENE,
    PRIMEIROS_SOCORROS
};

struct Item {

    std::string nome;
    TipoItem tipo;
    bool consumivel;
    float preco;
    double vitalidade;
    double sanidade;
    unsigned quantidade;
    unsigned id;
    
>>>>>>> 4d8dcea7650152a8f382b765db2e6749de6fa13e
};

#endif