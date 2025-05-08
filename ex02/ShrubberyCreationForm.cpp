#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name):_Name(name),_Signed(false),_SignGrade(145),_ExecuteGrade(137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy),_Name(copy.getName()),_Signed(false),_SignGrade(copy.getSigneGrade()),_ExecuteGrade(copy.getExecuteGrade())
{
    *this = copy ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    (void)  copy;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const 
{
    (void )executor;
}


std::string ShrubberyCreationForm::getName() const 
{
    return this->_Name;
}

bool ShrubberyCreationForm::getSignedStatus() const 
{
    return this->_Signed;
}

int ShrubberyCreationForm::getSigneGrade() const 
{
    return this->_SignGrade;
}

int ShrubberyCreationForm::getExecuteGrade() const 
{
    return this->_ExecuteGrade;
}