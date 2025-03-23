#include "Fixed.hpp"
#include "Point.hpp"

Fixed z_cross_prod(Point v1, Point v2) {
    return (v1.x * v2.y - v2.x * v1.y);
}

int sign(Point& P, Point& v1, Point& v2) {
    Fixed z = z_cross_prod(P-v1, v2-v1);
    if (z == 0)
        return 0;
    if (z > 0)
        return 1;
    return -1;
}

bool in_triangle(Point P, Point tri[3]) {
    int s1 = sign(P, tri[0], tri[1]);
    int s2 = sign(P, tri[1], tri[2]);
    int s3 = sign(P, tri[2], tri[0]);


    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    if (s1 == 0 || s2 == 0 || s3 == 0)
        return true;
    bool has_neg = (s1 > 0) || (s2 > 0) || (s3 > 0);
    bool has_pos = (s1 < 0) || (s2 < 0) || (s3 < 0);
    return !(has_neg && has_pos);
}

int main() {
    Point tri[3];

    tri[0] = Point(0, 0);
    tri[1] = Point(1, 0);
    tri[2] = Point(0, 1);
    Point P (float(0.2), float(0.2));
    std::cout << "in triangle: " << in_triangle(P, tri) << std::endl;

    P = Point(1, 1);
    std::cout << "in triangle: " << in_triangle(P, tri) << std::endl;

    P = Point(0, 0);
    std::cout << "in triangle: " << in_triangle(P, tri) << std::endl;

    P = Point(float(0.5), float(0.5));
    std::cout << "in triangle: " << in_triangle(P, tri) << std::endl;
    return 0;
}
