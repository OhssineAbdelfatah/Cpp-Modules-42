#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include<iostream>
#include"AMateria.hpp"
#include"ICharacter.hpp"

class Character : public ICharacter
{
    private :
        std::string _Name;
        AMateria* slots[4];
        int currIndex;
    public:
        Character();
        Character(std::string );
        ~Character();
        Character(Character & const );
        Character& operator=(Character & const );

        std::string const & getName() const ;
        void equip(AMateria* m) ;
        void unequip(int idx) ;
        void use(int idx, Character& target) ;
};

#endif