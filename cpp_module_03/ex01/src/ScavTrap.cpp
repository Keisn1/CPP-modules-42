#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("") {
		this->set_hit_points(100);
		this->set_energy_points(50);
		this->set_attack_damage(20);
		std::cout << "ScavTrap " << this->get_name() << " was constructed"
							<< " with hp: " << this->get_hit_points()
							<< ", ep: " << this->get_energy_points()
							<< " and ad: " << this->get_attack_damage() << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
		this->set_hit_points(100);
		this->set_energy_points(50);
		this->set_attack_damage(20);
		std::cout << "ScavTrap " << this->get_name() << " was constructed"
							<< " with hp: " << this->get_hit_points()
							<< ", ep: " << this->get_energy_points()
							<< " and ad: " << this->get_attack_damage() << std::endl;
}

ScavTrap::~ScavTrap() {
		std::cout << "ScavTrap " << this->get_name() << " got destructed"
							<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st) {
		std::cout << "ScavTrap " << this->get_name() << " got copied"
							<< " with hp: " << this->get_hit_points()
							<< ", ep: " << this->get_energy_points()
							<< " and ad: " << this->get_attack_damage() << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st) {
		std::cout << "ScavTrap " << this->get_name() << " got assigned ScavTrap "
							<< st.get_name() << std::endl;
		this->set_name(st.get_name());
		this->set_hit_points(st.get_hit_points());
		this->set_energy_points(st.get_energy_points());
		this->set_attack_damage(st.get_attack_damage());
		return *this;
}

void ScavTrap::guardGate(void) {
		std::cout << "ScavTrap " << get_name() << " sagt: Kommst hier nich reain..." << std::endl;
}
