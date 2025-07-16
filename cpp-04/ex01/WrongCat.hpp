#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include<iostream>
#include"WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    protected :
        std::string _type;
    public :
        std::string getType() const ;    
        WrongCat();
        ~WrongCat();

        WrongCat(const WrongCat&);
        WrongCat operator=(const WrongCat& );
        void makeSound() const;

};

#endif