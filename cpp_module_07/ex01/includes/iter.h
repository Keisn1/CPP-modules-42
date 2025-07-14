#ifndef ITER_H
#define ITER_H

#include <cstddef>

template < typename T, typename F >
void iter(T arr[], size_t len, F callback) {
    for (size_t i = 0; i < len; i++) {
        callback(arr[i]);
    }
}

// For const arrays specifically:
template < typename T, typename F >
void iter(const T arr[], size_t len, F callback) {
    for (size_t i = 0; i < len; ++i) {
        callback(arr[i]);
    }
}

#endif // ITER_H
