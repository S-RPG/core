/// @file factory.h
/// @brief Definição da classe Factory
///
/// Este arquivo contém a definição da classe Factory, que é uma classe abstrata
/// para criação de objetos de um tipo genérico.
///
/// @version 1.0
/// @date Data de criação do arquivo
///
/// @authors
/// - Alan Mota Calegari
/// - Davi de Carvalho Clark
/// - Gustavo Santiago de Magalhães
/// - Ricardo Augusto Costa Brito Moraes
/// - Washington Aparecido de Jesus Morais

#ifndef FACTORY_H
#define FACTORY_H

#include <map>
#include <string>
#include <vector>
#include <memory>

template <typename T>
class Factory
{
public:
    virtual std::unique_ptr<T> create(const std::vector<std::string> &instanceValues) = 0;

    /// @brief Extrai linhas de um determinado arquivo e as retorna como um vetor de strings.
    ///
    /// @param filename O nome do arquivo para extrair as linhas.
    /// @return Um vetor de strings contendo os valores extraídos.
    /// @throws None.
    std::vector<std::string> factory(const std::string &filename);

    /// @brief Remove a primeira linha de um arquivo e a retorna.
    ///
    /// @param filename O nome do arquivo para remover a primeira linha.
    /// @return A primeira linha do arquivo que foi removida.
    /// @throws std::ifstream::failure se o arquivo não puder ser aberto.
    ///         std::ofstream::failure se o arquivo não puder ser gravado.
    std::string removeLine(const std::string &filename);
};

template <typename T>
std::vector<std::string> Factory<T>::factory(const std::string &filename)
{
    std::string topLine = this->removeLine(filename);

    std::vector<std::string> lineArray;
    std::string propValue;

    for (char c : topLine)
    {
        if (c == ';' || c == '\n')
        {
            lineArray.push_back(propValue);
            propValue.clear();
        }
        else
        {
            propValue += c;
        }
    }

    return lineArray;
}

template <typename T>
std::string Factory<T>::removeLine(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::ifstream::failure("Falhou para abrir o arquivo");
    }

    std::string topLine;
    std::string content;

    if (std::getline(file, topLine))
    {
        std::string line;
        while (std::getline(file, line))
        {
            content += line + "\n";
        }
    }

    file.close();

    std::ofstream outFile(filename);
    if (!outFile.is_open())
    {
        throw std::ofstream::failure("Falhou para abrir o arquivo para gravacao");
    }

    outFile << content;
    outFile.close();

    return topLine;
}

#endif
