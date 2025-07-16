#ifndef BRAIN_HPP
#define BRAIN_HPP
#include<iostream>

class Brain 
{
    protected:
        std::string* ideas;
    public:
        Brain();
        Brain(std::string );
        Brain(const Brain& );
        Brain& operator=(const Brain& );
        ~Brain();
        std::string* getIdeas() const;
};

#endif