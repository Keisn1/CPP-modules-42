#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
        int _raw_bits;
        static const int _frac_bits;
        int _getIntPart(void) const;
        int _encode(float val) const;
public:
        Fixed(void);
        Fixed(int val);
        Fixed(float val);
        Fixed(const Fixed&);
        ~Fixed(void);
        Fixed &operator=(const Fixed &);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        bool operator==(const Fixed& fixed) const;
        bool operator!=(const Fixed& fixed) const;
        bool operator<(const Fixed&) const;
        bool operator>(const Fixed&) const;
        bool operator<=(const Fixed&) const;
        bool operator>=(const Fixed&) const;
        Fixed operator+(const Fixed&);
        Fixed operator-(const Fixed&);
        Fixed operator*(const Fixed&);
        Fixed operator/(const Fixed&);
        Fixed& operator++();
        Fixed& operator++(int);
        Fixed& operator--();
        Fixed& operator--(int);
        static Fixed& min(Fixed&, Fixed&);
        static Fixed& max(Fixed&, Fixed&);
        static const Fixed& min(const Fixed&, const Fixed&);
        static const Fixed& max(const Fixed&, const Fixed&);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

int add(int a, int b);
int multiply(int a, int b);

#endif // FIXED_H
