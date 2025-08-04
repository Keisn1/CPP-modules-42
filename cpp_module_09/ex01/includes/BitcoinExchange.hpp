#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

class BitcoinExchange {
  private:
    static double rate;

  public:
    static double exchange(double value) { return rate * value; }
};

#endif // BITCOINEXCHANGE_H
