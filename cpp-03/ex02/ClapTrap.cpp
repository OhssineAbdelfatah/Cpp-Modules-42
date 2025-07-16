#include"ClapTrap.hpp"
#include<iostream>

ClapTrap::ClapTrap(std::string name): _Name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
    std::cout << "ClapTrap Constructor called with name " << name << std::endl;
}

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default Constructor" << std::endl;
}


ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Default Destructor " << std::endl;
}

// copy const
ClapTrap::ClapTrap(const ClapTrap& copy )
{
    std::cout << "Copy Const ClapTrap" << std::endl;
    *this = copy ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy )
{
    this->_Name = copy._Name;
    this->_EnergyPoint = copy._EnergyPoint;
    this->_HitPoint = copy._HitPoint;
    this->_AttackDamage = copy._AttackDamage;
    
    return *this;
}

// assig operator

void ClapTrap::attack(const std::string& target)
{
    if(_EnergyPoint > 0)
    {
        std::cout << _Name << " attacks ";
        std::cout << target << " ,causing ";
        std::cout << _AttackDamage << " points of damage!";
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
        std::cout << amount << " points of damage!";
        this->_EnergyPoint--;
        this->_HitPoint += amount;
        std::cout << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _Name << " is out of energy!";
    return ;
}