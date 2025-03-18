#include "Harl.hpp"
#include <iostream>
#include <map>

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

void Harl::complain(std::string level) {
    // Array of function pointers
    // - void (Harl::*)(void)
    //   - void (Harl::*)(void) specifies a pointer to a member function
    //     of the Harl class that return nothing and take no parameters
    // - actions[]
    //   - Declares =actions= as an array of function pointers fitting the specified signature
    // { &Harl::error, &Harl::warning, &Harl::info, &Harl::debug };
    // - Initializes the array with pointers to the specific member functions of the Harl class.
    void (Harl::*actions[])(void) = { &Harl::error, &Harl::warning, &Harl::info, &Harl::debug };

    // Array of corresponding level strings
    std::string levels[] = { "ERROR", "WARNING", "INFO", "DEBUG" };

    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            // Why use this?
            // - =this= pointer is used within member functions to access the object for which the function is called
            //   - When you have a pointer to a member function and you want to call it on a particular instance of a class,
            //   - When you have a member function pointer, it does not inherently know which instance of the class to operate on
            //   - You need to use an instance of the class to call the function
            //   - By using =this=, you are specifying that the member function should be invoked on the current instance of the class.
            // - this->: Accesses the current object instance.
            // - *: Dereferences the function pointer.
            // - actions[i]: Refers to the ith function pointer in the =actions= array.
            // - (): Calls the function with no parameters.
            (this->*actions[i])(); // Call the corresponding function
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
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
        info();
        warning();
        error();
        break;
    case (2):
        info();
        warning();
        error();
        break;
    case (3):
        warning();
        error();
        break;
    case (4):
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
