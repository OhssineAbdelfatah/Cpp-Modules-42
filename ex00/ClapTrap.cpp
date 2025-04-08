#include"ClapTrap.hpp"
#include<iostream>

ClapTrap::ClapTrap(): _HitPoint(10), _EnergyPoint(10), _Attack(0)
{
    std::cout << "Default Const ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _Name(name)
{
    std::cout << "Param Const ClapTrap" << std::endl;
}


ClapTrap::~ClapTrap()
{
    std::cout << "Default Deconst ClapTrap" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(_HitPoint > 0 && _EnergyPoint > 0)
    {
        std::cout << _Name << " attacks ";
        std::cout << target << " ,causing ";
        std::cout << _Attack << " points of damage!";
        std::cout << std::endl;
        this->_EnergyPoint--;
    }

}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << _Name ;
    std::cout << _Attack << " points of damage!";
    std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    
    std::cout << _Name << " repaired ";
    std::cout << _Attack << " points of damage!";
    this->_EnergyPoint--;
    this->_HitPoint += amount;
    std::cout << std::endl;
}