//
//  Input.hpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include <iostream>
#include <string>
#include <cctype>

namespace input {
    
    bool capture(std::string &input);
    
    bool verify(std::string &text);
    
    bool yes_no();
}

#endif /* Input_hpp */
