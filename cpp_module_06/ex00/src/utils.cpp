#include "utils.h"
#include <cmath>
#include <limits>

#include <iostream>
#include <sstream>

bool isConvertibleToChar(std::string str, char* c) {
    // cannot use stringstream; eof only set after an attempt to read beyong the stream
    // here we're only reading one character
    if (str.length() == 1) {
        *c = str[0]; // Directly assign the character
        if (*c >= '0' && *c <= '9') {
            return false;
        }
        return true;
    }

    return false;
}

bool isConvertibleToInt(std::string str, int* nbr) {
    std::istringstream iss(str);
    iss >> *nbr;
    return iss.eof() && !iss.fail();
}

bool isConvertibleToFloat(std::string str, float* flt) {
    if (str == "nan") {
        *flt = std::numeric_limits< float >::quiet_NaN();
        return true;
    }
    if (str == "inf") {
        *flt = std::numeric_limits< float >::infinity();
        return true;
    }
    if (str == "-inf") {
        *flt = -std::numeric_limits< float >::infinity();
        return true;
    }
    std::istringstream iss(str);
    iss >> *flt;
    return iss.eof() && !iss.fail();
}

bool isConvertibleToDouble(std::string str, double* dbl) {
    std::istringstream iss(str);
    iss >> *dbl;
    if (iss.eof() && !iss.fail()) {
        return true;
    }
    return false;
}

void treatChar(char c) {
    if (c >= '!' && c <= '~') {
        std::cout << "char: " << c << std::endl;
    } else {
        std::cout << "char: Non-displayable" << std::endl;
    }
    std::cout << "int: " << static_cast< int >(c) << std::endl;
    std::cout << "float: " << static_cast< float >(c) << "f" << std::endl;
    std::cout << "double: " << static_cast< double >(c) << std::endl;
}

void treatInt(int nbr) {
    if (nbr >= std::numeric_limits< char >::min() && nbr <= std::numeric_limits< char >::max()) {
        char c = static_cast< char >(nbr);
        if (c >= ' ' && c <= '~') {
            std::cout << "char: " << c << std::endl;
        } else {
            std::cout << "char: Non-displayable" << std::endl;
        }
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    std::cout << "int: " << nbr << std::endl;

    int flt = static_cast< int >(static_cast< float >(nbr));
    if (flt == nbr) {
        std::cout << "float: " << std::fixed << static_cast< float >(nbr) << "f" << std::endl;
    } else {
        std::cout << "float: precision loss" << std::endl;
    }
    std::cout << "double: " << std::fixed << static_cast< double >(nbr) << std::endl;
}

void treatFloat(float flt) {
    if (flt >= std::numeric_limits< char >::min() && flt <= std::numeric_limits< char >::max()) {
        char c = static_cast< char >(flt);
        if (c >= '!' && c <= '~') {
            std::cout << "char: " << c << std::endl;
        } else {
            std::cout << "char: Non-displayable" << std::endl;
        }
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    if (std::isnan(flt) || std::isinf(flt) ||
        static_cast< double >(flt) < static_cast< double >(std::numeric_limits< int >::min()) ||
        static_cast< double >(flt) > static_cast< double >(std::numeric_limits< int >::max())) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast< int >(flt) << std::endl;
    }

    std::cout << "float: " << static_cast< float >(flt) << "f" << std::endl;
    std::cout << "double: " << static_cast< double >(flt) << std::endl;
}

void treatDouble(double dbl) {
    if (dbl >= std::numeric_limits< char >::min() && dbl <= std::numeric_limits< char >::max()) {
        char c = static_cast< char >(dbl);
        if (c >= '!' && c <= '~') {
            std::cout << "char: " << c << std::endl;
        } else {
            std::cout << "char: Non-displayable" << std::endl;
        }
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    if (std::isnan(dbl) || std::isinf(dbl) || dbl < std::numeric_limits< int >::min() ||
        dbl > std::numeric_limits< int >::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast< int >(dbl) << std::endl;
    }

    if (dbl > std::numeric_limits< float >::max() || dbl < -std::numeric_limits< float >::max()) {
        std::cout << "float: overflow" << std::endl;
    } else {
        std::cout << "float: " << static_cast< float >(dbl) << "f" << std::endl;
    }

    std::cout << "double: " << static_cast< double >(dbl) << std::endl;
}
