#include "MutantStack.hpp"

template <typename T> 
MutantStack<T>::MutantStack() {
    // Constructor implementation
}

template <typename T> 
MutantStack<T>::~MutantStack() {
    // Destructor implementation
}

template <typename T> 
MutantStack<T>::MutantStack(const MutantStack<T>& other) {
    // Copy constructor implementation
    *this = other;
}

template <typename T> 
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
    // Copy assignment operator implementation
    if (this != &other) {
        this->operator=(other);
    }
    return *this;
}

template <typename T> 
typename std::stack<T>::container_type::iterator MutantStack<T>::begin(){
    return (this->c.begin());
}


template <typename T> 
typename std::stack<T>::container_type::iterator MutantStack<T>::end(){
    return (this->c.end());
}