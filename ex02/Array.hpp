#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename A>
class Array {
public:
    Array();
    Array(unsigned int);
    ~Array();

    Array(const Array& other);
    Array& operator=(const Array& other);

private:
    A arr[];
};

#endif // ARRAY_HPP
