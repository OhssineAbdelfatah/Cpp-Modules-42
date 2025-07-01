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
    // printChar(literal);
    // print it in four forms (double ,int ,char ,float)
        // each one need to handeled separatley
    int type = getType(literal);

    std::cout << "alo" << type << std::endl;
    switch (type)
    {
    case 0:// Char
        ConvertFromChar(literal);        
        std::cout << "char" << std::endl;
        break;
    case 1:// int
        // convertFromInt
        std::cout << "int" << std::endl;
        break;
    case 2:// float
        // convertFromFloat
        std::cout << "float" << std::endl;
        break;
    case 3:// double
        // convertFromDouble
        std::cout << "double" << std::endl;
        break;
    case 4:// error
        std::cout << "can not convert" << std::endl;
        break;
    default:
        break;
    }
}