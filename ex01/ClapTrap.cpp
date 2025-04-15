#include"ClapTrap.hpp"
#include<iostream>

ClapTrap::ClapTrap(std::string name): _Name(name), _HitPoint(10), _EnergyPoint(10), _Attack(0)
{
    std::cout << "Constructor with name ClapTrap" << std::endl;
}

ClapTrap::ClapTrap()
{
    std::cout << "Default Constructor ClapTrap" << std::endl;
}


ClapTrap::~ClapTrap()
{
    std::cout << "Default Destructor ClapTrap" << std::endl;
}

// copy const
ClapTrap::ClapTrap(const ClapTrap& copy )
{
    std::cout << "Copy Const ClapTrap" << std::endl;
    this->_Name = copy._Name;
    this->_EnergyPoint = copy._EnergyPoint;
    this->_HitPoint = copy._HitPoint;
    this->_Attack = copy._Attack;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy )
{
    this->_Name = copy._Name;
    this->_EnergyPoint = copy._EnergyPoint;
    this->_HitPoint = copy._HitPoint;
    this->_Attack = copy._Attack;
    
    return *this;
}

// assig operator

void ClapTrap::attack(const std::string& target)
{
    if(_EnergyPoint > 0)
    {
        std::cout << _Name << " attacks ";
        std::cout << target << " ,causing ";
        std::cout << _Attack << " points of damage!";
        std::cout << std::endl;
        this->_EnergyPoint--;
        return ;
    }
    std::cout << "ClapTrap " << _Name << " is out of energy!";
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(_HitPoint <= amount)
    {
        std::cout << "ClapTrap " << _Name << " is dead!";
        std::cout << std::endl;
    }
    std::cout << "ClapTrap " << _Name << " take damage ";
    std::cout << amount;
    std::cout << std::endl;
    _HitPoint -= amount ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(_EnergyPoint > 0)
    {
        std::cout << _Name << " repaired ";
        std::cout << _Attack << " points of damage!";
        this->_EnergyPoint--;
        this->_HitPoint += amount;
        std::cout << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _Name << " is out of energy!";
    return ;
}