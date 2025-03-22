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
                // function does not modify any member variables of the class
                // allowing it to be called on constant instances of the class.
                int getRawBits(void) const;
                int setRawBits(int const raw);
                float toFloat(void) const;
                int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_H
