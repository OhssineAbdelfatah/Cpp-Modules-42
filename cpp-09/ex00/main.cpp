#include<iostream>

#define BLUE "\033[34m"
#define RED "\033[31m"
#define DEF "\033[0m"
#define GREEN "\033[32m" 
#define PINK "\033[35m" 
#include "BitcoinExchange.hpp"

int main(int ac , char *av[]){
    // (void)av;
    if(ac != 2 )
        std::cerr << RED << " no file provided !!"<< DEF << std::endl;
    else {
        try{
            BitcoinExchange btc(av[1]);
            btc.readFile();
        }catch (std::exception& e){
            std::cout << "main : " << e.what() << std::endl;
        }
    }
}