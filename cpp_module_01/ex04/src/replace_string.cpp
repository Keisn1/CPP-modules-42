#include "replace_string.hpp"

void replace_string(std::string& text, std::string s1, std::string s2) {
	if (s1.length() < 1)
		return;
	size_t pos = text.find(s1, 0);
	while (pos < text.length()) {
		std::string p1 = text.substr(0, pos);
		std::string p2 = text.substr(pos+s1.length(), text.length());
		text = p1 + s2 + p2;
		pos = text.find(s1, 0);
	}
}
