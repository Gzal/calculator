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
#include "Input.hpp"

int main() {
    Calculator calculator;
    
    output::app_name();
    calculator.capture();
    
    return 0;
}
