#include "Harl.hpp"
#include <iostream>

void Harl::debug(void )
{
    std::cout << " ";
    std::cout << std::endl;
}
void Harl::info(void )
{
    std::cout << " ";
    std::cout << std::endl;
}
void Harl::warning(void )
{
    std::cout << " ";
    std::cout << std::endl;
}
void Harl::error(void )
{
    std::cout << " ";
    std::cout << std::endl;
}

void Harl::complain( std::string level )
{
    if( level.compare("ERROR") ){
        std::cout << " ";
        std::cout << " ";
    }
    else if(level.compare("WARNING")){

    }
    else if(level.compare("INFO")){

    }
    else if(level.compare("DEBUG")){

    }
}
