#include "Harl.hpp"
#include <iostream>

Harl::t_log_func Harl::get_debug_level(std::string level) {
    if (level == "DEBUG") { return &Harl::debug; }
    if (level == "INFO") { return &Harl::info; }
    if (level == "WARNING") { return &Harl::warning; }
    if (level == "ERROR") { return &Harl::error; }
    return NULL;
}

void Harl::complain(std::string level) {
    Harl::t_log_func log_func= get_debug_level(level);
    if (log_func)
        (this->*log_func)();
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return;
}

void Harl::debug() {
    std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning() {
    std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."<< std::endl;
}

void Harl::error() {
    std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

