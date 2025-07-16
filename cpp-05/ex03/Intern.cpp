#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern& other) {
    // Copy constructor implementation
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    // Copy assignment operator implementation
    (void)other;
    return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    struct FormPair {
        const char* name;
        AForm* (*create)(const std::string&);
    };

    static FormPair formPairs[] = {
        { "robotomy request", &createRobotomyRequestForm },
        { "shrubbery creation", &createShrubberyCreationForm },
        { "presidential pardon", &createPresidentialPardonForm }
        };

    for (size_t i = 0; i < sizeof(formPairs) / sizeof(FormPair); ++i) {
        if (formName == formPairs[i].name) {
            AForm* form = formPairs[i].create(target);
            std::cout << "Intern creates <" << form->getName() << ">" << std::endl;
            return form;
        }
    }
    throw FormNameInvalidException();
}

const char* Intern::FormNameInvalidException::what() const throw()
{
    return "Intern Exception : Form name not exist on my dataset !";
}   

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}