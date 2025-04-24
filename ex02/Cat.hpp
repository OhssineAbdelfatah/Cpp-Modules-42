#ifndef CAT_HPP
#define CAT_HPP
#include<iostream>
#include"Animal.hpp"
#include"Brain.hpp"


class Cat: public Animal
{
    private : 
        Brain* brinwa;
    protected :
        std::string _type;
    public :
        std::string getType() const ;    
        Cat(std::string );
        Cat();
        ~Cat();

        Cat(const Cat&);
        Cat operator=(const Cat& );
        void makeSound() const;

};

#endif