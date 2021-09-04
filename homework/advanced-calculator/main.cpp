#include <iostream>
#include <string>
#include "advancedCalculator.hpp"


int main() {
    double result{};
    std::string equation{};

    while (true) {
        std::cout << "Enter equation: ";
        std::getline(std::cin, equation);

        if (equation == "quit") {
            break;
        }
        if (process(equation, &result) != ErrorCode::OK) {
            continue;
        }
        std::cout << "Result: " << result << '\n';
        std::cout << "Write quit to exit!!!\n";
    }
}