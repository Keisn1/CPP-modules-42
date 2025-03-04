#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nbr_ctcts(0) {};

void print_entry(std::string entry) {
    if (entry.length() < 10)
        std::cout << "|" << std::string(10 - entry.length(), ' ') <<  entry;
    else
        std::cout << "|" << entry.substr(0, 9) + ".";
}

void PhoneBook::display() {
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    int count = 0;

    while (count < nbr_ctcts) {
        std::cout << "|         " << count;
        print_entry(contacts[count].get_first_name());
        print_entry(contacts[count].get_last_name());
        print_entry(contacts[count].get_nick_name());
        std::cout << "|" << std::endl;
        count++;
    }
}

void PhoneBook::add(Contact ct) {
    if (nbr_ctcts < 8)
        contacts[nbr_ctcts++] = ct;
    else
        contacts[7] = ct;
}

int PhoneBook::get_nbr_ctcts() { return nbr_ctcts; }

void PhoneBook::display_ctct(int index) { contacts[index].display(); }
