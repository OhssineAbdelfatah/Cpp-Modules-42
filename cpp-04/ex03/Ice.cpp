#include"Ice.hpp"

Ice::Ice():AMateria("ice"),_type("ice")
{
    // std::cout << "Ice default Constructor" << std::endl;
    std::cout << "Materia type Constructed "+ this->_type << std::endl;
}

Ice::Ice(const Ice& copy):AMateria(copy)
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
    // std::cout << "Ice default Destructor" << std::endl;
}

AMateria* Ice::clone() const 
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "+ target.getName() +" *" << std::endl;
}
