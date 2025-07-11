#include "whatever.h"
#include <iostream>

class AClass {
  public:
    char _c;
    AClass(char c) : _c(c) {};
    bool operator<(const AClass& b) { return (*this)._c < b._c; }
    bool operator>(const AClass& b) { return (*this)._c > b._c; }
    bool operator==(const AClass& b) { return (*this)._c == b._c; }
};

std::ostream& operator<<(std::ostream& out, const AClass& a) {
    out << a._c;
    return out;
}

int main(void) {
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    AClass aClass('a');
    AClass bClass('b');
    std::cout << "min(aClass, bClass) = " << ::min(aClass, bClass) << std::endl;
    std::cout << "max(aClass, bClass) = " << ::max(aClass, bClass) << std::endl;
    return 0;
}
