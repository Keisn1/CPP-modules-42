#include "Fixed.hpp"

int main() {
	Fixed a (float(0.2));
	Fixed b (float(0.3));
	std::cout << (a < b) << std::endl;
    return 0;
}
