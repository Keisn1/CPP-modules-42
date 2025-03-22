#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_frac_bits = 8;

Fixed::Fixed() : _raw_bits(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(int val) : _raw_bits(val) {
    std::cout << "Int constructor called" << std::endl;
    _raw_bits = val << 8;
}

Fixed::Fixed(float val) : _raw_bits(val) {
    std::cout << "Float constructor called" << std::endl;
    _raw_bits = _encode(val);
}

// empty destructor means that it doesn't perform any specific cleanup tasks when an object of the `Fixed` class is destroyed
// You might define it to follow the rule of three, ensure proper cleanup if you add resources later,
// or simply because your coding style mandates explicitly defining special member functions.
// Without additional context, there's no immediate need to do anything in such a destructor unless the class manages resources
// (like dynamic memory, file handles, etc.) that require manual cleanup.
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

// Copy constructor
// initializes uninitilaized memory
Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

// private member functions
int Fixed::_getIntPart(void) const {
    return _raw_bits >> 8;
}

int encode_up(float float_part) {
    int res = 255;
    int comp = 128;
    float sub = 0.5;
    float suprenum = 0.99609375;
    while (comp > 0) {
        if (float_part <= (suprenum - sub)) {
            res ^= comp;
            suprenum -= sub;
        }
        sub /= 2;
        comp /= 2;
    }
    return res;
}

int Fixed::_encode(float val) const {
    int res;
    int int_part;
    float float_part;
    bool is_neg;

    is_neg = false;
    if (val < 0) {
        is_neg = true;
        val *= -1;
    }
    int_part = static_cast<int>(val);
    float_part = val - int_part;
    res = int_part << 8;

    res += encode_up(float_part);

    if (is_neg) {
        res ^= -1;
        res += 1;
    }
    return res;
}

// public member functions
int Fixed::getRawBits(void) const {
    return _raw_bits;
}

void Fixed::setRawBits(int const raw) {
    _raw_bits = raw;
}

int Fixed::toInt(void) const {
    int rest = _getIntPart();
    int res = 0;
    int summand = 1;
    int count = 0;
    while (count < 23) {
        res += summand * (rest & 1);
        summand *= 2;
        rest >>= 1;
        count++;
    }
    if (rest)
        res += -8388608;
    return res;
}

float Fixed::toFloat(void) const {
    float res = static_cast<float>(_getIntPart());
    int float_bits =  _raw_bits & 255;
    if (float_bits == 0)
        return res;
    int comp = 128;
    float add = 0.5;
    while (comp > 0) {
        if (float_bits & comp)
            res += add;
        comp /= 2;
        add /= 2;
    }
    return res;
}

// operators
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

bool Fixed::operator==(const Fixed& fixed) {
    return toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed& fixed) {
    return toFloat() != fixed.toFloat();
}

bool Fixed::operator<(const Fixed& fixed) {
    if (toFloat() < fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& fixed) {
    if (*this == fixed)
        return true;
    return *this < fixed;
}

bool Fixed::operator>(const Fixed& fixed) {
    if (toFloat() > fixed.toFloat())
        return true;
    return false;
}
bool Fixed::operator>=(const Fixed& fixed) {
    if (*this == fixed)
        return true;
    return *this > fixed;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

int add(int a, int b) {
    while (b != 0) {
        // Calculate carry
        int carry = a & b;

        // Sum without carry
        a = a ^ b;

        // Calculate next carry
        b = carry << 1;
    }
    return a;
}

Fixed Fixed::operator+(const Fixed &fixed) {
    Fixed res;
    res.setRawBits(add(_raw_bits, fixed.getRawBits()));
    return res;
}
