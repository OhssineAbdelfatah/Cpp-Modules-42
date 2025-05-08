#include"Bureaucrat.hpp"
#include"Form.hpp"

int main()
{
    try
    {

        Bureaucrat employeeTooHigh(1, "Ahmed");
        Bureaucrat employeeTooLow(150, "Bouslam");
        Form f1("form1", 6,6);
        Form f2("form2", 6,6);

        std::cout << employeeTooHigh << std::endl;
        std::cout << employeeTooLow << std::endl;
        // employeeTooLow.upGrade();
        employeeTooLow.downGrade();
        std::cout << employeeTooLow << std::endl;
        employeeTooHigh.signForm(f1);
        employeeTooLow.signForm(f2);
    }
    catch(const Bureaucrat::GradeTooHighException& grd)
    {
        std::cout << "Exception : " << grd.what() << std::endl ;
    }
    catch(const Bureaucrat::GradeTooLowException& grd)
    {
        std::cout << "Exception : " << grd.what() << std::endl ;
    }
    catch(const Form::Exception& grd)
    {
        std::cout << "Exception : " << grd.what() << std::endl ;
    }
}