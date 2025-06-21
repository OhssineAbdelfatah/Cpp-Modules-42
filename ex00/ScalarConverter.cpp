#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other)
        return *this;
    return *this;
}

void ScalarConverter::convert(std::string literal)
{
    /* here start the conversion */
    // parse to get type 
    if(getType(literal) == DOUBLE)
        std::cout << "double" << std::endl;
    else if(getType(literal) == FLOAT)
        std::cout << "float" << std::endl;
    else if(getType(literal) == ERROR)
        std::cout << "not a type" << std::endl;
    else if(getType(literal) == CHAR)
        std::cout << "char" << std::endl;
    else if(getType(literal) == INT)
        std::cout << "int" << std::endl;
    printChar(literal);
    // print it in four forms (double ,int ,char ,float)
        // each one need to handeled separatley
    printValues(literal);
}