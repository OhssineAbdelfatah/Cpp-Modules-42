#ifndef SPAN_HPP
#define SPAN_HPP
#include<set>
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
private:
    // Add member variables here
    unsigned int N;
    std::set<int> mySpan;

};

#endif // SPAN_HPP
