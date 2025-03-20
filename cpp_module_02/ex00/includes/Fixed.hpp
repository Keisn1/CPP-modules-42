#ifndef FIXED_H
#define FIXED_H

class Fixed {
        private:
                int _raw_bits;
                static const int _frac_bits;
        public:
                Fixed(void);
                Fixed(const Fixed&);
                ~Fixed(void);
                Fixed& operator=(const Fixed&);
                // function does not modify any member variables of the class
                // allowing it to be called on constant instances of the class.
                int getRawBits(void) const;
                int setRawBits(int const raw);
};


#endif // FIXED_H
