#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter Default Constructor" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    // Destructor implementation
    std::cout << "ScalarConverter Default Destructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    // Copy constructor implementation
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    // Copy assignment operator implementation
    (void)other;
    return *this;
}

void ScalarConverter::convert(std::string literal)
{
    if(checkTypes(literal) == U_TYPE)
    {

        return ;
    }
}