#include "Fixed.hpp"
#include <iostream>

void run_test_code() {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

int main() {
	run_test_code();
	return 0;
}
