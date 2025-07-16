#include"WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal(), _type("WrongCat")
{
    std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Default Destructor Called" << std::endl;
}

WrongCat WrongCat::operator=(const WrongCat& copy)
{
    std::cout << "Copy Assignemenåt Operator WrongCat Called" << std::endl;
    this->_type = copy._type;
    return *this;
} 

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
    *this = copy;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat is meowing ..."<< std::endl;
}

std::string WrongCat::getType() const{
    return _type;
}