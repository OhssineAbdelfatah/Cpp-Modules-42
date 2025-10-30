#include"BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange(){}


BitcoinExchange::BitcoinExchange(char *path) {
    try{
        file.open(path, std::ios::in);
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

std::pair<std::string , float> BitcoinExchange::parseLine(std::string& line){
    std::string token[2];
    std::string date[3];

    token[0] = line.substr(0 , line.find('|'));
    if(line.find('|') == std::string::npos)
        throw BitcoinExchange::BadInputException();
    token[1] = line.substr(line.find('|') + 1 , line.size());
    // std::reverse(token[1].begin(), token[1].end());
    // token[1] = token[1].substr(0 , token[1].size()-1);
    // std::reverse(token[1].begin(), token[1].end());

    if(token[0].size() == 0 || token[1].size() == 0 || token[0].size() == std::string::npos || token[1].size() == std::string::npos )
        throw BitcoinExchange::BadInputException();
    int pos = 0;
    for (size_t i = 0; i < 3; i++)
    {
        date[i] = token[0].substr( pos, token[0].find('-', pos ) - pos ); 
        pos  = token[0].find('-', pos ) +1;
    }
    std::cout << "**" << date[0] << "**" << date[1] << "**" << date[2] << "** ["<< token[1] << "]"<< std::endl;
    std::pair<std::string, float> ccc ();
    return  ;
}


void BitcoinExchange::readFile(){
    
    std::string line;
    std::getline(file, line);
    std::cout << "0 " << line << std::endl;
    // std::getline(file, line);
    // std::cout << "1 " << line << std::endl;
    // parseLine(line);


    while( std::getline(file, line)){
        parseLine(line);
    }
}

const char* BitcoinExchange::BadInputException::what() const throw(){
    return (" bad input !!");
}

