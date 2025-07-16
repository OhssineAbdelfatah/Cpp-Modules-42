#include"DiamondTrap.hpp"
#include<iostream>

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
    this->_Name = name;
    ClapTrap::_Name = name + "_clap_name";
    this->_HitPoint = FragTrap::_HitPoint;
    this->_EnergyPoint = ScavTrap::_EnergyPoint;
    this->_AttackDamage = FragTrap::_AttackDamage;
}

void DiamondTrap::operator=(const DiamondTrap& copy)
{
    this->_AttackDamage = copy._AttackDamage;
    this->_EnergyPoint = copy._EnergyPoint;
    this->_Name = copy._Name;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): FragTrap(copy),ScavTrap(copy)
{
    *this = copy;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Default Destructor" << std::endl ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Name : " << _Name ;
    std::cout << " ,ClapTrap::Name : " << ClapTrap::_Name ;
    std::cout << std::endl;
}