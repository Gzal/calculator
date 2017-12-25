//
//  Calculator.cpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#include "Calculator.hpp"
#include "Output.hpp"

void Calculator::capture() {
    do {
        try{
            get_operation();
            verify_operation();
            dissect_operation();
            assign_elem();
        } catch(std::runtime_error error){
            valid_operation = false;
            if(!try_again(error))
                return;
        }
    } while(!valid_operation);

    return;
}

void Calculator::get_operation() {
    output::prompt();
    getline(std::cin,Calculator::operation);
    return;
}

void Calculator::verify_operation() {
    bool is_blank{false}, is_digit{false}, is_operand{false};
    bool invalid_char{false};
    
    for (auto c : operation) {
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
            invalid_char = !is_blank && !is_digit && !is_operand;
            
            if(invalid_char)
                throw(std::runtime_error("Invalid character found"));
    }
    
    return;
}

void Calculator::dissect_operation() {
    oprtn_elem curr_elem = oprtn_elem::oprnd1;
    for (auto it = operation.begin(); it != operation.end(); ++it) {
        if (!isblank(*it) && curr_elem != oprtn_elem::none) {
            switch(curr_elem) {
                case oprtn_elem::oprnd1:
                    if (isdigit(*it)) {
                        oprnd1_it = it;
                        curr_elem = oprtn_elem::oprtr;
                    }
                    break;
                case oprtn_elem::oprtr:
                    if (ispunct(*it)) {
                        oprtr_it = it;
                        curr_elem = oprtn_elem::oprnd2;
                    } else
                    break;
                case oprtn_elem::oprnd2:
                    if (isdigit(*it)) {
                        oprnd2_it = it;
                        curr_elem = oprtn_elem::none;
                        valid_operation = true;
                    }
                    break;
                default:
                    throw(std::runtime_error("Invalid operation!"));
                    break;
            }
        }
    }
    return;
}

void Calculator::assign_elem() {
    oprnd1 = *oprnd1_it - '0';
    oprnd2 = *oprnd2_it - '0';
    switch(*oprtr_it) {
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
    }
    
}

bool Calculator::try_again(std::runtime_error e) {
    bool cont{true};
    char c{' '};
    
    std::cout
    << "\n"
    << e.what() << "\n"
    << "Do you wish to try again? (Y/N): ";
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    switch (c) {
        case 'y': case 'Y':
            cont = true;
            break;
        case 'n': case 'N':
            cont = false;
            break;
        default:
            std::cout
            << "Invalid input!";
            cont = false;
            break;
    }
    return cont;
}
