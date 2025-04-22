#ifndef BRAIN_HPP
#define BRAIN_HPP
#include<iostream>

class Brain 
{
    protected:
        std::string* ideas;
    public:
        Brain();
        Brain(const Brain& );
        Brain& operator=(const Brain& );
        ~Brain();
};

#endif