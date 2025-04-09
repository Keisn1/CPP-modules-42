#ifndef BRAIN_H_
#define BRAIN_H_

#include <string>

class Brain {
public:
	std::string ideas[100];
	Brain(void);
	~Brain(void);
	Brain(const Brain&);
};


#endif // BRAIN_H_
