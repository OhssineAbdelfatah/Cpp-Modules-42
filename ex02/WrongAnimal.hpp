#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include<iostream>

class WrongAnimal
{
    protected :
        std::string _type;
    public :
        std::string getType() const ;    
        WrongAnimal();
        virtual ~WrongAnimal();

        WrongAnimal(const WrongAnimal&);
        WrongAnimal operator=(const WrongAnimal& );
        void makeSound() const; // const , do not modify object state
};

#endif