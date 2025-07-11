#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <exception>
#include <vector>

class NotFoundException : public std::exception {
	public:
    const char* what() const throw() {
		return "Not found";
    }
};

template < typename T >
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return it;
};

#endif // EASYFIND_H
