#include "Contact.hpp"

Contact::Contact() : _first_name(""), _last_name(""), _nick_name(""), _mobile(""), _secret("") {}
Contact::Contact(const std::string &first_name, const std::string &last_name,
				 const std::string &nick_name, const std::string &mobile,
				 const std::string &secret)
	: _first_name(first_name), _last_name(last_name), _nick_name(nick_name),
	  _mobile(mobile), _secret(secret) {}


std::string Contact::get_first_name() const {return _first_name;}
std::string Contact::get_last_name() const {return _last_name;}
std::string Contact::get_nick_name() const {return _nick_name;}
std::string Contact::get_mobile() const {return _mobile;}
std::string Contact::get_secret() const {return _secret;}

void Contact::display() const {
	std::cout << "First Name: " << _first_name << std::endl;
	std::cout << "Last Name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nick_name << std::endl;
	std::cout << "Mobile: " << _mobile << std::endl;
	std::cout << "Darkest Secret: " << _secret << std::endl;
};
