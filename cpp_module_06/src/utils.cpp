#include "utils.h"
#include <sstream>
#include <stdexcept>

bool isConvertibleToInt(std::string str) {
    std::istringstream iss(str);
    int number;
    iss >> number;
    return iss.eof() && !iss.fail();
}
