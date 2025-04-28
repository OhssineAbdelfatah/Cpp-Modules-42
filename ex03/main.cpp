#include<iostream>
#include"Animal.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"Brain.hpp"

int main()
{
    Dog* anime;
    anime = new Dog("dog doggy dog ");

    // Access the ideas array of the Dog's Brain

    Dog* anime1  = new Dog("catatatat");
    Brain *br = anime1->getBrain();
    std::string *ideas = br->getIdeas();

    // Use the ideas array
    for (int i = 0; i < 100; i++)
    {
        std::cout << ideas[i] << std::endl;
    }

    delete anime;
    delete anime1;
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