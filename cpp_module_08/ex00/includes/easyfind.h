#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <exception>

template < typename T >
typename T::const_iterator easyfind(const T& container, int value) {
    return std::find(container.begin(), container.end(), value);
};

template < typename T >
typename T::iterator easyfind(T& container, int value) {
    return std::find(container.begin(), container.end(), value);
};

#endif // EASYFIND_H
