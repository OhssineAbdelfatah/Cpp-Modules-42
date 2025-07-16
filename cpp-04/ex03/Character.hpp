#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include<iostream>
#include"AMateria.hpp"
#include"ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
    private :
        std::string _Name;
        AMateria* slots[4];
    public:
        Character();
        Character(std::string );
        ~Character();
        Character(const Character &  );
        Character& operator=(const Character & );

        std::string const & getName() const ;
        void equip(AMateria* m) ;
        void unequip(int idx) ;
        virtual void use(int idx, ICharacter& target) ;
};

#endif