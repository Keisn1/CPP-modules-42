#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {
    log_fun_map["DEBUG"] = &Harl::debug;
    log_fun_map["INFO"] = &Harl::info;
    log_fun_map["WARNING"] = &Harl::warning;
    log_fun_map["ERROR"] = &Harl::error;
}

void Harl::complain(std::string level) {
    t_log_func log_fun = log_fun_map[level];
    if (log_fun)
        (this->*log_fun)();
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
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

void Harl::filter(std::string level) {
    std::map<std::string, int> actions;
    // starting with 1 because default constructor of int yields 0
    actions["DEBUG"] = 1;
    actions["INFO"] = 2;
    actions["WARNING"] = 3;
    actions["ERROR"] = 4;

    switch (actions[level]) {
    case (1):
        debug();
        // fall through
    case (2):
        info();
        // fall through
    case (3):
        warning();
        // fall through
    case (4):
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
