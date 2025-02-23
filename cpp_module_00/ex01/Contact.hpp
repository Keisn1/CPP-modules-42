#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string mobile;
	std::string secret;
public:
	explicit Contact(std::string& first_name, std::string& last_name, std::string& nick_name, std::string& mobile, std::string& secret);
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nick_name() const;
	std::string get_mobile() const;
	std::string get_secret() const;
	void display() const;
};

#endif // CONTACT_H
