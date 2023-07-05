#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T>
class Factory
{
public:
  virtual T *create(std::vector<std::string>) = 0;

  virtual std::vector<std::string> getLine(FILE *file) = 0;

  virtual std::vector<std::string> getHeader(FILE *file) = 0;
};

#endif
