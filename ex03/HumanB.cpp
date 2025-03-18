#include "HumanB.hpp"

HumanB::~HumanB()
{
    std::cout << "Deconstructer of Class HumanB" ;
    std::cout << std::endl;
}

HumanB::HumanB(std::string name )
{
    _name = name ;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weaponHumanB = (&weapon);
}

void HumanB::attack()
{
    std::cout << _name ;
    std::cout << " attacks with their " ;
    std::cout << _weaponHumanB->getType();
    std::cout << std::endl;
}