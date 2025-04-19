#include"Dog.hpp"

Dog::Dog():Animal(), type("Dog")
{
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Default Destructor Called" << std::endl;
}

Dog Dog::operator=(const Dog& copy)
{
    std::cout << "Copy Assignement Operator Dog Called" << std::endl;
    this->type = copy.type;
    return *this;
} 

Dog::Dog(const Dog& copy)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = copy;
}

void Dog::makeSound() const
{
    std::cout << "Dog is barking ..."<< std::endl;
}
