#include"ScalarConverter.hpp"

/*
    Cases :
        char : 'c'
        -inf +inf nan nanf -inff +inff
        float f and dot
        double dot
        
*/

bool isInt(std::string &base){
    if(base.size() == 0)
        return false;
    for (int i = 0 ; i < (int)base.size() ; i++){
        if(!isdigit(base[i]))// 'a' => 0 , '5' => 1
            return false;   
    }
    return true;
}

DataType getType(std::string base)
{
    // char check
    if( base.size() == 3 && base[0] == '\'' && base[2] == '\'' )
        return CHAR;
    
    // int check
    if (isInt(base))
        return INT;

    // double or float
    if ( base.find('.') != std::string::npos && base[base.size() -1 ] != '.' && base[0] != '.')
    {
        int end = (int)base.size();
        if ( base[base.size() -1 ] == 'f' ){
            end = base.size() -1;
            for(int i = 0 ; i < end ; i++)
            {   
                if(!isdigit(base[i]) && base[i] != '.')
                    return ERROR;
            }
            return FLOAT;
        }
        return DOUBLE;
    }
    if(base == "nan" || base =="-inf" || base =="+inf")
        return DOUBLE;
    if(base == "nanf" || base =="-inff" || base =="+inff")
            return FLOAT;
    return ERROR;
}

void    printDouble(std::string& base, DataType type)
{
    if(type == CHAR){
        std::cout << std::fixed << std::setprecision(1); // Set precision
        std::cout << "double: " << static_cast<double>(base[1]) << std::endl;
    }else if(type == INT){
        std::cout << std::fixed << std::setprecision(1); // Set precision
        std::cout << "double: " << static_cast<double>(atoi(base.c_str())) << std::endl;
    }else if(type == DOUBLE){
        std::cout << std::fixed << std::setprecision(base.size() - base.find('.')); // Set precision
        std::cout << "double: " << static_cast<double>(stod(base)) << std::endl;
    }else{
        std::cout << std::fixed << std::setprecision(base.size() - base.find('.')); // Set precision
        std::cout << "double: " << static_cast<double>(stof(base)) << std::endl;
    }
}

void printFloat(std::string& base,int type)
{
    if(type == CHAR){
        std::cout << std::fixed << std::setprecision(1); // Set precision
        std::cout << "float: " << static_cast<float>(base[1]) << "f" << std::endl;
    }else if(type == INT){
        std::cout << std::fixed << std::setprecision(1); // Set precision
        std::cout << "float: " << static_cast<float>(atoi(base.c_str())) << "f" << std::endl;
    }else if(type == DOUBLE){
        std::cout << std::fixed << std::setprecision(base.size() - base.find('.')); // Set precision
        std::cout << "float: " << static_cast<float>(stod(base)) << std::endl;
    }else{
        std::cout << std::fixed << std::setprecision(base.size() - base.find('.')); // Set precision
        std::cout << "float: " << static_cast<float>(stof(base)) << std::endl;
    }

}

void printChar(int c)
{
    if( c >= 32 && c <= 126 )
        std::cout << "char: " << static_cast<char>(c) << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;

}

void printInt(int i)
{

    std::cout << "int: " << i << std::endl;
}

void ConvertFromChar(std::string& base)
{   
    int i = (int)base[1];
    
    printChar(i);
    printInt(i);
    printFloat(base, CHAR);
    printDouble(base, CHAR);
}

void ConvertFromInt(std::string& base)
{
    try{
        int i = stoi(base);
    }catch(const std::out_of_range& e){
        printInt(i);
    }

    printChar(i);
    printFloat(base, INT);
    printDouble(base, INT);
}

void ConvertFromFloat(std::string& base)
{
    int i = stof(base);

    printChar(i);
    printInt(i);
    printFloat(base, INT);
    printDouble(base, INT);
}

void ConvertFromDouble(std::string& base)
{
    try {
        double value = std::stod(base); // Convert string to double

        // Check if the value is within the range of double
        if (value > std::numeric_limits<double>::max()) {
            std::cout << "double: Value exceeds maximum double limit." << std::endl;
        } else if (value < -std::numeric_limits<double>::max()) {
            std::cout << "double: Value exceeds minimum double limit." << std::endl;
        } else {
            std::cout << "double: " << value << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "double: Invalid argument. Unable to convert '" << base << "' to double." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "double: Out of range. The value in '" << base << "' is too large or small for a double." << std::endl;
    }
    int i = stod(base);

    printChar(i);
    printInt(i);
    printFloat(base, INT);
    printDouble(base, INT);
}

// to do
/*
    need to fix double input  >> 4654.0adklsfh shou not fix
    limits :
        > int 
        > double
        > float
*/