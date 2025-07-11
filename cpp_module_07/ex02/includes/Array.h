#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>

template < typename T >
class Array {
  private:
    int _size;
    T* _data;

  public:
    Array(void) : _size(0), _data(NULL) {}

    Array(unsigned int n) : _size(n), _data(new T[n]) {
        for (int i = 0; i < _size; i++) {
            _data[i] = T();
        }
    };

    ~Array(void) {
        if (this->_data) {
            delete[] this->_data;
        }
    };

    Array(const Array& arr) : _size(arr._size), _data(new T[arr._size]) {
        for (int i = 0; i < arr._size; i++) {
            _data[i] = arr._data[i];
        }
    };

    Array& operator=(const Array& other) {
        if (this == &other)
            return *this;

        if (_data)
            delete[] _data;

        _data = new T[other._size];
        _size = other._size;
        for (int i = 0; i < other._size; i++) {
            _data[i] = other._data[i];
        }
        return *this;
    };

    T& operator[](int index) {
        if (index >= _size || index < 0) {
            throw std::out_of_range("Index is out of range");
        }
        return _data[index];
    }

    const T& operator[](int index) const {
        if (index >= _size || index < 0) {
            throw std::out_of_range("Index is out of range");
        }
        return _data[index];
    }

    size_t size() const { return _size; };
};

#endif // ARRAY_H
