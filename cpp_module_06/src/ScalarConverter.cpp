#include "ScalarConverter.h"
#include "utils.h"
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

void ScalarConverter::convert(std::string str) {
    std::cout << str.length() << std::endl;
    std::istringstream iss(str);
    char c;
    iss >> c;
    if (iss.eof() && !iss.fail()) {
        std::cout << "not convertible to char" << std::endl;
    } else {
        std::cout << "is convertible to char" << std::endl;
        std::cout << static_cast< int >(c) << std::endl;
    }
    // if (checkPseudo(str)) {
    // }

    if (str[str.length() - 1] == 'f') {
        str = str.substr(0, str.length() - 1);
    }

    if (isConvertibleToInt(str)) {
        std::cout << "is convertible to int" << std::endl;
    } else {
        std::cout << "not convertible to int" << std::endl;
    }

    if (isConvertibleToFloat(str)) {
        std::cout << "is convertible to float" << std::endl;
    } else {
        std::cout << "not convertible to float" << std::endl;
    }

    if (isConvertibleToDouble(str)) {
        std::cout << "is convertible to double" << std::endl;
    } else {
        std::cout << "not convertible to double" << std::endl;
    }
};
