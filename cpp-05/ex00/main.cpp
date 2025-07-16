#include"Bureaucrat.hpp"

int main()
{
    try
    {

        Bureaucrat employeeTooHigh(1, "Ahmed");
        Bureaucrat employeeTooLow(150, "Bouslam");

        std::cout << employeeTooHigh << std::endl;
        std::cout << employeeTooLow << std::endl;

        employeeTooHigh.upGrade();
        employeeTooLow.downGrade();
    }
    catch(const Bureaucrat::GradeTooHighException& grd)
    {
        std::cout << "Exception : " << grd.what() << std::endl ;
    }
    catch(const Bureaucrat::GradeTooLowException& grd)
    {
        std::cout << "Exception : " << grd.what() << std::endl ;
    }
    catch(const std::exception& grd)
    {
        std::cout << "Exception : " << grd.what() << std::endl ;
    }
}