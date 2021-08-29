#pragma once

#include <functional>
#include <map>
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,            // - znak inny niż liczba
    BadFormat,               // - zły format komendy np. + 5 4, powinno być 4 + 5
    DivideBy0,               // - dzielenie przez 0
    SqrtOfNegativeNumber,    // - pierwiastek z liczby ujemnej
    ModuleOfNonIntegerValue  // - próba obliczenia % na liczbie niecałkowitej
};

// std::map<const char, std::function<double(const double, const double)>> map_;

ErrorCode process(std::string input, double* out);


bool isIntiger(double number);
bool isBadCharacter(std::string& input);
bool isBadFormat();
bool isBadNumber();
double fromStringToDouble(std::string& input);