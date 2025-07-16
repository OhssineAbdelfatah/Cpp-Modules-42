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

    Dog* anime1  = new Dog("catatatat");
    Brain *br = anime1->getBrain();
    std::string *ideas = br->getIdeas();

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    for (int i = 0; i < 100; i++)
    {
        std::cout << ideas[i] << std::endl;
    }

    delete anime;
    delete anime1;
    return 0;
}
