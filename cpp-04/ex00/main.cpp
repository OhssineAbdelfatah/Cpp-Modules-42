#include<iostream>
#include"Animal.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"
#include"Cat.hpp"
#include"Dog.hpp"

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
    
    const WrongCat* iii = new WrongCat();
    std::cout << iii->getType() << " " << std::endl;  // Cat
    iii->makeSound(); //will output the WrongCat sound!
    delete iii; 

    return 0;
}
