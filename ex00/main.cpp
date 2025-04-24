#include<iostream>
#include"Animal.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include<stdlib.h>

int main()
{
    const Animal* meta = new Animal();
    std::cout << meta->getType() << " " << std::endl;  // Dog
    meta->makeSound();
    delete meta;

    const Animal* j = new Dog();
    std::cout << j->getType() << " " << std::endl;  // Dog
    j->makeSound();
    delete j; 

    const Animal* i = new Cat();
    std::cout << i->getType() << " " << std::endl;  // Cat
    i->makeSound(); //will output the cat sound!
    delete i; 
    
    const WrongAnimal* ii = new WrongCat();
    std::cout << ii->getType() << " " << std::endl;  // Cat
    ii->makeSound(); //will output the WrongCat sound!
    delete ii; 

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




// class A
// {
//     public:
//         A(){std::cout << "default A Const\n";}
//         ~A(){std::cout << "default A Dest\n";}
// };

// class B : public A{
//     public:
//         B(){std::cout << "default A Const\n";}
//         ~B(){std::cout << "default A Dest\n";}
// };
