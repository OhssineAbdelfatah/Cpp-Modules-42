#include"FragTrap.hpp"
#include<iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor with name FragTrap" << std::endl;
    this->_HitPoint = 100;
    this->_EnergyPoint = 50;
    this->_Attack = 20;
}

// FragTrap::FragTrap() : ClapTrap()
// {
//     std::cout << "Default Constructor FragTrap" << std::endl;
// }

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
    this->_Attack = copy._Attack;
    this->_EnergyPoint = copy._EnergyPoint;
    this->_HitPoint = copy._HitPoint;
    this->_Name = copy._Name;

    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "[FragTrap] " << _Name << " request positive high-Five";
    std::cout << std::endl;
}


