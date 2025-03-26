#include "Point.hpp"

// default constructor
Point::Point(void) : _x(0), _y(0) {}

// floating point constructor
Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {
    std::cout << "flaot constructor called" << std::endl;
}

// floating point constructor
Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {
    std::cout << "fixed constructor called" << std::endl;
}

// copy constructor
Point::Point(const Point &p) : _x(p._x), _y(p._y) {}

// assignment operator
// since members are const, this makes no sense
Point &Point::operator=(const Point &p) {
    (void)p;
    return *this;
}

// destructor
Point::~Point(void) {}

Point Point::operator-(const Point &p1) const {
    return Point(p1._x - this->_x, p1._y - this->_y);
}
