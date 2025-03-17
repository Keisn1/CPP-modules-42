#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"


class PhoneBook {
private:
	Contact _contacts[8];
	int _nbr_ctcts;
public:
	explicit PhoneBook();		// no implicit initilaization
	void add(Contact ct);
	void display();
	void display_ctct(int index);
	int get_nbr_ctcts();
};

std::string get_field_loop(std::string field);

#endif // PHONEBOOK_H
