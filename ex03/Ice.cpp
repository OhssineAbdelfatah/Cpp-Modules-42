#include"Ice.hpp"

Ice::Ice():_type("ice")
{
    std::cout << "Ice default Constructor" << std::endl;
}

Ice::Ice(Ice const& copy)
{
    *this = copy ;
}

Ice& Ice::operator=(Ice const& copy)
{
    this->_type = copy._type;
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice default Destructor" << std::endl;
}

AMateria* Ice::clone() const 
{
    return new Ice(*this);
}