#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	// creates a reference named `stringREF` to an existing `std::string` object named `str`
	// The `&` symbol indicates that `stringREF` is a reference, meaning it is an alias to the original `str` object.
	// Any modifications made to `stringREF` will affect `str` since they both refer to the same object in memory.
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of str: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string variable: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}
