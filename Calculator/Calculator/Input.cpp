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
    
    return Input::verify(operation);;
}

bool Input::verify(string &text){
    bool is_digit = false;
    bool is_operand = false;
    bool valid_entry = false;
    
    for (auto c : text) {
        if (isdigit(c))
            is_digit = true;
        else {
            is_digit = false;
            switch (c) {
                case '+': case '-': case '*': case '/':
                    is_operand = true;
                    break;
                default:
                    is_operand = false;
                    break;
            }
        }
        valid_entry = is_digit || is_operand;
        
        if (valid_entry)
            continue;
        else
            break;
    }
    
    return valid_entry;
    }
          /*
           throw runtime_error("Invalid digit or operator!");
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
        */
