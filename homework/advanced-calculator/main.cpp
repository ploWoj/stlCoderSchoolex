#include <iostream>
#include <string>
#include "advancedCalculator.hpp"


int main() {

    double result = 0;
    std:: string option ="";
    while(true) {
        std::cout << "Enter operation which you want to do(+-*/%^!$) \n"; 

        std::getline(std::cin, option);

        std::cout << "OPTION: " << option << '\n';



        // if(option == "exit") {
        //     break;
        // }
        // if(process(option, &result) != ErrorCode::OK){
        //     continue;
        // }
    }

    
    std::cin >> option;

}