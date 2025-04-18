#include"FragTrap.hpp"
#include<iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor with name FragTrap" << std::endl;
    this->_HitPoint = 100;
    this->_EnergyPoint = 50;
    this->_AttackDamage = 20;
}

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default Constructor FragTrap" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy ): ClapTrap(copy)
{
    std::cout << "Copy Constructor FragTrap" << std::endl;
    *this = copy;
}
FragTrap& FragTrap::operator=(const FragTrap& copy )
{
    this->_AttackDamage = copy._AttackDamage;
    this->_EnergyPoint = copy._EnergyPoint;
    this->_HitPoint = copy._HitPoint;
    this->_Name = copy._Name;

    return *this;
}

void FragTrap::highFivesGuys(void)
{
    if(_EnergyPoint <= 0)
    { 
        std::cout << "[FragTrap] out of energy" << std::endl;
        return ;
    }
    std::cout << "[FragTrap] " << _Name << " high-Five everybody @_@ ";
    std::cout << std::endl;
    _EnergyPoint -= 1;
}


