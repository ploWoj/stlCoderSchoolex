#include "advancedCalculator.hpp"
#include <cmath>



std::pair<std::string, std::string> findNumbers(std::string& input) {
    std::string allOperations{"+-/*!$%^"};
    std::string firstValue = "";
    std::string secounValue = "";

    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

    auto it = std::find_first_of(input.begin() + 1,
                                 input.end(),
                                 allOperations.begin(),
                                 allOperations.end());
 
     firstValue= input.substr(0, std::distance(input.begin(), it));
  
    secounValue= input.substr(firstValue.size()+1, std::distance(it+1, input.end()+1));
    
    return std::make_pair(firstValue, secounValue);
}

bool isNumber(const std::string& input) {
    for (const auto el : input) {
        if (isdigit(el)) {
        }
    }
}

bool isOperation(char sign) {
    return operations.find(sign) != operations.end();
}

bool isBadCharakter(std::string& input) {
    for (auto el : input) {
        if (!isdigit(el) && !isOperation(el) && el != '.' && el != ' ') {
            return false;
        }
        return true;
    }
}