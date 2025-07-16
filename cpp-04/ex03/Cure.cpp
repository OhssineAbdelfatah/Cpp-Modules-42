#include"Cure.hpp"

Cure::Cure(): AMateria("cure"), _type("cure")
{
    std::cout << "Materia type Constructed "+ this->_type << std::endl;
}

Cure::Cure(Cure const& copy):AMateria(copy)
{
    *this = copy ;
}

Cure& Cure::operator=(Cure const& copy)
{
    this->_type = copy._type;
    return *this;
}

Cure::~Cure()
{
    // std::cout << "Cure default Destructor" << std::endl;
}

AMateria* Cure::clone() const 
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

