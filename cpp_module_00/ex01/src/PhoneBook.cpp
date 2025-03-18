#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits>
#include <cstdlib>

PhoneBook::PhoneBook() : _nbr_ctcts(0), _oldest_index(0) {
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
    int index = (_oldest_index-1) -  ((_oldest_index-1) % 8);
    while (count < _nbr_ctcts) {
        if (index == _oldest_index)
            index -= 8;
        std::cout << SADDLEBROWN << "|" << FORESTGREEN << "         " << index++;
        print_entry(_contacts[count].get_first_name());
        print_entry(_contacts[count].get_last_name());
        print_entry(_contacts[count].get_nick_name());
        std::cout << SADDLEBROWN << "|" << RESET << std::endl;
        count++;
    }
}

void PhoneBook::add(Contact ct) {
    if (_nbr_ctcts < 8)
        _nbr_ctcts++;

    _contacts[(_oldest_index++) % 8] = ct;
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
    std::cout << DARKSALMON << "Which contact do you want to be displayed. Give me an index between 0 and " << _nbr_ctcts-1 << " (or -1 to continue): " << RESET;
    bool failed = get_int_from_istream(in, index);
    while (failed || index < -1 || index > _nbr_ctcts-1) {
        std::cout << RED << "Invalid input. Please enter an integer between 0 and " << _nbr_ctcts-1 << " (or -1 to continue): " << RESET ;
        failed = get_int_from_istream(in, index);
    }
    return index;
}
