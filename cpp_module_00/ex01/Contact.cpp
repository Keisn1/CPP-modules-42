#include "Contact.hpp"

Contact::Contact(std::string& fn) {
	this->first_name = fn;
}

void Contact::display() const {
	std::cout << "First Name: " << this->first_name << std::endl;
};
