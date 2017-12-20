//
//  Input.cpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#include "Input.hpp"
#include "Output.hpp"

using namespace std;

namespace input {
    
    bool capture(string &input) {
        bool is_valid_op = false;
        
        do {
            output::prompt();
            getline(cin,input);
            is_valid_op = verify(input);
            
            try {
                if (!is_valid_op)
                    throw runtime_error("Invalid digit or operator found!");
            }
            catch (runtime_error err) {
                cout
                << "\n"
                << err.what() << "\n"
                << "Do you wish to try Again? (Y/N): ";
                if (yes_no())
                    continue;
                else
                    break;
            }
        } while (!is_valid_op);
        
        return is_valid_op;
    }
    
    bool verify(string &s) {
        bool is_blank = false;
        bool is_digit = false;
        bool is_operand = false;
        
        bool valid_entry = false;
        
            for (auto c : s) {
                isblank(c) ? is_blank = true : is_blank = false;
                isdigit(c) ? is_digit = true : is_digit = false;
                
                switch (c) {
                    case '+': case '-': case '*': case '/':
                        is_operand = true;
                        break;
                    default:
                        is_operand = false;
                        break;
                }
                
                valid_entry = is_blank || is_digit || is_operand;
                
                if (!valid_entry)
                    break;
            }
        
        return valid_entry;
    }

    bool yes_no() {
        char c{' '};
        
        cin >> c;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        
        switch (c) {
            case 'y': case 'Y':
                return true;
            case 'n': case 'N':
                return false;
            default:
                cout
                << "Invalid input!";
                return false;
        }
        
        return false;
    }

}

