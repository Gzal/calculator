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
    std::string oprtn{""};
    bool valid_oprtn{false};
    int result{0};
private:
    enum oprtrs{none, add = '+', sub = '-', mult = '*', div = '/'};
    enum class oprtn_elmnt{none, oprnd1, oprtr, oprnd2};
    
    std::string::const_iterator oprnd1_it, oprnd2_it, oprtr_it;
    int oprnd1{0}, oprnd2{0};
    oprtrs oprtr{none};
public:
    //Gathers and processes a user's input transforming its elements into
    //variables for calculation.
    void capture_oprtn();
    //Calculates and outputs the result for the requested operation.
    void show_result();
    //Prompts the user to enter another operation and returns choice.
    bool get_choice(std::string msg = "");
private:
    //Prompts user to enter a string operation to calculate.
    void get_oprtn();
    //Verifies that user input contains only valid characters.
    void verify_oprtn();
    //Finds on the string the location of the different operation elements and
    //checks that they have been entered in the right order.
    void dissect_oprtn();
    //Assigns the operation elements into separate variables
    void assign_elmnt();
    //Performs the requested operation.
    void do_oprtn();
};

#endif /* Calculator_hpp */
