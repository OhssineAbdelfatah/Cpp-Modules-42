#include"Brain.hpp"

Brain::Brain()
{
    stc::cout << "Brain Default Constructor Called" << std::endl ;
}

Brain::~Brain()
{
    stc::cout << "Brain Default Destructor Called" << std::endl ;
}

Brain::Brain(const Brain& copy)
{
    stc::cout << "Brain Copy Constructor Called" << std::endl ;
    for(int i ; i < 100 ;i++)
    {
        this->ideas[i] = copy.ideas[i];
    }
}

void Brain::operator=(const Brain& copy)
{
    stc::cout << "Brain Copy Assignment Operator Called"  << std::endl ;
    *this = copy;
}