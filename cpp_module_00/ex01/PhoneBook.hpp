#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
public:
	void add();
	void search();
	void exit();
};


#endif // PHONEBOOK_H
