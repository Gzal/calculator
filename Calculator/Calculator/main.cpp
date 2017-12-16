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

using namespace std;

int main() {
    string input;
    
    //Display information
    output::app_name();
    output::prompt();
    
    return !input::capture();
}
