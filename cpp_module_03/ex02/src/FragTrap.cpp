#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("") {
    this->set_hit_points(100);
    this->set_energy_points(100);
    this->set_attack_damage(30);
    std::cout << "FragTrap " << this->get_name() << " was constructed"
              << " with hp: " << this->get_hit_points()
              << ", ep: " << this->get_energy_points()
              << " and ad: " << this->get_attack_damage() << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->set_hit_points(100);
    this->set_energy_points(100);
    this->set_attack_damage(30);
    std::cout << "FragTrap " << this->get_name() << " was constructed"
              << " with hp: " << this->get_hit_points()
              << ", ep: " << this->get_energy_points()
              << " and ad: " << this->get_attack_damage() << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->get_name() << " got destructed"
              << std::endl;
}

FragTrap::FragTrap(const FragTrap &st) : ClapTrap(st) {
    std::cout << "FragTrap " << this->get_name() << " got copied"
              << " with hp: " << this->get_hit_points()
              << ", ep: " << this->get_energy_points()
              << " and ad: " << this->get_attack_damage() << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &st) {
    std::cout << "FragTrap " << this->get_name() << " got assigned FragTrap "
              << st.get_name() << std::endl;
    this->set_name(st.get_name());
    this->set_hit_points(st.get_hit_points());
    this->set_energy_points(st.get_energy_points());
    this->set_attack_damage(st.get_attack_damage());
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << get_name() << " sagt: High Five" << std::endl;
}
