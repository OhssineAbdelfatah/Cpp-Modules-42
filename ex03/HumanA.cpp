#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA()
{
    std::cout << "HumanA default Constructer" << std::endl;
}

HumanA::~HumanA(){
    std::cout << "HumanA Destructer" << std::endl;
}

HumanA::HumanA(std::string name , Weapon &weapon)
{
    _name = name;
    _weaponHumanA = weapon;
    std::cout << "HumanA Parametrized Constructer" << std::endl;
}

void HumanA::attack()
{
    std::cout << _name ;
    std::cout << " attacks with their " ;
    std::cout << _weaponHumanA.getType();
}