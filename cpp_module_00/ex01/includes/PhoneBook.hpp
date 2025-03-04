#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int nbr_ctcts;
public:
	explicit PhoneBook();		// no implicit initilaization
	void add(Contact ct);
	void display();
	void display_ctct(int index);
	int get_nbr_ctcts();
};


#endif // PHONEBOOK_H
