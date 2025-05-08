#include"AForm.hpp"

AForm::AForm():_Name("AForm"),_Signed(false),_SignGrade(150),_ExecuteGrade(1)
{
    // std::cout << "AForm Default Constructor" << std::endl;
}

AForm::AForm(std::string name, int sGrade, int exGrade):_Name(name),_Signed(false),_SignGrade(sGrade),_ExecuteGrade(exGrade)
{
    if(sGrade > 150 || exGrade > 150)
        throw AForm::GradeTooLowException();
    else if (sGrade < 1 || exGrade < 1)
        throw AForm::GradeTooHighException();
    // std::cout << "AForm Parametrized Constructor" << std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
    // this->_Signed = copy._Signed;
    return *this;
}

AForm::AForm(const AForm& copy):_Name(copy.getName()),_Signed(false),_SignGrade(copy.getSigneGrade()),_ExecuteGrade(copy.getExecuteGrade())
{
    *this = copy;
}

AForm::~AForm()
{
    // std::cout << "AForm Default Destructor" << std::endl;
}

std::string AForm::getName() const 
{
    return (this->_Name);
}

bool AForm::getSignedStatus() const 
{
    return (this->_Signed);
}

int AForm::getSigneGrade() const 
{
    return this->_SignGrade;
}
int AForm::getExecuteGrade() const 
{
    return this->_ExecuteGrade ;
}


std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << "AForm <" << obj.getName() << "> ";
    if(obj.getSignedStatus())
        os << "is signed " ;
    else
        os << "is not signed " ;
    os << ", Signe Grade is " << obj.getSigneGrade() ;
    os << ", excute Grade is " << obj.getExecuteGrade() ;
    return os;
}

const char* AForm::Exception::what() const throw()
{
    return ("AForm exception : error !");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm exception : Grade too High !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm exception : Grade too Low !");
}

bool AForm::beSigned(Bureaucrat& emp)
{
    if(emp.getGrade() <= this->_SignGrade)
    {
        if(this->_Signed)
            return false;
        this->_Signed = true ;
        return true;
    }
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const {(void)executor;}
