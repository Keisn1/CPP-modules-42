#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
private:
	std::string first_name;
public:
	explicit Contact(std::string& fn);
	void display() const;
};


#endif // CONTACT_H
