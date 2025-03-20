#ifndef HARL_H
#define HARL_H
#include <string>

class Harl {
        private:
                typedef void (Harl::*t_log_func)(void);
                t_log_func get_debug_level(std::string level);
                void debug(void);
                void info(void);
                void warning(void);
                void error(void);
        public:
                void complain(std::string level);
};

#endif // HARL_H
