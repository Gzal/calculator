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
    //Prompts user to input an operation and stores it in the string ref and
    //checks the string to ensure it represents a valid operation. Returns a
    //flag depending on whether it successfully captured a valid operation or
    //not.
    bool capture(std::string &input);
    //Checks whether the characters in a string contain only digits, white space,
    //or operation characters: '+', '-', '*' and/or '/'.
    bool verify(const std::string &s);
    //Checks standard input stream for a yes/no command. Namely, if the user has
    //entered 'y', 'Y', 'n', or 'N'.
    bool yes_no();
}

#endif /* Input_hpp */
