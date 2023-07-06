#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "../../src/classes/decisao/decisao.hpp"

TEST_CASE("Decisao"){
  Decisao* decisaoA = new Decisao('a', 1, 0, "Decisao A");
  
  CHECK(decisaoA->getAlternativa() == 'a');


};

