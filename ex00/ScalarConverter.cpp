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

    switch (type)
    {
    case 0:// Char
        std::cout << "switch type [char]" << std::endl;
        ConvertFromChar(literal);        
        break;
    case 1:// int
        // convertFromInt
        std::cout << "switch type [int]" << std::endl;
        ConvertFromInt(literal);
        break;
    case 2:// float
        // convertFromFloat
        std::cout << "switch type [float]" << std::endl;
        ConvertFromFloat(literal);
        break;
    case 3:// double
        // convertFromDouble
        std::cout << "switch type [double]" << std::endl;
        ConvertFromDouble(literal);
        break;
    case 4:// error
        std::cout << "switch type [can not convert]" << std::endl;
        break;
    default:
        break;
    }
}