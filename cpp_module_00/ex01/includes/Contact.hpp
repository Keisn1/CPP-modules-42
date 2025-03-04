#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _mobile;
	std::string _secret;
public:
	explicit Contact();
	explicit Contact(const std::string& first_name, const std::string& last_name, const std::string& nick_name, const std::string& mobile, const std::string& secret);
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nick_name() const;
	std::string get_mobile() const;
	std::string get_secret() const;
	void display() const;
};

#endif // CONTACT_H
