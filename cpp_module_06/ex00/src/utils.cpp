#include "utils.h"
#include <limits>

#include <iostream>
#include <sstream>

bool isConvertibleToChar(std::string str, char* c) {
    std::cout << "here: " << str << "explicit newline" << std::endl;
    std::istringstream iss(str);
    iss >> *c;
    return iss.eof() && !iss.fail();
}
// bool isConvertibleToChar(std::string str, char* c) {
//     // cannot use stringstream; eof only set after an attempt to read beyong the stream
//     // here we're only reading one character
//     if (str.length() != 1) {
//         return false;
//     }
//     *c = str[0]; // Directly assign the character

//     // going to interpret single digits as int
//     if (*c >= '0' && *c <= '9') {
//         return false;
//     }
//     return true;
// }

bool isConvertibleToInt(std::string str, int* nbr) {
    std::istringstream iss(str);
    iss >> *nbr;
    return iss.eof() && !iss.fail();
}

bool isConvertibleToFloat(std::string str, float* flt) {
    std::istringstream iss(str);
    iss >> *flt;
    return iss.eof() && !iss.fail();
}

bool isConvertibleToDouble(std::string str, double* dbl) {
    std::istringstream iss(str);
    iss >> *dbl;
    return iss.eof() && !iss.fail();
}

bool checkPseudo(std::string& str) {
    if (str == "inf" || str == "inff" || str == "-inf" || str == "-inff" || str == "nan" || str == "nanf") {
        return true;
    }
    return false;
}

double convertPseudo(std::string& str) {
    if (str == "inf" || str == "inff") {
        return std::numeric_limits< double >::infinity();
    }
    if (str == "-inf" || str == "-inff") {
        return -std::numeric_limits< double >::infinity();
    }
    return 0;
    // return std::nan("");
}
