#ifndef SPAN_HPP
#define SPAN_HPP
#include<vector>
class Span {
public:
    Span(unsigned int);
    ~Span();

    Span(const Span& other);
    Span& operator=(const Span& other);
    void addNumber(int);
    // void insert(iterator position, size_type n, const T& x); single element insert 
    // iterator insert(iterator position, const T& x); insert multiples copies
    template <typename T>
    void addNumbers(const typename T::iterator& start, const typename T::iterator& end) // insert range
    {
        this->mySpan.insert(mySpan.end(), start, end);
    }
    int shortestSpan();
    int longestSpan();

    class SpanOverflowException : public std::exception {
        public :
            virtual const char* what() const throw();
    };
    class SpanSingleElemException : public std::exception {
        public :
            virtual const char* what() const throw();
    };
private:
    // Add member variables here
    unsigned int N;
    std::vector<int> mySpan;

};

#endif // SPAN_HPP
