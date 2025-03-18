#include "PhoneBook.hpp"
#include <cctype>

std::string str_tolower(std::string &str) {
    for (size_t i = 0; i < str.size(); i++)
        str[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(str[i])));
    return str;
}

std::string get_cmd(std::istream& in) {
    std::cout << DARKSALMON << "What do you want to do? ADD, SEARCH or EXIT?" << RESET << std::endl;
    std::string input;
    std::getline(in, input);
    input = str_tolower(input);
    while (input != "exit" && input != "add" && input != "search") {
        if (in.fail())
            return "";
        std::cout << RED << "You can choose between: ADD, SEARCH and EXIT" << RESET << std::endl;
        std::getline(in, input);
    }
    return input;
}
