#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_Grade(150), _Name("DefName"){
    std::cout << "default Constructor" << std::endl ;
}

Bureaucrat::Bureaucrat(int grade , std::string name):_Name(name)
{
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_Grade = grade ;
    std::cout << "Parametrized Constructor " << *this << std::endl ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    this->_Grade = copy._Grade;
    return *this ;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "default Destructor" << std::endl ;
}

std::string Bureaucrat::getName() const {
    return this->_Name;
}

int Bureaucrat::getGrade() const 
{
    return this->_Grade;
}

std::ostream& operator<<(std::ostream& os ,const Bureaucrat& emp) 
{
    os << "<" << emp.getName() << ">, bureaucrat grade <"<< emp.getGrade() << ">.";
    return os;
}

void Bureaucrat::upGrade()
{
    if(this->_Grade == 1 )
        throw Bureaucrat::GradeTooHighException();
    this->_Grade--;
}

void Bureaucrat::downGrade()
{
    if(this->_Grade == 150 )
        throw Bureaucrat::GradeTooHighException();
    this->_Grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("the Grade is too High to be used !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("the Grade is too Low to be used !");
}

const char* Bureaucrat::Exception::what() const throw()
{
    return ("Generic Exception");
}