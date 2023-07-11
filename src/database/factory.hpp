#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include <vector>

template <typename... Args>
class IFactory
{
public:
  virtual void create(Args...) = 0;
  virtual ~IFactory() = default;
};

#endif
