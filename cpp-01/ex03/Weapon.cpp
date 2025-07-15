#include "Weapon.hpp"

Weapon::~Weapon(){
    std::cout << "Deconstructer of Class Weapon" ;
    std::cout << std::endl;
}


Weapon::Weapon(std::string type)
{
    std::cout << "constructer of Class Weapon" ;
    std::cout << std::endl;
    _type = type;
}


void Weapon::setType(std::string type)
{
    _type = type;
};

std::string const &Weapon::getType()
{
    return _type;
};