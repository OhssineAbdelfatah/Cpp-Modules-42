#include"Dog.hpp"

Dog::Dog():Animal(), _type("Dog")
{
    _type = "Dog";
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Default Destructor Called" << std::endl;
}

Dog Dog::operator=(const Dog& copy)
{
    std::cout << "Copy Assignement Operator Dog Called" << std::endl;
    this->_type = copy._type;
    return *this;
} 

Dog::Dog(const Dog& copy): Animal(copy)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = copy;
}

void Dog::makeSound() const
{
    std::cout << "Dog is barking ..."<< std::endl;
}


std::string Dog::getType() const{
    return _type;
}