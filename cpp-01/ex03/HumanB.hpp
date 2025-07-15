#ifndef HUMANB_HPP
#define HUMANB_HPP
#include<iostream>
#include"Weapon.hpp"

class HumanB {
    private :
        Weapon *_weaponHumanB;
        std::string _name;

    public :
        ~HumanB();
        void setWeapon(Weapon& weapon);
        HumanB(std::string name);
        void attack();
};

#endif