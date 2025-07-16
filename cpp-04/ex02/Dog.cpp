#include"Dog.hpp"

Dog::Dog():Animal(), _type("Dog")
{
    this->brina = new Brain();
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(std::string idea):Animal(), _type("Dog")
{
    this->brina = new Brain(idea);
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
    delete ( this->brina );
    std::cout << "Dog Default Destructor Called" << std::endl;
}

Dog Dog::operator=(const Dog& copy)
{
    delete (this->brina);
    this->brina = new Brain();
    this->brina = copy.brina;
    this->_type = copy._type;
    std::cout << "Copy Assignement Operator Dog Called" << std::endl;
    return *this;
} 

Dog::Dog(const Dog& copy): Animal(copy)
{
   this->brina = NULL;
    *this = copy;
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog is barking ..."<< std::endl;
}


std::string Dog::getType() const{
    return _type;
}  


Brain* Dog::getBrain() const {
    return this->brina;
} 
