#include<iostream>

#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"



/*
    * wrongAnimal and wrongCat
    There should be an example with a WrongAnimal and WrongCat that don't
    use the virtual keyword (see subject).
    The WrongCat must output the WrongCat makeSound() only when used as a
    wrongCat.

*/
// int main()
// {
//     Animal *d1;
//     Cat *d2;
//     Dog *d3;

//     d2 = new Cat();
//     d3 = new Dog();

//     d1 = new Dog();
//     d1->makeSound();

//     d1 = new Cat();
//     d1->makeSound();

//     d1 = new Animal();
//     d1->makeSound();
    
//     d2->makeSound();
//     d3->makeSound();


//     delete d1;
// }

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl
    ;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    return 0;
}