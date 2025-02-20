#include "Contact.hpp"

Contact::Contact(std::string fn) {
	this->first_name = fn;
}

std::string Contact::get_first_name() {
	return this->first_name;
}
