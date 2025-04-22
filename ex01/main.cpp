#include<iostream>
#include"Animal.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"Brain.hpp"

int main()
{
    Animal *animaux[10];

    for(int i = 0 ; i < 10 ; i++ )
    {
        if( i % 2 == 0 )
            animaux[i] = new Cat();
        else
            animaux[i] = new Dog();
    }

    for(int i = 0 ; i < 20 ; i++ )
        delete animaux[i];
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