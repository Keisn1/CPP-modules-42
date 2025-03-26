#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point(void);
        Point(const float x, const float y);
        Point(Fixed x, Fixed y);
        Point(const Point&);
        Point &operator=(const Point&);
        ~Point(void);
        Point operator-(const Point&) const;
};

#endif // POINT_H
