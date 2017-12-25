//
//  Calculator.hpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#ifndef Calculator_hpp
#define Calculator_hpp

#include <iostream>
#include <string>
#include <cctype>

class Calculator {
public:
    std::string operation{""};
private:
    enum operators{none, add = '+', sub = '-', mult = '*', div = '/'};
    enum class oprtn_elem{none, oprnd1, oprtr, oprnd2};
    
    bool valid_operation{false};
    
    std::string::const_iterator oprnd1_it, oprnd2_it, oprtr_it;
    int oprnd1{0}, oprnd2{0}, result{0};
    operators oprtr{none};
public:
    //Gathers and processes a user's input transforming its elements into
    //variables for calculation.
    void capture();
private:
    //Prompts user to enter a string operation to calculate.
    void get_operation();
    //Verifies user input contains only valid characters.
    void verify_operation();
    //Finds the location on the string of the different operation elements and
    //ensures that they have been entered in the right order.
    void dissect_operation();
    //Assigns the operation elements onto separate variables
    void assign_elem();
    
    bool try_again(std::runtime_error);
};

#endif /* Calculator_hpp */
