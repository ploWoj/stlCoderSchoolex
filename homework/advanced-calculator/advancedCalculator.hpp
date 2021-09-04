#pragma once

#include <functional>
#include <map>
#include <string>
#include <cmath>


enum class ErrorCode {
    OK,
    BadCharacter,            // - znak inny niż liczba
    BadFormat,               // - zły format komendy np. + 5 4, powinno być 4 + 5
    DivideBy0,               // - dzielenie przez 0
    SqrtOfNegativeNumber,    // - pierwiastek z liczby ujemnej
    ModuleOfNonIntegerValue  // - próba obliczenia % na liczbie niecałkowitej
};

ErrorCode process(std::string input, double* out); 
ErrorCode parsingWord(const std::string& input, std::string& output, std::string::const_iterator& it);
ErrorCode validation(std::string& input, double& a, double& b, char& sign);


char signParsing(std::string::const_iterator& it);
bool isIntiger(std::string& input);




