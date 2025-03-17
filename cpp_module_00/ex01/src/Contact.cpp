#include "Contact.hpp"


Contact::Contact() : _first_name(""), _last_name(""), _nick_name(""), _mobile(""), _secret("") {}

Contact::Contact(const std::string &first_name, const std::string &last_name,
				 const std::string &nick_name, const std::string &mobile,
				 const std::string &secret)
	: _first_name(first_name), _last_name(last_name), _nick_name(nick_name),
	  _mobile(mobile), _secret(secret) {}

Contact::Contact(std::istream& in) {
	_first_name = get_field_loop("First name", in);
	_last_name = get_field_loop("Last name", in);
	_nick_name = get_field_loop("Nickname", in);
	_mobile = get_field_loop("Phone number", in);
	_secret = get_field_loop("Darkest Secret", in);
}


std::string Contact::get_first_name() const {return _first_name;}
std::string Contact::get_last_name() const {return _last_name;}
std::string Contact::get_nick_name() const {return _nick_name;}
std::string Contact::get_mobile() const {return _mobile;}
std::string Contact::get_secret() const {return _secret;}

void Contact::display() const {
	std::cout << DEEPSKYBLUE << "First Name: " << DARKVIOLET << _first_name << RESET << std::endl;
	std::cout << DEEPSKYBLUE << "Last Name: " << DARKVIOLET << _last_name << RESET << std::endl;
	std::cout << DEEPSKYBLUE << "Nickname: " << DARKVIOLET << _nick_name << RESET << std::endl;
	std::cout << DEEPSKYBLUE << "Mobile: " << DARKVIOLET << _mobile << RESET << std::endl;
	std::cout << DEEPSKYBLUE << "Darkest Secret: " << DARKVIOLET << _secret << RESET << std::endl;
};

std::string get_field_loop(std::string field, std::istream& in) {
	std::cout << DARKSALMON << field << "?" << RESET << std::endl;
	std::string entry;
	std::getline(in, entry);
	while (entry.empty()) {
		std::cout << RED << "Field must not be empty" << RESET << std::endl;
		std::cout << DARKSALMON << field << "?" << RESET << std::endl;
		std::getline(in, entry);
	}
	return entry;
}
