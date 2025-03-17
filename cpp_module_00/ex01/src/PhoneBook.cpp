#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : _nbr_ctcts(0) {};

void print_entry(std::string entry) {
    if (entry.length() < 10)
        std::cout << SADDLEBROWN << "|" << RESET << std::string(10 - entry.length(), ' ') << FORESTGREEN <<  entry << RESET;
    else
        std::cout << SADDLEBROWN << "|"  << RESET << entry.substr(0, 9) + ".";
}

void PhoneBook::display() {
    std::cout << SADDLEBROWN << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << RESET << std::endl;
    int count = 0;

    while (count < _nbr_ctcts) {
        std::cout << SADDLEBROWN << "|         " << RESET << FORESTGREEN << count << RESET;
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

int PhoneBook::get_nbr_ctcts() { return _nbr_ctcts; }

void PhoneBook::display_ctct(int index) { _contacts[index].display(); }

