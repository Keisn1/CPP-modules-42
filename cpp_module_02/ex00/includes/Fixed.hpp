#ifndef FIXED_H
#define FIXED_H

class Fixed {
        private:
                int _raw_bits;
                static const int _frac_bits;
        public:
                Fixed(void);
                ~Fixed(void);
                Fixed(const Fixed&);
                Fixed& operator=(const Fixed&);
                int getRawBits(void) const;
                void setRawBits(int const raw);
};


#endif // FIXED_H
