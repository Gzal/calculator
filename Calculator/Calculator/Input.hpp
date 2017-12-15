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

using namespace std;

class Input {
public:
    static bool capture();
private:
    static bool verify(string &text);
};
#endif /* Input_hpp */