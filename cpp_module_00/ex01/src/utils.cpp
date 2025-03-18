#include "PhoneBook.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>

int get_int_from_istream(std::istream &in, int& res) {
    bool failed;
    if (in.eof()) {
        std::cout << "EOF, leaving." << std::endl;
        exit(EXIT_SUCCESS);
    }
    in >> res;
    failed = in.fail();
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return failed;
}

std::string get_line_wrapper(std::istream &in) {
    std::string input;
    if (in.eof()) {
        std::cerr << "EOF encountered. Exiting..." << std::endl;
        exit(EXIT_SUCCESS);
    }
    if (!std::getline(in, input)) {
        std::cerr << "EOF encountered. Exiting..." << std::endl;
        exit(EXIT_SUCCESS);
	}
    return input;
}

std::string str_tolower(std::string &str) {
    for (size_t i = 0; i < str.size(); i++)
        str[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(str[i])));
    return str;
}

std::string get_cmd(std::istream& in) {
    std::cout << DARKSALMON << "What do you want to do? ADD, SEARCH or EXIT?" << RESET << std::endl;
    std::string input = get_line_wrapper(in);

    input = str_tolower(input);
    while (input != "exit" && input != "add" && input != "search") {
        if (in.fail())
            return "";
        std::cout << RED << "You can choose between: ADD, SEARCH and EXIT" << RESET << std::endl;
        input = get_line_wrapper(in);
    }
    return input;
}
