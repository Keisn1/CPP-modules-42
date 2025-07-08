#ifndef UTILS_H
#define UTILS_H

#include <string>
bool isConvertibleToChar(std::string str, char* c);
bool isConvertibleToInt(std::string str, int* nbr);
bool isConvertibleToFloat(std::string str, float* flt);
bool isConvertibleToDouble(std::string str, double* dbl);
void treatChar(char c);
void treatInt(int nbr);
void treatFloat(float flt);
void treatDouble(double dbl);

#endif // UTILS_H
