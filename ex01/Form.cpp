#include"Form.hpp"

Form::Form():_Name("FormDef"),_Signed(false),_SignGrade(150),_ExecuteGrade(1)
{
    std::cout << "Form Default Constructor" << std::endl;
}
Form::Form(std::string name, int sGrade, int exGrade):_Name(name),_Signed(false),_SignGrade(sGrade),_ExecuteGrade(exGrade)
{
    std::cout << "Form Parametrized Constructor" << std::endl;
}

Form& Form::operator=(const Form& copy)
{
    this->_Signed = copy._Signed;
    // this->_ExecuteGrade = copy._ExecuteGrade;
    // this->_SignGrade = copy._SignGrade;
    return *this;
}

Form::Form(const Form& copy):_Name(copy.getName()),_Signed(false),_SignGrade(copy.getSigneGrade()),_ExecuteGrade(copy.getExecuteGrade())
{
    *this = copy;
}

Form::~Form()
{
    std::cout << "Form Default Destructor" << std::endl;
}

std::string Form::getName() const 
{
    return (this->_Name);
}

bool Form::getSignedStatus() const 
{
    return (this->_Signed);
}

int Form::getSigneGrade() const 
{
    return this->_SignGrade;
}
int Form::getExecuteGrade() const 
{
    return this->_ExecuteGrade ;
}


std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form <" << obj.getName() << "> ";
    if(obj.getSignedStatus())
        os << "is signed " ;
    else
        os << "is not signed " ;
    os << ", Signe Grade is " << obj.getSigneGrade() ;
    os << ", excute Grade is " << obj.getExecuteGrade() ;
}

const char* Form::Exception::what() 
{
    return ("Form exception : error !");
}

const char* Form::GradeTooHighException::what() 
{
    return ("Form exception : Grade too High !");
}

const char* Form::GradeTooLowException::what() 
{
    return ("Form exception : Grade too Low !");
}