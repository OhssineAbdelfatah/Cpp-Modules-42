#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include"AMateria.hpp"
#include"IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private :
        AMateria* source[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource & );
        MateriaSource& operator=(const MateriaSource &);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif 