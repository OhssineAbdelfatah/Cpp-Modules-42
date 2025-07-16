#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"



PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPForm",25,5),_Target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy),_Target(copy._Target)
{
    *this = copy ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    if (this == &copy)
		return *this;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}


std::string PresidentialPardonForm::getTarget() const {
    return this->_Target;
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const 
{
    if (!this->getSignedStatus() )
        throw PresidentialPardonForm::FormNotSignedException();
    if( executor.getGrade() > this->getExecuteGrade())
        throw PresidentialPardonForm::GradeTooLowException();
    else
        std::cout <<  "<" << this->getTarget() << "> has been pardoned by Zaphod Beeblebrox" << std::endl;
}