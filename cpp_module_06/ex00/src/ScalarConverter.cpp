#include "ScalarConverter.h"
#include "utils.h"
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

void treatChar(char c) {
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast< int >(c) << std::endl;
    std::cout << "float: " << static_cast< float >(c) << std::endl;
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
    std::cout << "float: " << static_cast< float >(nbr) << std::endl;
    std::cout << "double: " << static_cast< double >(nbr) << std::endl;
}

void treatFloat(int nbr) {

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
    std::cout << "float: " << static_cast< float >(nbr) << std::endl;
    std::cout << "double: " << static_cast< double >(nbr) << std::endl;
}

void ScalarConverter::convert(std::string str) {
    char c;
    if (isConvertibleToChar(str, &c)) {
        treatChar(c);
        return;
    }
    std::cout << std::endl;

    int nbr;
    if (isConvertibleToInt(str, &nbr)) {
        treatInt(nbr);
        return;
    }
    std::cout << std::endl;

    if (str[str.length() - 1] == 'f') {
        str = str.substr(0, str.length() - 1);
    }

    float flt;
    if (isConvertibleToFloat(str, &flt)) {
        std::cout << "is convertible to float" << std::endl;
    } else {
        std::cout << "not convertible to float" << std::endl;
    }
    std::cout << std::endl;

    double dbl;
    if (isConvertibleToDouble(str, &dbl)) {
        std::cout << "is convertible to double" << std::endl;
    } else {
        std::cout << "not convertible to double" << std::endl;
    }

    std::cout << std::endl;
};
