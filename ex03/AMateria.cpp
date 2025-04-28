#include"AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type)
{
    std::cout << "AMateria Constructed with type " << type << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

AMateria::AMateria(AMateria const & copy)
{
    *this = copy ;
}
AMateria& AMateria::operator=(AMateria const &copy)
{
    this->_type = copy._type;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria Default Destructor" << std::endl;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria use ..." << std::endl ;
}
