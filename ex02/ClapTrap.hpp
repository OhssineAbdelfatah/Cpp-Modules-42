#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include<string>

class ClapTrap{
    protected :
        // Name, which is passed as a parameter to the constructor
        std::string _Name;
        // • Hit points (10), representing the health of the ClapTrap
        unsigned _HitPoint;
        // • Energy points (10)
        unsigned int _EnergyPoint;
        // • Attack damage (0)
        unsigned int _AttackDamage;
    public :
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& copy );
        ClapTrap& operator=(const ClapTrap& copy );


        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};
#endif