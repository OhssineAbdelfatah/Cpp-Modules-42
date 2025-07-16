#ifndef CURE_HPP
#define CURE_HPP
#include<iostream>
#include"AMateria.hpp"

class Cure : public AMateria
{
    private:
        std::string _type;
    public : 
        Cure();
        Cure(Cure const&);
        Cure& operator=(Cure const&);
        ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);


};

#endif