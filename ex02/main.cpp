#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"

int main()
{
    try {

        ShrubberyCreationForm s1("abde");
        Bureaucrat b1(144, "taouil");
        s1.beSigned(b1);
        Bureaucrat b2(136, "taouil");
        std::cout << s1.getSignedStatus() << std::endl ;
        s1.execute(b2);
    }
    catch (AForm::Exception& excep){
        std::cout << excep.what() << std::endl;
    }
    return  0;
}