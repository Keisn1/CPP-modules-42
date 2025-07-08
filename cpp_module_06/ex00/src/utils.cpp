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
    // check if theoretically inf
    // for (int i = 0; i < str.length(); i++) {
    //    '0' <= str[i]
    // }
    return false;
}
