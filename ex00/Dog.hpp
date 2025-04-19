#ifndef DOG_HPP
#define DOG_HPP
#include<iostream>
#include"Animal.hpp"

class Dog: public Animal
{
    protected :
        std::string _type;
    public :
         std::string getType() const ;    
        Dog();
        ~Dog();

        Dog(const Dog&);
        Dog operator=(const Dog& );
        void makeSound() const;
};

#endif