#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "../item/item.hpp"
//#include "../personagem/personagem.hpp"
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <map>
#include <exception>
#include <iomanip>
#include <algorithm>



class InvalidConsumivelException : public std::exception{

    public:

         const char *what() const noexcept override;
};



class InvalidIdException : public std::exception{

    public:

        const char *what() const noexcept override;
    
};



class InvalidOptionException : public std::exception{

    public:

         const char *what() const noexcept override;
};




class InvalidQntException : public std::exception{

    public:
    
        InvalidQntException(const std::string &message);

        const char *what() const noexcept override;

    private:

        std::string _message;
};







class InvalidItemException : public std::exception{

    public:

     InvalidItemException(const std::string &message);


     const char *what() const noexcept override;
    
    private:

        std::string _message;
};










class Inventario {
   
    public:
        
        double getDinheiro();
        
        void exibir(); // exibe itens do inventário
        
        void armazenar(Item &item); // armazena itens comprados ou ganhos em eventos aleatórios

        void remover(); // remove itens do inventário 

        void consumir(); // consome uma quantidade x de um item e ganha/perde atributos




private:
    

    std::list<Item> _inventario; //map(ID, item - nome, quantidade, vitalidade, sanidade)
    
    double _setDinheiro();
    
    double _dinheiro; ///< Quantidade de dinheiro disponível
};


 #endif
