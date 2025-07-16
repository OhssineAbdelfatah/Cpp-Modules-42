#include"Character.hpp"

Character::Character():_Name("characterX")
{
    for(int i = 0 ; i < 4 ; i++)
    {
        this->slots[i] = NULL;
    }
}

Character::Character(std::string name):_Name(name)
{
    std::cout << "Character created [" + name +"]" << std::endl; 
    for(int i = 0 ; i < 4 ; i++)
    {
        this->slots[i] = NULL;
    }
}

// need body
Character::Character(const Character &  copy )
{
    for(int i = 0 ; i < 4 ; i++)
    {
        this->slots[i] = NULL;
    }
    *this = copy ;
}

// need body
Character& Character::operator=(const Character &  copy )
{
    this->_Name = copy._Name;
    for(int i = 0 ; i < 4 ; i++)
    {
        if( this->slots[i] )
        {
            delete this->slots[i];
            this->slots[i] = NULL;
        }
        if(copy.slots[i])
            this->slots[i] = copy.slots[i]->clone();
    }
    return *this;
}

Character::~Character()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        if(this->slots[i])
            delete this->slots[i];
    }
    // std::cout << "Character Destructed"<< std::endl;
}

std::string const & Character::getName() const 
{
    return this->_Name;
}

void Character::equip(AMateria* m)
{
    for( int i = 0 ; i < 4 ; i++ )
    {
        if(this->slots[i] ==  NULL )
        {   
            std::cout << "Character "+this->getName()+" equiped "+m->getType() << std::endl;
            this->slots[i] = m;
            return ;
        }
    }
}


void Character::unequip(int idx)
{
    if(idx >=0 && idx <= 3)
    {
        this->slots[idx] = NULL; // leaks in main should be freed
    }
}

void Character::use(int idx, ICharacter& target)
{
    if( idx >= 0 && idx <= 3 && this->slots[idx])
    {
        this->slots[idx]->use(target);
        delete this->slots[idx];
        this->slots[idx] = NULL ;
    }
}