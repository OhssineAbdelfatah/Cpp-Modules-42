#ifndef INTERN_HPP
#define INTERN_HPP
#include<string>
#include"AForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();

        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm* makeForm(std::string , std::string);

        class FormNameInvalidException : public AForm::Exception 
        {
            public :
                virtual const char* what() const throw();
        };
    private :
        static AForm* createRobotomyRequestForm(const std::string& target);
        static AForm* createShrubberyCreationForm(const std::string& target);
        static AForm* createPresidentialPardonForm(const std::string& target);
};

typedef AForm* (AForm::*t_func) (std::string ) ;

#endif 
