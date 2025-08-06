#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class BitcoinExchange {
  private:
    // static std::list< std::pair< std::string, double > > rates;
    static std::vector< std::pair< std::string, double > > getRates(void) {

        std::ifstream file;
        file.open("data.csv");
        if (!file.good()) {
            throw std::runtime_error("Error: Could not open file");
        }

        std::string line;
        std::vector< std::pair< std::string, double > > rates;
        while (std::getline(file, line)) {
            if (line == "date,exchange_rate")
                continue;
            std::string date = line.substr(0, 10);

            std::istringstream valStrStream(line.substr(11));
            double value;
            valStrStream >> value;
            if (!valStrStream.eof() || valStrStream.fail())
                throw std::runtime_error("Error: Parsing File");
            rates.push_back(std::pair< std::string, double >(date, value));
        }
        return rates;
    };

  public:
    static double exchange(std::string date, double value) {
        static std::vector< std::pair< std::string, double > > rates; // Defined here, no separate definition needed
        if (rates.empty()) {
            rates = getRates();
        }

        std::vector< std::pair< std::string, double > >::iterator it = rates.begin();
        while (it != rates.end() && (*it).first < date)
            it++;

        if (it == rates.end() || (*it).first != date)
            it--;

        return value * (*it).second;
    }
};

#endif // BITCOINEXCHANGE_H
