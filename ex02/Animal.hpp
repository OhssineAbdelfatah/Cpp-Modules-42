#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<iostream>

class Animal
{
    protected :
        std::string _type;
    public :
        virtual std::string getType() const = 0;    
        Animal();
        virtual ~Animal() = 0;

        Animal(const Animal&);
        Animal& operator=(const Animal& );
        virtual void makeSound() const = 0; // const , do not modify object state
};

#endif