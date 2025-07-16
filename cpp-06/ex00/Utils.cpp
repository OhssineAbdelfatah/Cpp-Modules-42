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
    int i = 0;
    if(base[0] == '-' || base[0] == '+')
        i++;
    for ( ; i < (int)base.size() ; i++){
        if(!isdigit(base[i]))// 'a' => 0 , '5' => 1
            return false;   
    }
    return true;
}

DataType getType(std::string base)
{
    if(base == "nan" || base =="-inf" || base =="+inf")
        return DOUBLE_SP;
    if(base == "nanf" || base =="-inff" || base =="+inff")
            return FLOAT_SP;
    // char check
    if( base.size() == 3 && base[0] == '\'' && base[2] == '\'' )
        return CHAR;
    
    // int check
    if (isInt(base))
        return INT;

    // double or float
    if ( base.find('.') != std::string::npos && base[base.size() -1 ] != '.' && base[0] != '.' && (isdigit(base[base.size() -1 ]) || base[base.size() -1 ] == 'f'))
    {
        int i = 0;
        if(base[0] == '-' || base[0] == '+')
            i++;
        int end = (int)base.size();
        if ( base[base.size() -1 ] == 'f' ){
            end = base.size() -1;
            for( ; i < end ; i++)
            {   
                if(!isdigit(base[i]) && base[i] != '.')
                    return ERROR;
            }
            return FLOAT;
        }
        return DOUBLE;
    }
    return ERROR;
}

void    printDouble(double d, DataType type)
{
    if(type == CHAR){
        std::cout << std::fixed << std::setprecision(2); // Set precision
        std::cout << "double: " << static_cast<double>(d) << std::endl;
    }else if(type == INT){
        std::cout << std::fixed << std::setprecision(2); // Set precision
        std::cout << "double: " << static_cast<double>(d) << std::endl;
    }else if(type == DOUBLE){
        std::cout << std::fixed << std::setprecision(2); // Set precision
        std::cout << "double: " << static_cast<double>(d) << std::endl;
    }else{
        std::cout << std::fixed << std::setprecision(2); // Set precision
        std::cout << "double: " << static_cast<double>(d) << std::endl;
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
        std::cout << std::fixed << std::setprecision(2); // Set precision
        std::cout << "float: " << static_cast<float>(stod(base)) << "f" << std::endl;
    }else{
        std::cout << std::fixed << std::setprecision(2); // Set precision
        std::cout << "float: " << static_cast<float>(stof(base)) << "f" << std::endl;
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
    printDouble(i, CHAR);
}

void ConvertFromInt(std::string& base)
{
    int i;
    try{
        i = stoi(base);
        printChar(i);
        printInt(i);
        printFloat(base, INT);
        printDouble(i, INT);
    }
    catch(const std::out_of_range& e){
        std::cerr << "int out of range" << std::endl;
    }

}

void ConvertFromFloat(std::string& base)
{
    float i;
    try{
        i = stof(base);
        if(i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min() ){
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }else{
            printChar(i);
            printInt(i);
        }
        printFloat(base, FLOAT);
        printDouble(i, FLOAT);

    }catch (const std::out_of_range& e) {
        std::cerr << "cannot convert : double out of range" << std::endl;
    }

}

void ConvertFromDouble(std::string& base)
{
    double i;
    try {
        i = std::stod(base);
        if(i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min() ){
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }else{
            printChar(i);
            printInt(i);
        }
            
        if(i > std::numeric_limits<float>::max() || i < std::numeric_limits<float>::min() )
            std::cout << "float: impossible" << std::endl;
        else
            printFloat(base, DOUBLE);
        printDouble(i, DOUBLE);

    }catch (const std::out_of_range& e) {
        std::cerr << "cannot convert : double out of range" << std::endl;
    }

}


/*

input : nan 

output : 


*/