#ifndef UTILS_H
#define UTILS_H

#include <string>
bool isConvertibleToChar(std::string str, char* c);
bool isConvertibleToInt(std::string str, int* nbr);
bool isConvertibleToFloat(std::string str, float* flt);
bool isConvertibleToDouble(std::string str, double* dbl);

bool checkPseudo(std::string& str);
double convertPseudo(std::string& str);

#endif // UTILS_H
