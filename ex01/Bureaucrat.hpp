#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include<iostream>
// #include"Form.hpp"

/*
    throw exeception in Constructor with wrong grade TooLow or TooHigh
    add getters getGrade() getName()
    add setters increaseGrade() decreaseGrade() => throw execiption
*/
class Form;
class Bureaucrat
{
    private:
    int  _Grade;
        const std::string _Name;
    public:
        Bureaucrat();
        Bureaucrat(int ,std::string);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);
        ~Bureaucrat();
        void signForm(Form &); // call beSigned()

        std::string getName() const ;
        int getGrade() const ;
        void upGrade();
        void downGrade();
    class Exception : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };

    class GradeTooHighException : public Bureaucrat::Exception
    {   public :
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public Bureaucrat::Exception
    {
        public :
            virtual const char* what() const throw();
    };
};
    
std::ostream& operator<<(std::ostream& os, const Bureaucrat&);

#endif