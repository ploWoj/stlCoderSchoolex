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

std::map<const char, std::function<double(const double a, const double b)>> operations{
    {'+', std::plus<double>{}},
    {'-', std::minus<double>{}},
    {'*', std::multiplies<double>{}},
    {'/', std::divides<double>{}},
    {'%', [](const double& a, const double b) { return static_cast<int>(a) % static_cast<int>(b); }},
    {'!', [](const double& a, const double b) { return std::tgamma(a + 1); }},
    {'^', [](const double& a, const double b) { return std::pow(a, b); }},
    {'$', [](const double& a, const double b) { return std::pow(a, 1 / b); }}};



std::pair<std::string, std::string> findNumbers(std::string& input);
bool isBadCharakter(std::string& input);
bool isNumber(const std::string& input);
bool isOperation(char sign);


bool isBadFormat();
bool isBadNumber();