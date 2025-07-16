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
