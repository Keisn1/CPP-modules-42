#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
	std::string _type;
public:
	Weapon(std::string type);
	// returns a reference to a =std::string= object
	// The =const= modifier indicates that the returned string reference is read-only,
	// meaning the caller should not modify the string via this reference.
	// Any attempt to modify the string through this reference in the caller's code would
	// result in a compilation error.
	const std::string& getType();
	void setType(std::string new_type);
};


#endif // WEAPON_H
