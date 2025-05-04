#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include<iostream>

class Bureaucrat
{
    private:
        const std::string _Name;
        unsigned int  _Grade;
        /*
            throw exeception in Constructor with wrong grade TooLow or TooHigh
            add getters getGrade() getName()
            add setters increaseGrade() decreaseGrade() => throw execiption
        */
    public:
        Bureaucrat(/* args */);
        ~Bureaucrat();
};



#endif