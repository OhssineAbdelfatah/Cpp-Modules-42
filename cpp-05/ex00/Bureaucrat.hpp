#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include<iostream>

/*
    throw exeception in Constructor with wrong grade TooLow or TooHigh
    add getters getGrade() getName()
    add setters increaseGrade() decreaseGrade() => throw execiption
*/

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