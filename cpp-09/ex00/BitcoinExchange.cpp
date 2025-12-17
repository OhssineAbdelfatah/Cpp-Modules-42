#include"BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange(){}


BitcoinExchange::BitcoinExchange(char *path) {
    try{
        fileBase.open("data.csv", std::ios::in);
        checkExt(path, ".csv");
        fileInput.open(path, std::ios::in);
        if(fileInput.fail() || fileBase.fail())
            throw BitcoinExchange::BadInputException("...");
    }catch (std::exception& e){
        std::cout << "Failed to open file : " << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
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

std::pair<std::string , float> BitcoinExchange::parseLineInput(std::string& line, char sep){
    std::string token[2];
    std::string date[3];

    token[0] = line.substr(0 , line.find(sep));
    token[0] = token[0].substr(0 , token[0].find(' '));
    if(line.find(sep) == std::string::npos)
        throw BitcoinExchange::BadInputException("bad input");
    token[1] = line.substr(line.find(sep) + 1 , line.size());
    if(token[0].size() == 0 || token[1].size() == 0 || token[0].size() == std::string::npos || token[1].size() == std::string::npos )
        throw BitcoinExchange::BadInputException("bad input");
    int pos = 0;
    for (size_t i = 0; i < 3; i++)
    {
        date[i] = token[0].substr( pos, token[0].find('-', pos ) - pos ); 
        pos  = token[0].find('-', pos ) +1;
    }
    if(date[1].size() > 2 || date[2].size() > 2)
        throw BitcoinExchange::BadInputException("bad date format");
    float value  = std::strtod(token[1].c_str(), NULL);
    if(value > 1000  )
        throw BitcoinExchange::BadInputException("too large value");
    else if (value < 0 )
        throw BitcoinExchange::BadInputException("negative value");
    std::pair<std::string, float> ccc (date[0] + date[1] + date[2],value);
    return  ccc;
}


std::pair<std::string , float> BitcoinExchange::parseLineBase(std::string& line, char sep){
      std::string token[2];
    std::string date[3];

    token[0] = line.substr(0 , line.find(sep));
    token[0] = token[0].substr(0 , token[0].find(' '));
    if(line.find(sep) == std::string::npos)
        throw BitcoinExchange::BadInputException("bad data");
    token[1] = line.substr(line.find(sep) + 1 , line.size());
    if(token[0].size() == 0 || token[1].size() == 0 || token[0].size() == std::string::npos || token[1].size() == std::string::npos )
        throw BitcoinExchange::BadInputException("bad data");
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

/*
    Errors :
    => badDate
    => badPrice
    => tooLargeNumber 
*/
void BitcoinExchange::readInputFile(){
    std::string line;
    // std::getline(fileInput, line);
    while( std::getline(fileInput, line)){
        if(line.empty())
            throw BitcoinExchange::BadInputException("Empty file");
        try{
            std::pair<std::string, float> obj = parseLineInput(line, '|');
            std::map<std::string, float>::iterator elem = pricesDataBase.find(obj.first);
            if(elem != pricesDataBase.end())
                std::cout << elem->first << " => " << elem->second << " * " << obj.second << " = " <<  obj.second * elem->second << std::endl;
            else{
                elem = pricesDataBase.upper_bound(obj.first) ;
                if( elem != pricesDataBase.end()){
                    if( elem != pricesDataBase.begin())
                        --elem;
                    std::cout << elem->first << " => " << elem->second << " = " <<  obj.second * elem->second << std::endl;
                }
            }
        }catch (std::exception& e){
            std::cout <<"Input Error : " << e.what() << std::endl;
        }
    }
}




    // std::ostringstream os ;
    // os << obj.second ;
    // std::string ss(os.str()); 
    // std::cout << std::fixed << std::setprecision(ss.find('.')) <<  obj.first << obj.second << std::endl; 

void BitcoinExchange::readBaseFile(){
    
    std::string line;
    // std::getline(fileBase, line);

    while( std::getline(fileBase, line)){
        std::pair<std::string, float> obj = parseLineBase(line, ',');
        pricesDataBase.insert(obj);
        // std::ostringstream os ;
        // os << obj.second ;
        // std::string ss(os.str()); 
        // std::cout << "Base " << std::fixed << std::setprecision(ss.find('.')) <<  obj.first << obj.second << std::endl; 
    }
}
const char* BitcoinExchange::BadInputException::what() const throw(){
    return (_mssg.c_str());
}

BitcoinExchange::BadInputException::BadInputException(std::string mssg) :_mssg(mssg){}
BitcoinExchange::BadInputException::~BadInputException() throw() {}
void BitcoinExchange::checkExt(std::string path, std::string ext){
    if(ext.size() > path.size() || path.empty() || ext.empty())
        throw BitcoinExchange::BadInputException("extension error (.csv)");
    if ( (&path[path.size() - 4]) != ext )
        throw BitcoinExchange::BadInputException("extension error (.csv)");
    return ;
}
