#include<iostream>
#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include"FragTrap.hpp"
#include"DiamondTrap.hpp"

int main()
{
    ClapTrap b("ohssine");
    b.attack("10");

    ScavTrap a("abdelfatah");
    a.beRepaired(10);
    a.attack("10");
    a.guardGate();   

    FragTrap c("abohssine");
    c.attack("fragtttt");
    c.highFivesGuys();

    DiamondTrap cv();
}