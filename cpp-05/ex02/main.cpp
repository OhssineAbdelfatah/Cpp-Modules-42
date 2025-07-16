#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"


int main()
{

    try {
        ShrubberyCreationForm s1("abde");
        RobotomyRequestForm s2("boutayna");
        PresidentialPardonForm s3("boutayna");
        
        Bureaucrat b1(144, "Assis");
        Bureaucrat b2(136, "Assisexec");
        Bureaucrat b3(71, "Med");
        Bureaucrat b4(44, "Medexec");
        Bureaucrat b5(24, "Emp");
        Bureaucrat b6(4, "Empexec");

        s1.beSigned(b1);
        s2.beSigned(b3);
        s3.beSigned(b5);
        std::cout << s1 << std::endl ;
        std::cout << s2 << std::endl ;
        std::cout << s3 << std::endl ;
        s1.execute(b2);
        s2.execute(b4);
        s3.execute(b6);
		
        b2.executeForm(s1);
        b4.executeForm(s2);
        b6.executeForm(s3);
    }
    catch (AForm::Exception& excep){
        std::cout << excep.what() << std::endl;
    }
    return  0;
}