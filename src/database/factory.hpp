#ifndef FACTORY_H
#define FACTORY_H

#include <map>
#include <string>
#include <vector>

template <typename T>
class Factory
{
public:
  virtual T *create(std::vector<std::string> *instanceValues) = 0;

  std::vector<std::string> factory(const std::string &filename);

  std::string removeLine(const std::string &filename);
};

template <typename T>
std::vector<std::string> Factory<T>::factory(const std::string &filename)
{
  std::string topLine = this->removeLine(filename);

  std::string propValue;

  for (std::string::iterator it = topLine.begin(); it != topLine.end(); ++it)
  {
    if (*it == ';' || *it == '\n')
    {
      lineArray.push_back(propValue);
      propValue.erase();
    }
    else
    {
      propValue += *it;
    }
  }

  return lineArray;
};

template <typename T>
std::string Factory<T>::removeLine(const std::string &filename)
{
  std::ifstream file(filename);
  std::string topLine;
  std::string content;

  std::vector<std::string> lineArray;

  if (std::getline(file, topLine))
  {
    std::string line;
    while (std::getline(file, line))
      content += line + "\n";
  }

  file.close();

  std::ofstream outFile(filename);
  outFile << content;
  outFile.close();

  return topLine;
}
#endif
