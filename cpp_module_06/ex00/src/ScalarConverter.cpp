#include "ScalarConverter.h"
#include "utils.h"
#include <cmath>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

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
