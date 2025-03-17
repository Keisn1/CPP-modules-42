#include "PhoneBook.hpp"

std::string get_cmd(std::istream& in) {
    std::cout << DARKSALMON << "What do you want to do? ADD, SEARCH or EXIT?" << RESET << std::endl;
    std::string input;
    std::getline(in, input);
    while (input != "EXIT" && input != "ADD" && input != "SEARCH") {
        if (in.fail())
            return "";
        std::cout << RED << "You can choose between: ADD, SEARCH and EXIT" << RESET << std::endl;
        std::getline(in, input);
    }
    return input;
}
