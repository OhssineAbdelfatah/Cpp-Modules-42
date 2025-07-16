#include"Cat.hpp"

Cat::Cat():Animal(), _type("Cat")
{
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Default Destructor Called" << std::endl;
}

Cat Cat::operator=(const Cat& copy)
{
    std::cout << "Copy Assignemenåt Operator Cat Called" << std::endl;
    this->_type = copy._type;
    return *this;
} 

Cat::Cat(const Cat& copy): Animal(copy)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    *this = copy;
}

void Cat::makeSound() const
{
    std::cout << "Cat is meowing ..."<< std::endl;
}

std::string Cat::getType() const{
    return _type;
}