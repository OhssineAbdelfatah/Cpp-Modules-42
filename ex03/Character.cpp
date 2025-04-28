#include"Character.hpp"

Character::Character():_Name("characterX")
{
    this->currIndex = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        this->slots[i] = NULL;
    }
}

Character::Character(std::string name):_Name(name)
{
    this->currIndex = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        this->slots[i] = NULL;
    }
}

// need body
Character::Character(Character & const copy )
{
    (void)copy;
}

// need body
Character& Character::operator=(Character & const copy )
{
    (void)copy;
}

Character::~Character()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        if(this->slots[i])
            delete this->slots[i];
    }
    std::cout << "Character Destructed"<< std::endl;
}

std::string const & Character::getName() const 
{
    return this->_Name;
}

void equip(AMateria* m)
{

}
void unequip(int idx);
void use(int idx, Character& target);