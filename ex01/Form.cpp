#include"Form.hpp"

Form::Form():_Name("FormDef"),_Signed(false),_SignGrade(100),_ExecuteGrade(10)
{
    // std::cout << "Form Default Constructor" << std::endl;
}

Form::Form(std::string name, int sGrade, int exGrade):_Name(name),_Signed(false),_SignGrade(sGrade),_ExecuteGrade(exGrade)
{
    if(sGrade > 150 || exGrade > 150)
        throw Form::GradeTooLowException();
    else if (sGrade < 1 || exGrade < 1)
        throw Form::GradeTooHighException();
    // std::cout << "Form Parametrized Constructor" << std::endl;
}

Form& Form::operator=(const Form& copy)
{
    if (this == &copy)
		return *this;
    return *this;
}

Form::Form(const Form& copy):_Name(copy.getName() + "_copy"),_Signed(false),_SignGrade(copy.getSigneGrade()),_ExecuteGrade(copy.getExecuteGrade())
{
    *this = copy;
}

Form::~Form()
{
    // std::cout << "Form Default Destructor" << std::endl;
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
    return os;
}

const char* Form::Exception::what() const throw()
{
    return ("Form exception : error !");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form exception : Grade too High !");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form exception : Grade too Low !");
}

bool Form::beSigned(Bureaucrat& emp)
{
    if(emp.getGrade() <= this->_SignGrade)
    {
        if(this->_Signed)
            return false;
        this->_Signed = true ;
        return true;
    }
    else
        throw Form::GradeTooLowException();
}