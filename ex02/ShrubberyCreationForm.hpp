#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm 
{
    private :
        const std::string _Target;
    public :
        // orthodox
        ShrubberyCreationForm(std::string);
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
        ~ShrubberyCreationForm();

        void execute(const Bureaucrat&) const ;
        std::string getTarget() const;
};
#endif

/* 
• ShrubberyCreationForm: 
    Required grades: sign 145, exec 137
    Creates a file <target>_shrubbery in the working directory 
    and writes ASCII trees
    inside it. 
*/