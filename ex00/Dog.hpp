#ifndef DOG_HPP
#define DOG_HPP
#include<iostream>
#include"Animal.hpp"

class Dog: public Animal
{
    protected :
        std::string type;
    public :
        Dog();
        ~Dog();

        Dog(const Dog&);
        Dog operator=(const Dog& );
        void makeSound() const;
};

#endif