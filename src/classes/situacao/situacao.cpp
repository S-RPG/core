#include "situacao.hpp"
#include "../decisao/decisao.hpp"

Situacao::Situacao(std::string contexto, std::map<char, Decisao> decisoes, std::string titulo)
    : _contexto(contexto), _decisoes(decisoes), _titulo(titulo){};

void Situacao::setContexto(std::string contexto) { _contexto = contexto; };

void Situacao::setDecisoes(char alternativa, Decisao decisao) { _decisoes[alternativa] = decisao; };

void Situacao::setTitulo(std::string titulo) { _titulo = titulo; };

std::string Situacao::getContexto() { return _contexto; };

std::map<char, Decisao> Situacao::getDecisoes() { return _decisoes; };

std::string Situacao::getTitulo() { return _titulo; };
