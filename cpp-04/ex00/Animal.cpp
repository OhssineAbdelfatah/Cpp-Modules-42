#include"Animal.hpp"

Animal::Animal(): _type("animal")
{
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Default Destructor Called" << std::endl;
}

Animal Animal::operator=(const Animal& copy)
{
    std::cout << "Copy Assignement Operator Animal Called" << std::endl;
    this->_type = copy._type;
    return *this;
} 

Animal::Animal(const Animal& copy)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    *this = copy;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound..."<< std::endl;
}

std::string Animal::getType() const{
    return _type;
}

