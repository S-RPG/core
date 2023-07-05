#include "situacao.hpp"

#include <string>

Situacao::Situacao(std::string contexto, std::string titulo, unsigned decisoesId, unsigned dia, unsigned id, unsigned situacaoConectadaId)
    : _contexto(contexto), _titulo(titulo), _decisoesId(decisoesId), _dia(dia), _id(id), _situacaoConectadaId(situacaoConectadaId){};

std::string Situacao::getTitulo(std::size_t charMax)
{
  std::string title;

  std::size_t titleLen = _titulo.length();
  std::size_t tab = charMax / 2 - titleLen / 2;

  title.append(tab, ' ');
  title.append(_titulo);
  title.append(tab, ' ');

  return title;
};

std::string Situacao::getDecisoes(std::map<char, Decisao> *decisoes)
{
  std::string decisoesStr;
  std::size_t decisaoTextLenMax = 0;

  for (std::map<char, Decisao>::iterator it = decisoes->begin(); it != decisoes->end(); ++it)
  {
    std::size_t decisaoTextLen = it->second.texto.size();
    if (decisaoTextLenMax < decisaoTextLen)
    {
      decisaoTextLenMax = decisaoTextLen;
    }
  };

  std::size_t tab = decisaoTextLenMax / 2;

  for (std::map<char, Decisao>::iterator it = decisoes->begin(); it != decisoes->end(); ++it)
  {
    std::string decisaoAlternativa(1, it->first);
    std::size_t decisaoTextLen = it->second.texto.size();

    if (decisaoAlternativa == "c")
    {
      decisoesStr.append("|\n|");
    };
    decisoesStr.append(decisaoAlternativa);
    decisoesStr.append(") ");

    decisoesStr.append(tab - decisaoTextLen / 2, ' ');
    decisoesStr.append(it->second.texto);
    decisoesStr.append(tab - decisaoTextLen / 2, ' ');
    decisoesStr.append("|");
  };

  return decisoesStr;
};
