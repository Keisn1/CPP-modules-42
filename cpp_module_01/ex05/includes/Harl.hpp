#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

class Harl {
    private:
        void debug(void);
        void info(void);
    public:
        void complain(std::string level);
};

#endif // HARL_H
