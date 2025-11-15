#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <algorithm>
#include <stack>
#include <deque>

// template <class T, class container = std::deque<T> > ;
template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>{
// class MutantStack : public std::stack<T> {
public:
    typedef typename Container::iterator                 iterator;
    MutantStack();
    ~MutantStack();

    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);

    // make a typedef to create an iterator of type stack<T>
    iterator begin();
    iterator end();


};
#include "MutantStack.tpp"
#endif // MUTANTSTACK_HPP
