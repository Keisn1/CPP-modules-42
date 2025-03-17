#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <limits>

std::string get_cmd_loop() {
	std::cout << DARKSALMON << "What do you want to do? ADD, SEARCH or EXIT?" << RESET << std::endl;
	std::string input;
	std::getline(std::cin, input);
	while (input != "EXIT" && input != "ADD" && input != "SEARCH") {
		std::cout << RED << "You can choose between: ADD, SEARCH and EXIT" << RESET << std::endl;
		std::getline(std::cin, input);
	}
	return input;
}

int get_index_loop(int nbr_contacts) {
	int index;
	std::cout << DARKSALMON << "Which contact do you want to be displayed. Give me index: " << RESET;
	std::cin >> index;
	while (std::cin.fail() || (0 < index && index > nbr_contacts-1)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << RED << "Invalid input. Please enter an integer between 0 and " << nbr_contacts-1 << ": " << RESET ;
		std::cin >> index;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return index;
}

int main() {
	std::cout << FORESTGREEN << "Welcome to PhoneBook!" << RESET << std::endl;

	PhoneBook pb;
	while (1) {
		std::string input = get_cmd_loop();
		if (input == "EXIT")
			break;
		if (input == "SEARCH") {
			pb.display();
			if (pb.get_nbr_ctcts() > 0) {
				int index = get_index_loop(pb.get_nbr_ctcts());
				pb.display_ctct(index);
			}
		}
		if (input == "ADD")
			pb.add(Contact(std::cin));
	}

}
