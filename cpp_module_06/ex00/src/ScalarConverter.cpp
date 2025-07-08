#include "ScalarConverter.h"
#include "utils.h"
#include <cmath>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

void ScalarConverter::convert(std::string str) {
    char c;
    if (isConvertibleToChar(str, &c)) {
        std::cout << "read as char" << std::endl;
        treatChar(c);
        return;
    }

    int nbr;
    if (isConvertibleToInt(str, &nbr)) {
        std::cout << "read as integer" << std::endl;
        treatInt(nbr);
        return;
    }

    if (str[str.length() - 1] == 'f' && str != "-inf" && str != "inf") {
        str = str.substr(0, str.length() - 1);
    }

    float flt;
    if (isConvertibleToFloat(str, &flt)) {
        std::cout << "read as float" << std::endl;
        treatFloat(flt);
        return;
    }

    double dbl;
    if (isConvertibleToDouble(str, &dbl)) {
        std::cout << "read as double" << std::endl;
        treatDouble(dbl);
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
