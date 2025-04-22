#include"Cat.hpp"

Cat::Cat():Animal(), _type("Cat")
{
    this->brinwa = new Brain();
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
    delete (this->brinwa);
    std::cout << "Cat Default Destructor Called" << std::endl;
}

Cat Cat::operator=(const Cat& copy)
{
    delete(this->brinwa);
    this->brinwa = new Brain();
    this->brinwa = copy.brinwa;
    this->_type = copy._type;
    std::cout << "Copy Assignement Operator Cat Called" << std::endl;
    return *this;
} 

Cat::Cat(const Cat& copy)
{
    this->brinwa = NULL;
    *this = copy;
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat is meowing ..."<< std::endl;
}

std::string Cat::getType() const{
    return _type;
}