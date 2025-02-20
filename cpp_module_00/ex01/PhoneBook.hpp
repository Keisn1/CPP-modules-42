#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
public:
	explicit PhoneBook();		// no implicit initilaization
	void add();
	void search();
	void exit();
};


#endif // PHONEBOOK_H
