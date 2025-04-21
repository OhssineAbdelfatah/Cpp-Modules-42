#include<iostream>
#include"Animal.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"
#include"Cat.hpp"
#include"Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    std::cout << std::endl;

    const Animal* j = new Dog();
    std::cout << std::endl;

    const Animal* i = new Cat();
    std::cout << std::endl;

    const WrongAnimal* ii = new WrongCat();
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;  // Dog
    std::cout << std::endl;

    std::cout << i->getType() << " " << std::endl;  // Cat
    std::cout << std::endl;

    std::cout << ii->getType() << " " << std::endl;  // Cat
    std::cout << std::endl;

    i->makeSound(); //will output the cat sound!
    std::cout << std::endl;

    ii->makeSound(); //will output the WrongCat sound!
    std::cout << std::endl;

    j->makeSound();
    std::cout << std::endl;

    meta->makeSound();
    std::cout << std::endl;

    delete i; 
    std::cout << std::endl;

    delete ii; 
    std::cout << std::endl;

    delete j; 
    std::cout << std::endl;

    delete meta; 
    std::cout << std::endl;

    return 0;
}

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