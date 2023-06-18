#include <situacao.hpp>

Situacao::Situacao(std::string contexto, std::map<char, Decisao> decisoes, std::string titulo)
    : _contexto(contexto), _decisoes(decisoes), _titulo(titulo){};

void Situacao::setContexto(std::string contexto){};

void Situacao::setDecisoes(char alternativa, Decisao decisao){};

void Situacao::setTitulo(std::string titulo){};
