#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include"ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
    
    public :
        void guardGate(); //ScavTrap is now in Gate keeper mode.
        ScavTrap(std::string name);
        ScavTrap();
        ~ScavTrap();
        
};
#endif