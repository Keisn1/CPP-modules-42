#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
        private:
                int _raw_bits;
                static const int _frac_bits;
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
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_H
