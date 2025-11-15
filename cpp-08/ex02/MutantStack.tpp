#include "MutantStack.hpp"

template <typename T, class Container> 
MutantStack<T, Container>::MutantStack() {
    // Constructor implementation
}

template <typename T, class Container> 
MutantStack<T, Container>::~MutantStack() {
    // Destructor implementation
}

template <typename T, class Container> 
MutantStack<T, Container>::MutantStack(const MutantStack& other) {
    // Copy constructor implementation
    *this = other;
}

template <typename T, class Container> 
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other) {
    // Copy assignment operator implementation
    if (this != &other) {
        this->operator=(other);
    }
    return *this;
}

template <typename T, class Container> 
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return (this->c.begin());
}


template <typename T, class Container> 
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(){
    return (this->c.end());
}