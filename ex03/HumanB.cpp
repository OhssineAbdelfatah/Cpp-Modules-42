#include "HumanB.hpp"

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
}