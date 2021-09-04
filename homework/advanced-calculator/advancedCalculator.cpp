#include "advancedCalculator.hpp"
#include <cmath>


std::map<const char, std::function<double(const double a, const double b)>> operations{
    {'+', std::plus<double>{}},
    {'-', std::minus<double>{}},
    {'*', std::multiplies<double>{}},
    {'/', std::divides<double>{}},
    {'%', [](const double& a, const double b) { return static_cast<int>(a) % static_cast<int>(b); }},
    {'!', [](const double& a, const double b) { 
            if (a < 0) {
                return std::tgamma((-a) + 1)*(-1);
            }
            return std::tgamma(a + 1); }},
    {'^', [](const double& a, const double b) { return std::pow(a, b); }},
    {'$', [](const double& a, const double b) { return std::pow(a, 1 / b); }}};


char signParsing(std::string::const_iterator& it) {
    char sign = *it;
    ++it;
    return sign;
}

ErrorCode parsingWord(const std::string& input, std::string& output, std::string::const_iterator& it) {
    bool flag{true};
    auto start = it;
    ErrorCode error{ErrorCode::OK};
    if (*it == '-') {
        it++;
    }
    for (; it != input.cend(); it++) {
        // if (std::count_if(input.begin(), input.end(), [](char el) { return el == '.'; }) > 1) {
        //     error = ErrorCode::BadFormat;
        //     continue;
        // }
        if (*it == '.' && flag == true) {
            flag = false;
            continue;
        }
        if (*it == '.' && flag == false) {
            error = ErrorCode::BadFormat;
            continue;
        }

        if (isdigit(*it)) {
            continue;
        }
        if (*it == ',') {
            error = ErrorCode::BadFormat;
            continue;
        }
        if (operations.find(*it) != operations.end()) {
            break;
        }
        return ErrorCode::BadCharacter;
    }
    output = std::string(start, it);
    // std::cout << "Słowo: " << output << '\n';
    return error;
}


bool isIntiger(std::string& input) {
    return std::none_of(input.begin(), input.end(), [](char el) { return el == '.'; });
}

bool isNoComma(std::string& input) {
    return std::none_of(input.begin(), input.end(), [](char el) { return el == ',';});
}

ErrorCode validation(std::string& input, double& a, double& b, char& sign) {
    std::string firstWord{};
    std::string secondWord{};

    ErrorCode error{ErrorCode::OK};

    auto it = input.cbegin();

    error = parsingWord(input, firstWord, it);
    if (error != ErrorCode::OK){
        return error;
    }
    sign = signParsing(it);

    error = parsingWord(input, secondWord, it);
    if (error != ErrorCode::OK){
        return error;
    }

    std::string sum = firstWord+sign+secondWord;
    // std::cout << "PO przeróbce : " << sum << '\n';
    if (input != sum) {
        return ErrorCode::BadFormat;
    }

    if (sign == '%' && (!isIntiger(firstWord) || !isIntiger(secondWord))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if(!isNoComma(firstWord) || !isNoComma(secondWord)) {
        return ErrorCode::BadFormat;
    }

    if (firstWord.empty()) {
        return ErrorCode::BadFormat;
    }

    a = std::stod(firstWord);

    if (sign != '!') {
        if (secondWord.empty()) {
            return ErrorCode::BadFormat;
        }
        b = std::stod(secondWord);
    } else {
        if (!secondWord.empty()) {
            return ErrorCode::BadFormat;
        }
        b = 0;
    }

    if (sign == '/' && (secondWord.empty() || b == 0 ) ) {
        return ErrorCode::DivideBy0;
    }

    if (sign == '$' && a < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    return ErrorCode::OK;
}

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    double a{0};
    double b{0};
    char signOperation{' '};
    ErrorCode error{validation(input, a, b, signOperation)};
    // std::cout << "Operation sign is: " << signOperation << '\n';
    if (error == ErrorCode::OK) {
        *out = operations.at(signOperation)(a, b);
    }

    return error;
}