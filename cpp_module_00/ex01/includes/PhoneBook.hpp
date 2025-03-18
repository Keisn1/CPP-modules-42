#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
private:
	Contact _contacts[8];
	int _nbr_ctcts;
		int _oldest_index;
public:
	explicit PhoneBook();		// no implicit initilaization
	~PhoneBook();
	void add(Contact ct);
	void display();
	void display_ctct(std::istream& in);
	int get_index(std::istream& in);
};

std::string get_cmd(std::istream& in);
#endif // PHONEBOOK_H
