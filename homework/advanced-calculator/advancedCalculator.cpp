#include "advancedCalculator.hpp"
#include <cmath>

std::map<const char, std::function<double(const double a, const double b)>> map_{
    {'+', std::plus<double>{}},
    {'-', std::minus<double>{}},
    {'*', std::multiplies<double>{}},
    {'/', std::divides<double>{}},
    {'%', [](const double& a, const double b) { return static_cast<int>(a) % static_cast<int>(b); }},
    {'!', [](const double& a, const double b) { return std::tgamma(a + 1); }},
    {'^', [](const double& a, const double b) { return std::pow(a, b); }},
    {'$', [](const double& a, const double b) { return std::pow(a, 1 / b); }}};

ErrorCode process(std::string input, double* out) {
}

bool enterNumber(double a) {
}

bool allowedOperation(char operation) {
    std::string allowedOperations = "-+*/$!^%";
    auto it = std::find_if(allowedOperations.begin(),
                           allowedOperations.end(),
                           [&operation](auto el) {
                               return el == operation;
                           });
    return it != allowedOperations.end();
}

bool isIntiger(double number) {
    return std::floor(number) == number;
}