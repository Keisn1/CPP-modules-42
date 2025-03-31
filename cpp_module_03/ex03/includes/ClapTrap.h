#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
private:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;
public:
	ClapTrap(void);
	ClapTrap(std::string);
	ClapTrap(const ClapTrap&);
	ClapTrap& operator=(const ClapTrap&);
	virtual ~ClapTrap(void);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string get_name(void) const;
	unsigned int get_hit_points(void) const;
	unsigned int get_energy_points(void) const;
	unsigned int get_attack_damage(void) const;
	void set_name(std::string name);
	void set_hit_points(unsigned int);
	void set_energy_points(unsigned int);
	void set_attack_damage(unsigned int);
};


#endif // CLAPTRAP_H
