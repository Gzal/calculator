//
//  main.cpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#include <iostream>
#include <string>

#include "Output.hpp"
#include "Calculator.hpp"

bool try_again();

int main() {
    bool go_again{true};
    Calculator calculator;
    
    output::app_name();
    
    while(go_again) {
        calculator.capture_oprtn();
        if(calculator.valid_oprtn)
            calculator.show_result();
        go_again = try_again();
    }
    
    return 0;
}

bool try_again() {
    bool cont{true};
    char c{' '};
    
    std::cout
    << "\n"
    << "Do you wish to try again? (Y/N): ";
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    switch (c) {
        case 'y': case 'Y':
            cont = true;
            break;
        case 'n': case 'N':
            cont = false;
            break;
        default:
            std::cout
            << "Invalid input!\n";
            cont = false;
            break;
    }
    return cont;
}
