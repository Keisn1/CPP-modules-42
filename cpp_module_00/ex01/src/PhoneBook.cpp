#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits>

PhoneBook::PhoneBook() : _nbr_ctcts(0) {
    std::cout << FORESTGREEN << "Welcome to PhoneBook!" << RESET << std::endl;
};

PhoneBook::~PhoneBook() {
    std::cout << FORESTGREEN << "PhoneBook closed!" << RESET << std::endl;
}

void print_entry(std::string entry) {
    if (entry.length() < 10)
        std::cout << SADDLEBROWN << "|" << FORESTGREEN << std::string(10 - entry.length(), ' ') <<  entry;
    else
        std::cout << SADDLEBROWN << "|"  << FORESTGREEN << entry.substr(0, 9) + ".";
}

void PhoneBook::display() {
    std::cout << SADDLEBROWN << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << RESET << std::endl;
    int count = 0;

    while (count < _nbr_ctcts) {
        std::cout << SADDLEBROWN << "|" << FORESTGREEN << "         " << count;
        print_entry(_contacts[count].get_first_name());
        print_entry(_contacts[count].get_last_name());
        print_entry(_contacts[count].get_nick_name());
        std::cout << SADDLEBROWN << "|" << RESET << std::endl;
        count++;
    }
}

void PhoneBook::add(Contact ct) {
    if (_nbr_ctcts < 8)
        _contacts[_nbr_ctcts++] = ct;
    else
        _contacts[7] = ct;
}

void PhoneBook::display_ctct(std::istream& in) {
    int index = get_index(in);
    if (index == -1)
        return;
    _contacts[index].display();
}


int PhoneBook::get_index(std::istream &in) {
    int index;
    if (_nbr_ctcts < 1)
        return -1;
    std::cout << DARKSALMON << "Which contact do you want to be displayed. Give me index 0 and " << _nbr_ctcts-1 << " (or -1 to continue): " << RESET;
    in >> index;
    while (std::cin.fail() || index < -1 || index > _nbr_ctcts-1) {
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << "Invalid input. Please enter an integer between 0 and " << _nbr_ctcts-1 << " (or -1 to continue): " << RESET ;
        in >> index;
    }
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return index;
}
