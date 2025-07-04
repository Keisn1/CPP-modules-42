#include "ScalarConverter.h"
#include "utils.h"
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

void ScalarConverter::convert(std::string str) {
    if (isConvertibleToInt(str)) {
        std::cout << "is convertible" << std::endl;
    } else {
        std::cout << "not convertible" << std::endl;
    }
};
