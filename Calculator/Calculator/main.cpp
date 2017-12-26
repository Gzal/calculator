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
    bool go_again{true};
    Calculator calculator;
    
    output::app_name();
    
    while(go_again) {
        calculator.capture_oprtn();
    }
    
    return 0;
}
