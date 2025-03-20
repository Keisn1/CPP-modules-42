#ifndef HARL_H
#define HARL_H
#include <string>
#include <map>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        int get_debug_level(std::string level);
        typedef void (Harl::*t_log_func)(void);
        std::map<std::string, t_log_func> log_fun_map;
    public:
        Harl(void);
        void complain(std::string level);
};

#endif // HARL_H
