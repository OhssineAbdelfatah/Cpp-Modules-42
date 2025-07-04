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
    int type = getType(literal);

    switch (type)
    {
    case 0:// Char
        ConvertFromChar(literal);        
        break;
    case 1:// int
        ConvertFromInt(literal);
        break;
    case 2:// float
        ConvertFromFloat(literal);
        break;
    case 3:// double
        ConvertFromDouble(literal);
        break;
    case 4:// error
        std::cout << "switch type [can not convert]" << std::endl;
        break;
    case 5:// error
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " ;
        literal.resize(literal.size() - 1) ;
        std::cout << literal << std::endl;
        break;
    case 6:// error
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        break;
    default:
        break;
    }
}