//
//  Input.cpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#include "Input.hpp"

bool Input::capture() {
    string operation;
    
    getline(cin,operation);
    
    /*
    char operators[] = {'+','-','*','/'};
    
    try {
        for (auto c : operation) {
            if (!isdigit(c))
                throw runtime_error("Invalid digit or operator!");
            
            bool valid = false;
            
            for (auto o : operators){
                if (o == c)
                    valid = true;
            }
            
            if (!valid) {
                throw runtime_error ("Invalid operator!");
            }
        }
    }
    catch (runtime_error err) {
        cout << err.what() << endl;;
        return false;
    }
    */
    return true;
}
