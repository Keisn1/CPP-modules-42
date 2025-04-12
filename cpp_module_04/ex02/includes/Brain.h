#ifndef BRAIN_H_
#define BRAIN_H_

#include <string>

class Brain {
private:
	std::string _ideas[100];
public:
	Brain(void);
	~Brain(void);
	Brain(const Brain&);
	Brain& operator=(const Brain&);
	void printIdeas(int amount) const;
};


#endif // BRAIN_H_
