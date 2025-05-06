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
    }
    catch(const Bureaucrat::GradeTooHighException& grd)
    {
        std::cout << "Exception : " << grd.what() << std::endl ;
    }
    catch(const Bureaucrat::GradeTooLowException& grd)
    {
        std::cout << "Exception : " << grd.what() << std::endl ;
    }
    // catch(const Bureaucrat::Exception& grd)
    // {
    //     std::cout << "Exception : " << grd.what() << std::endl ;
    // }
}