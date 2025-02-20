#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
private:
	std::string first_name;
public:
	explicit Contact(std::string fn);
	std::string get_first_name();
};


#endif // CONTACT_H
