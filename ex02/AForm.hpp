#ifndef AFORM_HPP
#define AFORM_HPP
#include<iostream>
#include"Bureaucrat.hpp"

class AForm
{
    private:
        const std::string _Name;
        bool _Signed;
        const int _SignGrade;
        const int _ExecuteGrade;
    public:
        AForm();
        AForm(std::string , int , int );
        AForm(const AForm&);
        AForm& operator=(const AForm&);
        virtual ~AForm();
        virtual void execute(Bureaucrat const & executor) const = 0 ;

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

    class GradeTooHighException : public AForm::Exception{
        public :
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public AForm::Exception{
        public :
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& , const AForm&);


#endif