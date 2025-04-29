#include<iostream>
#include"Animal.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"Ice.hpp"
#include"Cure.hpp"
#include"Brain.hpp"
#include"AMateria.hpp"
#include"Character.hpp"
#include"ICharacter.hpp"
#include"IMateriaSource.hpp"
#include"MateriaSource.hpp"

int main1()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}

int main()
{
    main1();
}

