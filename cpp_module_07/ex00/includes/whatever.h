#ifndef FUNCTION_H
#define FUNCTION_H

template < typename T >
void swap(T& a, T& b) {
    T tmp = b;
    b = a;
    a = tmp;
}

template < typename T >
T min(T& a, T& b) {
    if (a < b) {
        return a;
    }
    return b;
}

template < typename T >
T max(T& a, T& b) {
    if (a > b) {
        return a;
    }
    return b;
}

#endif // FUNCTION_H
