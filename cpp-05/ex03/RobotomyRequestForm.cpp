/* 

• RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.

 */

#include"RobotomyRequestForm.hpp"
static int percent = 0;

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotmyForm",72,45),_Target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy),_Target(copy._Target)
{
    *this = copy ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    (void)  copy;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_Target;
}


void RobotomyRequestForm::execute(const Bureaucrat & executor) const 
{
    if (!this->getSignedStatus() )
        throw RobotomyRequestForm::FormNotSignedException();
    if( executor.getGrade() > this->getExecuteGrade())
        throw RobotomyRequestForm::GradeTooLowException();
    else{
        if(percent++ % 2 == 0){
            std::cout << "DRRRRRRRRRRRRRRRR RRRRRRR RRRRRR" << std::endl;
            std::cout << this->getName() <<" has been robotomized" << std::endl;
        }
        else
            std::cout << "the robotomy failed." << std::endl;
    }
}
