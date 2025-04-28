#ifndef ICE_HPP
#define ICE_HPP
#include<iostream>
#include"ICharacter.hpp"

class Ice : public AMateria
{
    private:
        std::string _type;
    public : 
        Ice();
        Ice(Ice const&);
        Ice& operator=(Ice const&);
        ~Ice();


        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif