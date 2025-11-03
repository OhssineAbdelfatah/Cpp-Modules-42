#ifndef SPAN_HPP
#define SPAN_HPP
#include<vector>
#include<iostream>
class Span {
    private:
        unsigned int N;
        std::vector<int> mySpan;
    
    public:
        Span(unsigned int);
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);

        void addNumber(int);
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

        template <typename T> void addNumbers(const T start, const T end); // insert range
        
};

template <typename T> void Span::addNumbers(const T start, const T end) // insert range
{
    // std::cout << std::distance(start, end) << std::endl;
    if( mySpan.size() + std::distance(start, end) > N)
        throw Span::SpanOverflowException();
    this->mySpan.insert(mySpan.end(), start, end);
}

#endif // SPAN_HPP
