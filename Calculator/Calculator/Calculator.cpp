//
//  Calculator.cpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#include "Calculator.hpp"
#include "Output.hpp"

void Calculator::capture_oprtn() {
    do {
        try{
            get_oprtn();
            verify_oprtn();
            dissect_oprtn();
            assign_elem();
        } catch(std::runtime_error error){
            valid_oprtn = false;
            if(!try_again(error))
                return;
        }
    } while(!valid_oprtn);
    
    return;
}

void Calculator::show_result() {
    do_oprtn();
    std::cout
    << "\n"
    << "The result is " << result << std::endl;
}

void Calculator::do_oprtn() {
    switch(oprtr) {
        case add:
            result = oprnd1 + oprnd2;
            break;
        case sub:
            result = oprnd1 - oprnd2;
            break;
        case mult:
            result = oprnd1 * oprnd2;
            break;
        case div:
            result = oprnd1 / oprnd2;
            break;
        case none: default:
            break;
    }
    return;
}

void Calculator::get_oprtn() {
    output::prompt();
    getline(std::cin,Calculator::oprtn);
    return;
}

void Calculator::verify_oprtn() {
    bool is_blank{false}, is_digit{false}, is_oprnd{false};
    bool invalid_char{false};
    
    for (auto c : oprtn) {
            isblank(c) ? is_blank = true : is_blank = false;
            isdigit(c) ? is_digit = true : is_digit = false;
            switch (c) {
                case add: case sub: case mult: case div:
                    is_oprnd = true;
                    break;
                default:
                    is_oprnd = false;
                    break;
            }
            invalid_char = !is_blank && !is_digit && !is_oprnd;
            
            if(invalid_char)
                throw(std::runtime_error("Invalid character found"));
    }
    return;
}

void Calculator::dissect_oprtn() {
    oprtn_elem curr_elem = oprtn_elem::oprnd1;
    for (auto it = oprtn.begin(); it != oprtn.end(); ++it) {
        if (!isblank(*it) && curr_elem != oprtn_elem::none) {
            switch(curr_elem) {
                case oprtn_elem::oprnd1:
                    if (isdigit(*it)) {
                        oprnd1_it = it;
                        curr_elem = oprtn_elem::oprtr;
                    } else
                        throw(std::runtime_error("First element must be a digit!"));
                    break;
                case oprtn_elem::oprtr:
                    if (ispunct(*it)) {
                        oprtr_it = it;
                        curr_elem = oprtn_elem::oprnd2;
                    } else
                        throw(std::runtime_error("Second element must be an operator!"));
                    break;
                case oprtn_elem::oprnd2:
                    if (isdigit(*it)) {
                        oprnd2_it = it;
                        curr_elem = oprtn_elem::none;
                        valid_oprtn = true;
                    } else
                        throw(std::runtime_error("Third element must be a digit!"));
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
