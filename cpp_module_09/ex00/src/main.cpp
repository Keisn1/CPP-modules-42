#include "BitcoinExchange.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

bool isLeapYear(int year) {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

bool isDateCoherent(int year, int month, int day) {
    if (day == 31) {
        if (!(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
            return false;
        }
    }
    if (isLeapYear(year)) {
        if ((month == 2) && (day > 28)) {
            return false;
        }
    }

    return true;
}

bool isValidDate(std::string& date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    int year;
    std::istringstream iss(date.substr(0, 4));
    iss >> year;
    if (!iss.eof() || iss.fail())
        return false;
    if (year < 0)
        return false;

    int month;
    iss.clear();
    iss.str(date.substr(5, 2));
    iss >> month;
    if (!iss.eof() || iss.fail())
        return false;
    if (month < 1 || month > 12)
        return false;

    int day;
    iss.clear();
    iss.str(date.substr(8, 2));
    iss >> day;
    if (!iss.eof() || iss.fail())
        return false;
    if (day < 1 || day > 31)
        return false;
    if (!isDateCoherent(year, month, day))
        return false;

    return true;
}

double convertToDouble(std::string valStr) {
    std::istringstream valStrStream(valStr);
    double value;
    valStrStream >> value;
    if (valStrStream.eof() && !valStrStream.fail()) {
        return value;
    }
    return -1;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: no file" << std::endl;
        return 1;
    }

    std::ifstream file;
    file.open(argv[1]);
    if (!file.good()) {
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }

    std::string line;
    while (getline(file, line)) {
        if (line == "date | value") {
            continue;
        }
        std::string date = line.substr(0, 10);
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value = convertToDouble(line.substr(line.find(" | ") + 3));
        if (value < 0) {
            std::cout << "Error: not a positive number" << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number" << std::endl;
            continue;
        }
        std::cout << date << " => " << std::fixed << std::setprecision(2) << value << " = "
                  << BitcoinExchange::exchange(date, value) << std::endl;
    }
    file.close();

    return 0;
}
