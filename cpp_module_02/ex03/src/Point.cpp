#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}
Point::~Point(void) {}
Point::Point(const Point &p) : x(p.x), y(p.y) {}

Point &Point::operator=(const Point &p) {
    this->x = p.x;
    this->y = p.y;
    return *this;
}

Point Point::operator-(const Point &p1) const {
    return Point(p1.x - this->x, p1.y - this->y);
}
