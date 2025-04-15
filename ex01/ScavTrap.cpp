#include"ScavTrap.hpp"
#include<iostream>

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _Name << " is now in Gate keeper mode.";
    std::cout << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor with name ScavTrap" << std::endl;
    this->_HitPoint = 100;
    this->_EnergyPoint = 50;
    this->_Attack = 20;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Default Constructor ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Default Destructor ScavTrap" << std::endl;
}

ScavTrap::Attack()
{
    std::cout << "Default Destructor ScavTrap" << std::endl;
}
