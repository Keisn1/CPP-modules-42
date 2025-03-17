#include "Contact.hpp"
#include "PhoneBook.hpp"


int main() {
	PhoneBook pb;
	while (1) {
		std::string input = get_cmd(std::cin);
		if (input == "EXIT")
			break;
		if (input == "SEARCH") {
			pb.display();
			pb.display_ctct(std::cin);
		}
		if (input == "ADD")
			pb.add(Contact(std::cin));
	}

}
