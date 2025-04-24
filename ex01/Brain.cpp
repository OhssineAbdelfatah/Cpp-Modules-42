#include"Brain.hpp"
#include<iostream>

Brain::Brain()
{   
    this->ideas = new std::string[100];
    for(int i = 0 ; i < 100 ; i++)
        this->ideas[i] = "brain and brainwa and brina " ;
    std::cout << "Brain Default Constructor Called" << std::endl ;
}

Brain::Brain(std::string idea)
{   
    this->ideas = new std::string[100];
    for(int i = 0 ; i < 100 ; i++)
        this->ideas[i] = idea ;
    std::cout << "Brain with string Constructor Called" << std::endl ;
}

Brain::~Brain()
{
    delete[] ( this->ideas);
    std::cout << "Brain Default Destructor Called" << std::endl ;
}

Brain::Brain(const Brain& copy)
{
    this->ideas = NULL;
    *this = copy;
    std::cout << "Brain Copy Constructor Called" << std::endl ;
}

Brain& Brain::operator=(const Brain& copy)
{
    delete (this->ideas);
    this->ideas = new std::string[100]; // this is deep copy
    for(int i = 0 ; i < 100 ;i++)
    {
        this->ideas[i] = copy.ideas[i]; // shallow copy
    }
    std::cout << "Brain Copy Assignment Operator Called" << std::endl ;
    return *this;
}

std::string* Brain::getIdeas() const
{
    return this->ideas;
}

