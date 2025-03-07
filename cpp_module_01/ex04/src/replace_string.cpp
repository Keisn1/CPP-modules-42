#include "replace_string.hpp"
#include <sys/types.h>


void replace_string(std::string& text, std::string s1, std::string s2) {
	text = "jim";
	size_t pos = text.find(s1, 0);
	std::string p1 = text.substr(0, pos);
	std::string p2 = text.substr(0, pos+s1.length());
	text = p1 + s2 + p2;
	// return "jim";
}
