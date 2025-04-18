#include<iostream>
#include"ClapTrap.hpp"
#include"ScavTrap.hpp"

int main()
{
    ClapTrap a("ohssine");
    ScavTrap b("abdelfatah");

    a.attack("nono");
    b.attack("nono");

    a.beRepaired(10);
    b.beRepaired(10);

    a.takeDamage(8);
    a.takeDamage(8);

    b.guardGate();
}