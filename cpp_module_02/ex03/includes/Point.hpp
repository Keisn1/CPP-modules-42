#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
    public:
        Fixed x;
        Fixed y;

        Point(void);
        Point(const Fixed &x, const Fixed &y);
        Point(const Point&);
        Point &operator=(const Point&);
        ~Point(void);
        Point operator-(const Point&) const;
};

#endif // POINT_H
