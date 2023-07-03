#ifndef ITME_H
#define ITEM_H

#include <iostream>
#include <string>

struct Item{
    std::string nome;
    double price;
    unsigned usos;
    float vitalidade;
    float sanidade;
};

//Cada item terá seu nome, preço e quantidade de usos
//O preço só é importante para a Loja, já que esse é o valor que ela ira cobrar pelo produto
//Os itens vendidos na loja terão seus usos cheios. Os que eventualmente forem encontrados, 
//podem estar gasto ex: Encontra um MedKit (1/3)

//A interação dos itens com a vitalidade e a sanidade são definidas nos momentos de usos
//relacionado a isso, eles só têm os valores de influência
//Ex1: Frango assado (V: 15%, S: 3)
//Comer o Frango Assado {Vatual += FrangoAssado.vitalidade; Satual += FrangoAssado.sanidade;}
//Ex2: Pão Mofado (V; -15%, S; -1)
//Comer o Pão Mofado {Vatual += PaoMofado.vitalidade; Satual += PaoMofado.sanidade;}

#endif