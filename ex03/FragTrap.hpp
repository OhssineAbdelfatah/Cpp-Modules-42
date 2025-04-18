#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include"ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private :
        FragTrap();

    public :
        void highFivesGuys(void);
        FragTrap(std::string name);

        FragTrap(const FragTrap& copy );
        FragTrap& operator=(const FragTrap& copy );
        
        ~FragTrap();
};

#endif