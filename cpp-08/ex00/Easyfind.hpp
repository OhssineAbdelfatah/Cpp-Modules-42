#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// #define ERROR 1

template <typename T>

int easyfind(T &data, int target)
{
    if(std::find(data.begin(), data.end(), target) == data.end())
        throw std::exception();
    return *(std::find(data.begin(), data.end(), target));
}


#endif // EASYFIND_HPP
