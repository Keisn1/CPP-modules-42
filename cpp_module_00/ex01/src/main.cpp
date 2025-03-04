#include "PhoneBook.hpp"
#include <limits>

std::string get_cmd_loop() {
	std::cout << "What do you want to do? ADD, SEARCH or EXIT?" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	while (input != "EXIT" && input != "ADD" && input != "SEARCH") {
		std::cout << "You can choose between: ADD, SEARCH and EXIT" << std::endl;
		std::getline(std::cin, input);
	}
	return input;
}

std::string get_field_loop(std::string field) {
	std::cout << field << "?" << std::endl;
	std::string entry;
	std::getline(std::cin, entry);
	while (entry.empty()) {
		std::cout << field << "?" << std::endl;
		std::getline(std::cin, entry);
	}
	return entry;
}

int get_index_loop(int nbr_contacts) {
	int index;
	std::cout << "Which contact do you want to be displayed. Give me index: ";
	std::cin >> index;
	while (std::cin.fail() || (0 < index && index > nbr_contacts-1)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter an integer between 0 and " << nbr_contacts-1 << ": " ;
		std::cin >> index;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return index;
}

int main() {
	std::cout << "Welcome to PhoneBook!" << std::endl;

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
		if (input == "ADD") {
			std::string first_name = get_field_loop("First name");
			std::string last_name = get_field_loop("Last name");
			std::string nick_name = get_field_loop("Nickname");
			std::string phone_nbr = get_field_loop("Phone number");
			std::string secret = get_field_loop("Darkest Secret");
			pb.add(Contact(first_name, last_name, nick_name, phone_nbr, secret));
		}
	}

}
