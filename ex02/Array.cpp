#include "Array.hpp"
template <typename A>

Array::Array() {
    // Constructor implementation
    return new A[]; 
}

Array::~Array() {
    // Destructor implementation
}

Array::Array(const Array& other) {
    // Copy constructor implementation
}

Array& Array::operator=(const Array& other) {
    // Copy assignment operator implementation
    if (this != &other) {
        // Perform deep copy
    }
    return *this;
}
