#include"BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange(){}


BitcoinExchange::BitcoinExchange(char *path) {
    try{
        fileBase.open("data.csv", std::ios::in);
        fileInput.open(path, std::ios::in);
    }catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
    if(this != &obj){
        pricesDataBase = obj.pricesDataBase;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

// void BitcoinExchange::openFile(std::string path){

// }

std::pair<std::string , float> BitcoinExchange::parseLine(std::string& line, char sep){
    std::string token[2];
    std::string date[3];

    token[0] = line.substr(0 , line.find(sep));
    if(line.find(sep) == std::string::npos)
        throw BitcoinExchange::BadInputException();
    token[1] = line.substr(line.find(sep) + 1 , line.size());
    if(token[0].size() == 0 || token[1].size() == 0 || token[0].size() == std::string::npos || token[1].size() == std::string::npos )
        throw BitcoinExchange::BadInputException();
    int pos = 0;
    for (size_t i = 0; i < 3; i++)
    {
        date[i] = token[0].substr( pos, token[0].find('-', pos ) - pos ); 
        pos  = token[0].find('-', pos ) +1;
    }
    float value  = std::strtod(token[1].c_str(), NULL);
    std::pair<std::string, float> ccc (date[0] + date[1] + date[2],value);
    return  ccc;
}


void BitcoinExchange::readInputFile(){
    
    std::string line;
    std::getline(fileInput, line);
    std::cout << "0 " << line << std::endl;


    while( std::getline(fileInput, line)){
        std::pair<std::string, float> obj = parseLine(line, '|');
        // std::ostringstream os ;
        // os << obj.second ;
        // std::string ss(os.str()); 
        // std::cout << std::fixed << std::setprecision(ss.find('.')) <<  obj.first << obj.second << std::endl; 
    }
}

void BitcoinExchange::readBaseFile(){
    
    std::string line;
    std::getline(fileBase, line);
    std::cout << "0 " << line << std::endl;


    while( std::getline(fileBase, line)){
        std::pair<std::string, float> obj = parseLine(line, ',');
        pricesDataBase.insert(obj);
        std::ostringstream os ;
        os << obj.second ;
        std::string ss(os.str()); 
        std::cout << "Base " << std::fixed << std::setprecision(ss.find('.')) <<  obj.first << obj.second << std::endl; 
    }
}
const char* BitcoinExchange::BadInputException::what() const throw(){
    return (" bad input !!");
}

