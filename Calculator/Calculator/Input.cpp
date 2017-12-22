//
//  Input.cpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#include "Input.hpp"
#include "Output.hpp"

namespace input {
    enum operators { add = '+', sub = '-', mult = '*', div = '/'};
    
    bool capture(std::string &input) {
        bool is_valid_oper = false;
        
        do {
            output::prompt();
            getline(std::cin,input);
            
            is_valid_oper = verify(input);
            
            try {
                if (!is_valid_oper)
                    throw std::runtime_error("Invalid digit or operator found!");
            }
            catch (std::runtime_error err) {
                std::cout
                << "\n"
                << err.what() << "\n"
                << "Do you wish to try Again? (Y/N): ";
                //Checks user input for a yes or no command
                if (yes_no())
                    continue;
                else
                    return is_valid_oper;
            }
        } while (!is_valid_oper);
        
        find_elem(input);
        
        return is_valid_oper;
    }
    
    bool verify(const std::string &s) {
        bool is_blank = false;
        bool is_digit = false;
        bool is_operand = false;
        
        bool valid_entry = false;
            for (auto c : s) {
                isblank(c) ? is_blank = true : is_blank = false;
                isdigit(c) ? is_digit = true : is_digit = false;
                switch (c) {
                    case add: case sub: case mult: case div:
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
    
    enum class oper_elem {null, oprnd1, oprtr, oprnd2};
    
    int oprnd1{0}, oprnd2{1};
    operators oprtr;
    oper_elem curr_elem = oper_elem::null;
    std::string::const_iterator oprnd1_it, oprnd2_it, oprtr_it;
    
    bool find_elem(const std::string &s) {
        curr_elem = oper_elem::oprnd1;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (!isblank(*it) && curr_elem != oper_elem::null) {
                switch(curr_elem) {
                    case oper_elem::oprnd1:
                        if (isdigit(*it)) {
                            oprnd1_it = it;
                            curr_elem = oper_elem::oprtr;
                        }
                        break;
                    case oper_elem::oprtr:
                        if (ispunct(*it)) {
                            oprtr_it = it;
                            curr_elem = oper_elem::oprnd2;
                        }
                        break;
                    case oper_elem::oprnd2:
                        if (isdigit(*it)) {
                            oprnd2_it = it;
                            curr_elem = oper_elem::null;
                        }
                    case oper_elem::null: default:
                        break;
                }
            }
        }
        return true;
    }
    
    bool yes_no() {
        char c{' '};
        
        std::cin >> c;
        //Ignores newline character and any other character in between to avoid
        //errors
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        
        switch (c) {
            case 'y': case 'Y':
                return true;
            case 'n': case 'N':
                return false;
            default:
                std::cout
                << "Invalid input!";
                return false;
        }
        
        return false;
    }
}
