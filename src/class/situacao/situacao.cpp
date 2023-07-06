#include "situacao.hpp"

#include <string>

Situacao::Situacao(unsigned id, std::string titulo, std::string contexto, unsigned decisoesId, unsigned dia, unsigned situacaoConectadaId)
    : _contexto(contexto), _titulo(titulo), _decisoesId(decisoesId), _dia(dia), _id(id), _situacaoConectadaId(situacaoConectadaId){};

/**
 * Uma funcao que retorna uma string contendo o titulo do objeto
 * 'Situacao'. O comprimento do titulo e ajustado para caber dentro do dado
 * 'charMax' limite. A string resultante e centralizada pela adição de espacos no
 * inicio e fim.
 *
 * @param charMax o numero maximo de caracteres para a string resultante
 *
 * @return uma string contendo o titulo centralizado
 *
 * @throws None
 */
std::string Situacao::getTitulo(std::size_t charMax)
{
  std::size_t titleLen = _titulo.length();
  std::size_t tab = charMax / 2 - titleLen / 2;

  std::string title(tab, ' ');
  title.append(_titulo);
  title.append(tab, ' ');

  return title;
}

/**
 * Recupera as decisoes como uma string formatada.
 *
 * @param decisoes Um ponteiro para um mapa contendo as decisoes.
 *
 * @return Uma representacao de string das decisoes.
 */
std::string Situacao::getDecisoes(std::map<char, Decisao> *decisoes)
{
  std::string decisoesStr;
  std::size_t decisaoTextLenMax = 0;

  for (const auto &[ch, dec] : *decisoes)
  {
    std::size_t decisaoTextLen = dec.texto.size();
    if (decisaoTextLenMax < decisaoTextLen)
    {
      decisaoTextLenMax = decisaoTextLen;
    }
  }

  std::size_t tab = decisaoTextLenMax / 2;

  for (const auto &[ch, dec] : *decisoes)
  {
    std::string decisaoAlternativa(1, ch);
    std::size_t decisaoTextLen = dec.texto.size();

    if (decisaoAlternativa == "c")
    {
      decisoesStr.append("|\n|");
    }
    decisoesStr.append(decisaoAlternativa);
    decisoesStr.append(") ");

    decisoesStr.append(tab - decisaoTextLen / 2, ' ');
    decisoesStr.append(dec.texto);
    decisoesStr.append(tab - decisaoTextLen / 2, ' ');
    decisoesStr.append("|");
  }

  return decisoesStr;
}
