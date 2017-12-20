//
//  Output.hpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#ifndef Output_hpp
#define Output_hpp

#include <iostream>

namespace output {
    const float version = 1.0;
    
    inline void app_name () {
        std::cout
        << "\n"
        << "Calculator v" << version << std::endl;
    }
    
    inline void prompt() {
        std::cout
        << "\n"
        << "Enter operation: ";
    }
    
    inline void again() {
        std::cout
        << "\n"
        << "Do you wish to enter another operation? (Y/N): ";
    }
}

#endif /* Output_hpp */
