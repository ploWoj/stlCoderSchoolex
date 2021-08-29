#include "arithmeticAverage.hpp"

#include <cmath>
#include <numeric>

double ArithmeticAverage(std::vector<int>& vec1, std::vector<int>& vec2) {
    return (std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, std::plus<int>(), std::plus<int>())) / (double)(vec1.size() + vec2.size());
}

double Distance(std::vector<int>& vec1, std::vector<int>& vec2) {
    auto result = std::inner_product(vec1.begin(),
                                     vec1.end(),
                                     vec2.begin(),
                                     0,
                                     std::plus<int>(),
                                     [](int a, int b) { return std::pow(a - b, 2);});

    return std::sqrt(result);
}