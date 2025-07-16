#ifndef DOG_HPP
#define DOG_HPP
#include<iostream>
#include"Animal.hpp"
#include"Brain.hpp"

class Dog: public Animal
{
    private :
        Brain* brina;
    protected :
        std::string _type;
    public :
        std::string getType() const ;    
        Dog();
        Dog(std::string);
        ~Dog();

        Dog(const Dog&);
        Dog operator=(const Dog& );
        void makeSound() const;
        Brain* getBrain() const;

};

#endif