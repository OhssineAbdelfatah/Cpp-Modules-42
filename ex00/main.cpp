#include<iostream>

#include"Animal.hpp"
#include"Cat.hpp"
#include"Dog.hpp"

int main()
{
    Animal *dog1;

    dog1 = new Dog();
    dog1->makeSound();

    dog1 = new Cat();
    dog1->makeSound();

    dog1 = new Animal();
    dog1->makeSound();
    
    delete dog1;

}