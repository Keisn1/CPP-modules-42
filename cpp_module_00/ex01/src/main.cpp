#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	PhoneBook pb;
	while (1) {
		std::string input = get_cmd(std::cin);
		if (input == "exit")
			break;
		if (input == "search") {
			pb.display();
			pb.display_ctct(std::cin);
		}
		if (input == "add")
			pb.add(Contact(std::cin));
	}
}
