#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T p1, T p2){
    T p3 = p1;
    p1 = p2;
    p2 = p3;
}

template <typename A>
A min(A p1, A p2){
    if(p1 > p2)
        return p2;
    else if(p1 < p2)
        return p1;
    return p2;
}

template <typename B>
B max(B p1, B p2){
    if(p1 < p2)
        return p2;
    else if(p1 > p2)
        return p1;
    return p2;
}
#endif 