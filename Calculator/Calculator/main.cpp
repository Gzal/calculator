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
    std::string operation{" "};
    bool go_again{false};
    
    output::app_name();
    
    do {
        if(!input::capture(operation))
            return 0;
        output::again();
        go_again = input::yes_no();
    } while (go_again);
    
    return 0;
}
