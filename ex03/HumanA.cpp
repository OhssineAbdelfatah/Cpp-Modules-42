#include "HumanA.hpp"
#include <iostream>

// HumanA::HumanA()
// {
//     std::cout << "HumanA default Constructer" << std::endl;
// }

HumanA::~HumanA(){
    std::cout << "Deconstructer of Class HumanA" << std::endl;
}

HumanA::HumanA(std::string name , Weapon& weapon): _name(name) ,_weaponHumanA(weapon) 
{
    // _name = name ; 
    // _weaponHumanA = &weapon ;
    std::cout << "HumanA Parametrized Constructer" ;
    std::cout << std::endl;
}

void HumanA::attack()
{
    std::cout << _name ;
    std::cout << " attacks with their " ;
    std::cout << _weaponHumanA.getType();
    std::cout << std::endl;
}