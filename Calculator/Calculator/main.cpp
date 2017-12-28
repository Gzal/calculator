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

int main() {
    bool can_contin{true};
    Calculator calc;
    
    output::app_name();
    
    while(can_contin) {
        calc.capture_oprtn();
        if(calc.valid_oprtn)
            calc.show_result();
        can_contin = calc.get_choice();
    }
    
    return 0;
}
