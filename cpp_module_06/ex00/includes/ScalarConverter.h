#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>

class ScalarConverter {
  private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter(void);

  public:
    static void convert(std::string str);
};

#endif // SCALARCONVERTER_H
