#include<iostream>
#include"Iter.hpp"

// void printelem(int& i){
//     std:: cout << i << std::endl;
// }

// void printWord(std::string& i){
//     std:: cout << i << std::endl;
// }   


// int main(  )
// {
//     std::string array[] = {"abde", "ohss","zaka" ,"lina"};
//     int arrayint[] = { 5 ,22, 44 , 68};

//     iter(arrayint, sizeof(arrayint)/sizeof(arrayint[0]) , printelem);
// }

#include<iostream>
#include"Iter.hpp"

void printInt(const int& i) {
    std::cout << "Value: " << i << std::endl;
}

void doubleInt(int& i) {
    i *= 2;
}

void printWord(const std::string& str) {
    std::cout << "Word: " << str << std::endl;
}

void upperCaseFirst(std::string& str) {
    if (!str.empty()) {
        str[0] = std::toupper(str[0]);
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "Original numbers:" << std::endl;
    iter(numbers, length, printInt);  // Uses const T& overload
    
    iter(numbers, length, doubleInt); // Uses T& overload
    
    std::cout << "After doubling:" << std::endl;
    iter(numbers, length, printInt);  // Uses const T& overload
    
    std::cout << std::endl;
    
    std::string words[] = {"hello", "world", "test", "example"};
    int wordLength = sizeof(words) / sizeof(words[0]);
    
    std::cout << "Original words:" << std::endl;
    iter(words, wordLength, printWord);  // Uses const T& overload
    
    iter(words, wordLength, upperCaseFirst);  // Uses T& overload
    
    std::cout << "After capitalizing first letter:" << std::endl;
    iter(words, wordLength, printWord);  // Uses const T& overload
    
    return 0;
}