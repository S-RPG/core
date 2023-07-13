#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>

enum POLITICA_ENUM
{
  RESISTENCIA = 0,
  GOVERNO
};

typedef struct Personagem
{
  std::string name;
  float sanity;
  float vitality;
  POLITICA_ENUM policy;

} Personagem;

#endif
