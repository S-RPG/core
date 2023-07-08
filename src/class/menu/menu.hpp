#ifndef MENU_H
#define MENU_H

#include <string>

class Menu
{
public:
  virtual void showMenu(std::size_t maxLen) = 0;
  virtual char getChoice() = 0;
};

#endif
