#include "Fixed.hpp"
#include <iostream>
#include <cmath>


int add(int a, int b);
int subtract(int a, int b);

const int Fixed::_frac_bits = 8;

Fixed::Fixed() : _raw_bits(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(int val) : _raw_bits(val) {
    std::cout << "Int constructor called" << std::endl;
    _raw_bits = val << _frac_bits;
}

Fixed::Fixed(float val) : _raw_bits(val) {
    std::cout << "Float constructor called" << std::endl;
    _raw_bits = roundf(val * (1 << _frac_bits));
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

// Copy constructor
// initializes uninitilaized memory
Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

// private member functions
// public member functions
int Fixed::getRawBits(void) const {
    return _raw_bits;
}

void Fixed::setRawBits(int const raw) {
    _raw_bits = raw;
}

int Fixed::toInt(void) const {
    return _raw_bits >> _frac_bits;
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(_raw_bits) / (1 << _frac_bits));
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

bool Fixed::operator==(const Fixed& fixed) const {
    return toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed& fixed) const {
    return toFloat() != fixed.toFloat();
}

bool Fixed::operator<(const Fixed& fixed) const {
    if (toFloat() < fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& fixed) const {
    if (*this == fixed)
        return true;
    return *this < fixed;
}

bool Fixed::operator>(const Fixed& fixed) const {
    if (toFloat() > fixed.toFloat())
        return true;
    return false;
}
bool Fixed::operator>=(const Fixed& fixed) const {
    if (*this == fixed)
        return true;
    return *this > fixed;
}

Fixed Fixed::operator+(const Fixed &fixed) {
    Fixed res;
    res.setRawBits(add(_raw_bits, fixed.getRawBits()));
    return res;
}

Fixed Fixed::operator-(const Fixed &fixed) {
    Fixed res;
    res.setRawBits(subtract(_raw_bits, fixed.getRawBits()));
    return res;
}

Fixed Fixed::operator*(const Fixed &fixed) {
    return toFloat() * fixed.toFloat();
}

Fixed Fixed::operator/(const Fixed &fixed) {
    if (fixed.toFloat() == 0)
        return Fixed ();
    return toFloat() / fixed.toFloat();
}

Fixed& Fixed::operator++(void){
    _raw_bits++;
    return *this;
}

Fixed& Fixed::operator++(int){
    _raw_bits++;
    return *this;
}

Fixed& Fixed::operator--(void){
    _raw_bits--;
    return *this;
}

Fixed& Fixed::operator--(int){
    _raw_bits--;
    return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (b < a)
        return b;
    return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (b < a)
        return b;
    return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (b > a)
        return b;
    return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (b > a)
        return b;
    return a;
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

int subtract(int a, int b) {
    while (b != 0) {
        // Calculate borrow where `b` has a 1 and `a` has a 0
        int borrow = (~a) & b;

        // Subtract without considering borrow using XOR
        a = a ^ b;

        // Calculate next borrow
        b = borrow << 1;
    }

    return a;
}
