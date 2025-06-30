#include"ScalarConverter.hpp"
#include<iostream>

int main(int ac, char *av[])
{
    if(ac == 2){
        // ScalarConverter::convert(av[1]);
        (void)av;
        std::cout << isdigit('a') << std::endl;
    }
    else
        std::cout << "format : ./cpp06 balabla" << std::endl;
}