#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <string>
#include <vector>

struct BitcoinExchange {
    static std::vector< std::pair< std::string, double > > getRates(void);
    static double exchange(std::string date, double value);
};

#endif // BITCOINEXCHANGE_H
