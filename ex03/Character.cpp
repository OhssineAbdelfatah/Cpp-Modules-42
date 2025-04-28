#include"Character.hpp"

Character::~Character()
{
    std::cout << ""<< std::endl;
}
std::string const & getName() const {

}
void equip(AMateria* m) ;
void unequip(int idx) ;
void use(int idx, Character& target)