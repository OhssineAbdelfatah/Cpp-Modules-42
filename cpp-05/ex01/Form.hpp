#ifndef FORM_HPP
#define FORM_HPP
#include<iostream>
#include"Bureaucrat.hpp"

class Form
{
    private:
        const std::string _Name;
        bool _Signed;
        const int _SignGrade;
        const int _ExecuteGrade;
    public:
        Form();
        Form(std::string , int , int );
        Form(const Form&);
        Form& operator=(const Form&);
        ~Form();

        bool beSigned(Bureaucrat& );

        // getters 
        std::string getName() const ;
        bool getSignedStatus() const ;
        int getSigneGrade() const ;
        int getExecuteGrade() const ;

    class Exception : public std::exception {
        public :
            virtual const char* what() const throw();
    };

    class GradeTooHighException : public Form::Exception{
        public :
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public Form::Exception{
        public :
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& , const Form&);


#endif