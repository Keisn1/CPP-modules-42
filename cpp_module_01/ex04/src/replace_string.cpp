#include "replace_string.hpp"

void replace_string(std::string& text, std::string s1, std::string s2) {
	if (s1.length() < 1)
		return;
	size_t pos = text.find(s1, 0);
	if (pos < text.length()) {
		std::string car = text.substr(0, pos);
		std::string cdr = text.substr(pos+s1.length(), text.length());
		replace_string(cdr, s1, s2);
		text = car + s2 + cdr;
	}
}
