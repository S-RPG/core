#include "situacao.hpp"

#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

bool Situacao::operator==(const Situacao &situacao)
{
  return this->_id == situacao._id;
}

Situacao::Situacao(){};

Situacao::Situacao(unsigned id, std::string titulo, std::string contexto, std::vector<std::pair<char, Decisao>> decisoes, unsigned dia, unsigned situacaoConectadaId)
    : _contexto(contexto), _titulo(titulo), _decisoes(decisoes), _dia(dia), _id(id), _situacaoConectadaId(situacaoConectadaId){};

Situacao::Situacao(unsigned id, std::string titulo, std::string contexto, std::vector<std::pair<char, Decisao>> decisoes, unsigned dia)
    : _contexto(contexto), _titulo(titulo), _decisoes(decisoes), _dia(dia), _id(id){};

std::string Situacao::getTitulo(std::size_t charMax)
{
  unsigned titleLen = _titulo.length();

  unsigned tab = ceil(charMax / 2 - titleLen / 2);
  tab = tab % 2 == 0 ? tab : ((tab + 1) % 2) == 0 ? tab + 1
                                                  : tab - 1;

  std::string title = "+";
  title.append(charMax, '-');
  title.append("+\n");
  title.append(tab, ' ');
  title.append(_titulo);
  title.append(tab, ' ');
  title.append("\n+");
  title.append(charMax, '-');
  title.append("+");

  return title;
}

std::string Situacao::getContexto(std::size_t charMax)
{
  float contextLen = _contexto.length() - 1.0;
  unsigned contextLines = ceil(contextLen / charMax);

  unsigned charLimit = charMax - 1;

  unsigned initLine = 0;
  _contexto.resize(_contexto.length() + 1, '\n');
  if (contextLines <= 1)
  {
    return _contexto;
  }
  for (unsigned i = 0; i < contextLines; ++i)
  {
    bool sameLine = true;
    while (sameLine)
    {
      if (_contexto.at(charLimit) == ' ')
      {
        _contexto.at(charLimit) = '\n';
        initLine = charLimit;
        charLimit = (2 * charLimit) <= (contextLen) ? (charLimit + charLimit) : contextLen;
        sameLine = false;
      }
      if (charLimit == contextLen)
      {
        initLine = charLimit;
        charLimit = (2 * charLimit) <= (contextLen - 1) ? (charLimit + charLimit) : contextLen;
        sameLine = false;
      }
      else
      {
        charLimit += 1;
      }
    };
  };

  return _contexto;
}

/**
 * Recupera as decisoes como uma string formatada.
 *
 * @param decisoes Um ponteiro para um mapa contendo as decisoes.
 *
 * @return Uma representacao de string das decisoes.
 */
std::string Situacao::getDecisoes(std::size_t charMax)
{
  std::string decisoesStr;
  std::size_t decisaoTextLenMax = 0;

  for (const auto &decisao : this->_decisoes)
  {
    std::size_t decisaoTextLen = decisao.second.texto.size();
    if (decisaoTextLenMax < decisaoTextLen)
    {
      decisaoTextLenMax = decisaoTextLen;
    }
  }

  std::size_t tab = decisaoTextLenMax;

  for (const auto &decisao : this->_decisoes)
  {
    char ch = decisao.first;
    std::string decisaoText = decisao.second.texto;

    std::string decisaoAlternativa(1, ch);
    std::size_t decisaoTextLen = decisaoText.size();

    if (decisaoAlternativa == "a")
    {
      decisoesStr.append(" ");
    }
    if (decisaoAlternativa == "c")
    {
      decisoesStr.append("\n ");
    }
    decisoesStr.append(decisaoAlternativa);
    decisoesStr.append(") ");

    // decisoesStr.append(tab - decisaoTextLen / 2, ' ');
    decisoesStr.append(decisaoText);
    decisoesStr.append(tab - decisaoTextLen / 2, ' ');
    decisoesStr.append(" ");
  }
  decisoesStr.append("\n");
  decisoesStr.append(charMax + 2, '_');

  return decisoesStr;
}
