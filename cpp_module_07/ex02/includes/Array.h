#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <exception>
#include <iostream>

template < typename T >
class Array {
  private:
    size_t _size;
    T* _data;

  public:
    Array(void) : _size(0), _data(NULL) {}

    Array(unsigned int n) : _size(n), _data(NULL) {
        try {
            this->_data = new T[n];
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
            _size = 0;
            return;
        }

        T* tmp = new T();
        for (size_t i = 0; i < _size; i++) {
            _data[i] = *tmp;
        }
        delete tmp;
    };

    ~Array(void) {
        if (this->_data) {
            delete[] this->_data;
        }
    };

    // Array(const Array& arr) {
    //     try {
    //         this->_data = new T[arr._size];
    //     } catch (std::exception& e) {
    //         std::cerr << e.what() << std::endl;
    //         return;
    //     }

    //     _size = arr._size;
    //     for (size_t i = 0; i < arr._size; i++) {
    //         _data[i] = arr._data[i];
    //     }
    // };

    Array& operator=(const Array&);
    T& operator[](int index) { return _data[index]; }

    size_t size() { return _size; };
};

#endif // ARRAY_H
