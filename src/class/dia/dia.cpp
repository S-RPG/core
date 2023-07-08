#include "../dia/dia.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

Dia::Dia(unsigned dia, std::vector<Situacao> situacoes, std::vector<Item> newItemsByDay)
    : dia(dia), situacoes(situacoes), newItemsByDay(newItemsByDay){};

/**
 * Displays the menu centered on the screen.
 *
 * @param maxLen the maximum length of the screen
 *
 * @return void
 *
 * @throws None
 */
void Dia::showMenu(std::size_t maxLen)
{
  std::string menu = "(L)oja - (I)nventario - (S)aude - (D)ormir";
  std::string fMenu;

  std::size_t menuLen = menu.length();
  std::size_t tab = maxLen / 2 - menuLen / 2;

  fMenu.append(tab, ' ');
  fMenu.append(menu);
  fMenu.append(tab, ' ');

  std::cout << fMenu << std::endl;
};

/**
 * Returns the user's choice from a list of options.
 *
 * @return the user's choice as a char
 *
 * @throws None
 */
char Dia::getChoice()
{
  char choice;
  std::vector<char> choices = {'L', 'I', 'S', 'D'};

  std::cout << "Escolha uma opção: ";

  while (true)
  {
    std::cin >> choice;

    if (std::find(choices.begin(), choices.end(), choice) != choices.end())
      return choice;
  }

  return choice;
}
