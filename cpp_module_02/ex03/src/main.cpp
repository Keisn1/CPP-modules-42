#include "Fixed.hpp"
#include "Point.hpp"

Fixed z_cross_prod(Point v1, Point v2) {
    return (v1.get_x() * v2.get_y()) - (v2.get_x() * v1.get_y());
}

int sign(const Point &P, const Point &v1, const Point &v2) {
    Fixed z = z_cross_prod(P - v1, v2 - v1);
    if (z == 0)
        return 0;
    if (z > 0)
        return 1;
    return -1;
}

bool bsp(const Point a, const Point b, const Point c, const Point P) {
    int s1 = sign(P, a, b);
    int s2 = sign(P, b, c);
    int s3 = sign(P, c, a);

    if (s1 == 0 || s2 == 0 || s3 == 0)
        return true;
    bool has_neg = (s1 > 0) || (s2 > 0) || (s3 > 0);
    bool has_pos = (s1 < 0) || (s2 < 0) || (s3 < 0);
    return !(has_neg && has_pos);
}

int main() {
    Point a (0, 0);
    Point b (1, 0);
    Point c (0, 1);

    Point P1(float(0.2), float(0.2));
    bool in_tri = bsp(a, b, c, P1);
    std::cout << "in triangle: " << bsp(a, b, c, P1) << std::endl;

    Point P2(1, 1);
    in_tri = bsp(a, b, c, P2);
    std::cout << "in triangle: " << in_tri << std::endl;

    Point P3(0, 0);
    in_tri = bsp(a, b, c, P3);
    std::cout << "in triangle: " << in_tri << std::endl;

    Point P4(float(0.5), float(0.5));
    in_tri = bsp(a, b, c, P4);
    std::cout << "in triangle: " << in_tri << std::endl;
    return 0;
}

// int main() {
//     Point x;
//     Point y (0.2, 0.1);

//     Point a (Fixed(float(0.2)), Fixed(float(0.1)));
//     Point b (Fixed(float(0.3)), Fixed(float(0.1)));
//     Point z (y);

//     std::cout << z_cross_prod(a, b) << std::endl;
//     std::cout << "The end" << std::endl;
// }
