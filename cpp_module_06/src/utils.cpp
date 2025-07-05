#include "utils.h"
#include <cmath>
#include <limits>
#include <sstream>

bool isConvertibleToInt(std::string str) {
    std::istringstream iss(str);
    int number;
    iss >> number;
    return iss.eof() && !iss.fail();
}

bool isConvertibleToFloat(std::string str) {
    std::istringstream iss(str);
    float number;
    iss >> number;
    return iss.eof() && !iss.fail();
}

bool isConvertibleToDouble(std::string str) {
    std::istringstream iss(str);
    double number;
    iss >> number;
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
