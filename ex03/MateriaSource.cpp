#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
    for (size_t i = 0; i < 4 ; i++)
    {
        this->source[i] = NULL;
    }
}

MateriaSource::~MateriaSource() 
{
    for (size_t i = 0; i < 4 ; i++)
    {
        if(this->source[i])
            delete this->source[i] ;
    }
}


MateriaSource::MateriaSource(const MateriaSource &copy)
{
    for (size_t i = 0; i < 4 ; i++)
    {
        if(this->source[i])
            delete this->source[i] ;
    }
    *this = copy ;

}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
    for (size_t i = 0; i < 4 ; i++)
    {
        if(this->source[i]){
            delete this->source[i] ;
            this->source[i] = NULL;
        }
        if( copy.source[i] )
            this->source[i] = copy.source[i]->clone();

    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (size_t i = 0; i < 4; i++)
    {
        if(this->source[i] == NULL){
            this->source[i] = m ;
            return ;
        }
    }
    
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if( this->source[i] && this->source[i]->getType() == type )
            return this->source[i]->clone();
    }
    return NULL;
}