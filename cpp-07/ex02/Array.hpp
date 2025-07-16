#ifndef ARRAY_HPP
#define ARRAY_HPP
#include<iostream> 

template <typename A>
class Array {
    private:
        A* _data;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int);
        ~Array();

        Array(const Array& );
        Array& operator=(const Array& );
        A &operator[](unsigned int index);

    class OutOfBoundryException : public std::exception 
    {
        public :
            virtual const char* what() const throw();

    };

};

#endif // ARRAY_HPP