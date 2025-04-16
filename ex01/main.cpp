#include<iostream>
#include"ClapTrap.hpp"
#include"ScavTrap.hpp"

int main()
{
    ScavTrap a("abdelfatah");
    ClapTrap b("ohssine");
    a.beRepaired(10);
    a.attack("10");
    b.attack("10");
    a.guardGate();   
}