#include "Brain.h"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain was constructed" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain was destructed" << std::endl;
}

Brain::Brain(const Brain &b) {
	(void)b;
	std::cout << "ideas were copied" << std::endl;
	std::cout << "Brain was copy-constructed" << std::endl;
}

void Brain::printIdeas(int amount) const {
	if (amount < 0 || amount > 100) {
		std::cout << "you're funny; which brain can handle this amount of ideas?" << std::endl;
		return;
	}
	for (int i = 0; i < amount; i++)
			std::cout << _ideas[i] << std::endl;
}
