
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
    private :
        const std::string _Target;
    public :
        // orthodox
        RobotomyRequestForm(std::string);
        RobotomyRequestForm(const RobotomyRequestForm&);
        RobotomyRequestForm& operator=(const RobotomyRequestForm&);
        ~RobotomyRequestForm();

        std::string getTarget() const;
        void execute(const Bureaucrat&) const ;
};
#endif