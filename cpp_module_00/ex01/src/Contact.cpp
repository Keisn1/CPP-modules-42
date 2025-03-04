#include "Contact.hpp"


Contact::Contact() : first_name(""), last_name(""), nick_name(""), mobile(""), secret("") {}
Contact::Contact(const std::string &first_name, const std::string &last_name,
				 const std::string &nick_name, const std::string &mobile,
				 const std::string &secret)
	: first_name(first_name), last_name(last_name), nick_name(nick_name),
	  mobile(mobile), secret(secret) {}


std::string Contact::get_first_name() const {return first_name;}
std::string Contact::get_last_name() const {return last_name;}
std::string Contact::get_nick_name() const {return nick_name;}
std::string Contact::get_mobile() const {return mobile;}
std::string Contact::get_secret() const {return secret;}

void Contact::display() const {
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nick_name << std::endl;
	std::cout << "Mobile: " << mobile << std::endl;
	std::cout << "Darkest Secret: " << secret << std::endl;
};
