#include "Fixed.hpp"

int Fixed::fr_bits = 8;

Fixed::Fixed() : val(0) {}

Fixed::Fixed(const Fixed& fixed) : val(fixed.val) {}

Fixed::operator=(const Fixed&) {}

int Fixed::getVal(void) const { return val; }
