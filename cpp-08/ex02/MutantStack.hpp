#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <algorithm>
#include <stack>

template <typename T> 
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    ~MutantStack();

    MutantStack(const MutantStack<T>& other);
    MutantStack<T>& operator=(const MutantStack<T>& other);

    // make a typedef to create an iterator of type stack<T>
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();


};
# include "MutantStack.tpp"
#endif // MUTANTSTACK_HPP
