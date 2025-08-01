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
    // void addNumbers(int); // using iterators
    int shortestSpan();
    int longestSpan();

    class SpanOverflowException : public std::exception {
        public :
            virtual const char* wath() const throw();
    };
    class SpanSingleElemException : public std::exception {
        public :
            virtual const char* wath() const throw();
    };
private:
    // Add member variables here
    unsigned int N;
    std::vector<int> mySpan;

};

#endif // SPAN_HPP
