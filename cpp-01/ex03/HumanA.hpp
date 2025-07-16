#ifndef HUMANA_HPP
#define HUMANA_HPP
#include<iostream>
#include"Weapon.hpp"

class HumanA {
    private :
        std::string _name;
        Weapon &_weaponHumanA;

    public :
        HumanA();
        HumanA(std::string name, Weapon &waepon);
        ~HumanA();
        void attack();
};

#endif