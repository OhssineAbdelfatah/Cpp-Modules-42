#ifndef HUMANA_HPP
#define HUMANA_HPP
#include<iostream>
#include"Weapon.hpp"

class HumanA {
    private :
        Weapon &_weaponHumanA;
        std::string _name;

    public :
        HumanA();
        HumanA(std::string name, Weapon &waepon);
        ~HumanA();
        void attack();
};

#endif