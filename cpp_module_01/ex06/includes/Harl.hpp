#ifndef HARL_H
#define HARL_H
#include <string>

typedef enum e_debug_levels {
DEBUG,
INFO,
WARNING,
ERROR
} t_debug_levels;

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    int get_debug_level(std::string level);
public:
    void complain(std::string level);
    void filter(std::string level);
};

#endif // HARL_H
