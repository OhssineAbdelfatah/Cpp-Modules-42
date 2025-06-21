#include"ScalarConverter.hpp"

DataType getType(std::string base)
{
    //check string int value size compare to string size
    if( base.size() == 1 && isalpha(base[0]) )
        return CHAR;
    std::stringstream ss;
    ss << atoi(base.c_str());
    if (ss.str().size() == base.size())
        return INT;
    // double or float
    if ( base.find('.') != std::string::npos && base[base.size() -1 ] != '.' && base[0] != '.')
    {
        if ( base[base.size() -1 ] == 'f' )
            return FLOAT;
        return DOUBLE;
    }
    if(base == "nan" || base =="-inf" || base =="+inf")
        return DOUBLE;
    if(base == "nanf" || base =="-inff" || base =="+inff")
            return FLOAT;
    return ERROR;
}

void printChar(std::string base)
{
    int c ;
    try{
        c = stoi(base);
    }catch(std::exception& e)
    {

    }
    if (c < 32 || c > 126 )
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(c) << std::endl;
}

void printValues(std::string base)
{
    void *prim;

    if(getType(base) == DOUBLE){}
        prim = static_cast<double>();
    else if(getType(base) == FLOAT)
        prim = static_cast<>();
    else if(getType(base) == CHAR)
        prim = static_cast<>();
    else if(getType(base) == INT)
        prim = static_cast<>();
    else if(getType(base) == ERROR)
        prim = static_cast<>();
}
