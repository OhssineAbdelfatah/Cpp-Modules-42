/* 

PresidentialPardonForm:     
    Required grades: sign 25, exec 5
    Informs that <target> has been pardoned by Zaphod Beeblebrox.

 */

#ifndef  PRESIDENTIALPARDONFORM_HPP 
#define  PRESIDENTIALPARDONFORM_HPP 
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    private :
        const std::string _Target;
    public :
        // orthodox
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(const PresidentialPardonForm&);
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat&) const ;
        std::string getTarget() const;
};
#endif