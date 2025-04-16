#include"ScavTrap.hpp"
#include<iostream>


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
    std::cout << "Destructor ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy )
{
    std::cout << "Copy Constructor ScavTrap" << std::endl;
    *this = copy;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& copy )
{
    this->_Attack = copy._Attack;
    this->_EnergyPoint = copy._EnergyPoint;
    this->_HitPoint = copy._HitPoint;
    this->_Name = copy._Name;

    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _Name << " is now in Gate keeper mode.";
    std::cout << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(_EnergyPoint > 0)
    {
        std::cout << "[ScavTrap] " <<  _Name << " attacks ";
        std::cout << target << " , causing ";
        std::cout << _Attack << " points of damage!";
        std::cout << std::endl;
        this->_EnergyPoint--;
        return ;
    }
    std::cout << "ScavTrap " << _Name << " is out of energy!";
    return ;
}
