#ifndef FIXED_H
#define FIXED_H

class Fixed {
    private:
        int val;
        static int fr_bits;
    public:
		Fixed(void);
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed&);
        int getVal(void) const;
};


#endif // FIXED_H
