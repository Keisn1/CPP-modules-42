#ifndef ARRAY_H
#define ARRAY_H

#include <ostream>

#include <cstddef>

template < typename T >
class Array {
  private:
    size_t _len;

  public:
    Array(void) : _len(0) {}
    Array(unsigned int n) : _len(n) { T _data[] = new T[n]; };
    ~Array(void);
    Array(const Array&);
    Array& operator=(const Array&);
    size_t length();
};

/* template <typename T> */
/* std::ostream& operator<<(std::ostream& out, const Array&) { */
/*     // for (size_t i = 0; i < a.length(); i++) { */
/*     //     out << a[i]; */
/*     // } */
/*     // out << std::endl; */
/*     return out; */
/* } */

#endif // ARRAY_H
