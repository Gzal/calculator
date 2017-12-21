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
        
        process_oper(input);
        
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
    
    enum class oper_elem { null, oprnd1, oprtr, oprnd2};

    int oprnd1{0}, oprnd2{1};
    operators oprtr;
    oper_elem curr_elem = oper_elem::null;
    
    bool process_oper(const std::string &s) {
        for (auto c : s) {
            if (!isblank(c)) {
                if (isdigit(c) && curr_elem == oper_elem::null) {
                    curr_elem = oper_elem::oprnd1;
                    oprnd1 = c - '0';
                } else if (isdigit(c) && curr_elem == oper_elem::oprtr) {
                    curr_elem = oper_elem::oprnd2;
                    oprnd2 = c - '0';
                } else if (ispunct(c) && curr_elem == oper_elem::oprnd1) {
                    curr_elem = oper_elem::oprtr;
                    switch(c) {
                        case add:
                            oprtr = add;
                            break;
                        case sub:
                            oprtr = sub;
                            break;
                        case mult:
                            oprtr = mult;
                            break;
                        case div:
                            oprtr = div;
                            break;
                        default:
                            break;
                    }
                }
            }
            if(curr_elem == oper_elem::oprnd2) {
                curr_elem = oper_elem::null;
                break;
            }
        }
        std::cout << oprnd1 << " " << static_cast<char>(oprtr) << " " << oprnd2;
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

