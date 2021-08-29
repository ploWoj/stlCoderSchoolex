#include <iostream>
#include <vector>
#include "arithmeticAverage.hpp"

int main() {

    std::vector<int> v1{-3, 2, 5, -4, 5, 2, 3};
    std::vector<int> v2{3, -8, 3, -2, 21, 1, 9};

    std::cout << ArithmeticAverage(v1, v2);
}