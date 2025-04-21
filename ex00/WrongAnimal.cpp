#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
    std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Default Destructor Called" << std::endl;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal& copy)
{
    std::cout << "Copy Assignement Operator WrongAnimal Called" << std::endl;
    this->_type = copy._type;
    return *this;
} 

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
    *this = copy;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound..."<< std::endl;
}

std::string WrongAnimal::getType() const{
    return _type;
}

