#include "Fixed.hpp"
#include <iostream>

const int Fixed::_frac_bits = 8;

Fixed::Fixed() : _raw_bits(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int val) : _raw_bits(val) {
    std::cout << "Int constructor called" << std::endl;
    _raw_bits = val << 8;
}

// Copy constructor
// initializes uninitilaized memory
Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

// Copy-assignement operator
// must correctly deal with an object that has already been constructed and may own ressources
//
// This line defines an overloaded assignment operator for a class named `Fixed`.
// It ensures that the left-hand side object (`*this`) is properly assigned the value from the right-hand side object's value passed as a constant reference.
// The `return *this;` part allows chaining assignments by returning a reference to the left-hand object.
//
// In C++, operator overloading allows a programmer to define the behavior of operators for user-defined data types (like classes or structs).
// This is useful for making user-defined types behave more like built-in types.
// Each operator can be overloaded, and the syntax is typically `return_type ClassName::operator<operator_symbol>(parameter_list)`.
Fixed &Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_raw_bits = fixed.getRawBits();
    return *this;
}


// empty destructor means that it doesn't perform any specific cleanup tasks when an object of the `Fixed` class is destroyed
// You might define it to follow the rule of three, ensure proper cleanup if you add resources later,
// or simply because your coding style mandates explicitly defining special member functions.
// Without additional context, there's no immediate need to do anything in such a destructor unless the class manages resources
// (like dynamic memory, file handles, etc.) that require manual cleanup.
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _raw_bits;
}

int Fixed::toInt(void) const {
    int rest = _raw_bits >> 8;
    int count = 0;
    int result = 0;
    int summand = 1;
    while (count < 23) {
        result += summand * (rest & 1);
        summand *= 2;
        rest >>= 1;
        count++;
    }
    if (rest)
        result += -8388608;
    return result;
}

float Fixed::toFloat(void) const {
    float res = 0;
    int rest = _raw_bits;
    int summand = 1;
    int count = 0;
    while (count < 32 - _frac_bits) {
        res += (rest & 1) * summand;
        summand *= 2;
        rest >>= 1;
        count++;
    }
    return res;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toInt();
    return out;
}
