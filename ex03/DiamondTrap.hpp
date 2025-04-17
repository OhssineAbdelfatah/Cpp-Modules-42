#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include"FragTrap.hpp"
#include"ScavTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap 
{
    private :
        std::string _Name;
    public :
        DiamondTrap(std::string );
        DiamondTrap(const DiamondTrap& );
        void operator=(const DiamondTrap& );
        ~DiamondTrap();

        void whoAmI();
};

#endif 