#ifndef UTILS_H
#define UTILS_H

#include <string>
bool isConvertibleToInt(std::string str);
bool isConvertibleToFloat(std::string str);
bool isConvertibleToDouble(std::string str);

bool checkPseudo(std::string& str);
double convertPseudo(std::string& str);

#endif // UTILS_H
