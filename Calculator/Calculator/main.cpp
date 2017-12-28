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

bool get_choice();

int main() {
    bool can_contin{true};
    Calculator calc;
    
    output::app_name();
    
    while(can_contin) {
        calc.capture_oprtn();
        if(calc.valid_oprtn)
            calc.show_result();
        can_contin = get_choice();
    }
    
    return 0;
}

bool get_choice() {
    bool cont{true};
    char c{' '};
    
    std::cout
    << "\n"
    << "Do you wish to enter a new operation? (Y/N): ";
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
            << "Invalid input! The application will termiante.\n";
            cont = false;
            break;
    }
    return cont;
}
