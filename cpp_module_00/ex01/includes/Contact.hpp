#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <istream>

#define RESET "\033[0m"
#define DEEPSKYBLUE "\033[38;2;0;191;255m"
#define DARKSALMON "\033[38;2;255;127;80m"
#define DARKVIOLET "\033[38;2;148;0;211m"
#define RED "\033[38;2;255;0;0m"
#define SADDLEBROWN "\033[38;2;139;69;19m"
#define FORESTGREEN "\033[38;2;34;139;34m"

class Contact {
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _mobile;
	std::string _secret;
public:
	// explicit prevent implicit type conversions for constructors
	explicit Contact();
	explicit Contact(const std::string& first_name, const std::string& last_name, const std::string& nick_name, const std::string& mobile, const std::string& secret);
	explicit Contact(std::istream& in);
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nick_name() const;
	std::string get_mobile() const;
	std::string get_secret() const;
	void display() const;
};

std::string get_entry(std::string field, std::istream& in);

#endif // CONTACT_H
