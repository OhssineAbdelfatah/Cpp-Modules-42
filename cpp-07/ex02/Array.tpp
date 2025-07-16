#include "Array.hpp"

template <typename A>
Array<A>::Array() : _data(NULL), _size(0){}

template <typename A>
Array<A>::Array(unsigned int _size) : _data(new A[_size]), _size(_size){}

template <typename A>
Array<A>::~Array() {
    // Destructor implementation
    if(_data)
        delete [] _data;
}

template <typename A>
Array<A>::Array(const Array& other) :_data(NULL), _size(0) {
    *this = other;
}

template <typename A>
Array<A>& Array<A>::operator=(const Array<A>& other) {
    // Copy assignment operator implementation
    if (this != &other) {
        if(_data)
            delete [] _data;
        this->_size = other._size;
        this->_data = new A[this->_size];
        for(int i = 0 ; i < (int)other._size ; i++)
            this->_data[i] = other._data[i];
    }
    return *this;
}

template <typename A>
const char * Array<A>::OutOfBoundryException::what() const throw()
{
    return ("Array is out of boundry !");
} 

template <typename A>
A &Array<A>::operator[](unsigned int index)
{
    if(index < 0 || index >= this->_size )
        throw Array<A>::OutOfBoundryException();
    return this->_data[index];
}
