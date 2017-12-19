//
//  main.cpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#include <iostream>
#include <string>

#include "Output.hpp"
#include "Input.hpp"

using namespace std;

int main() {
    string operation;
    bool cont = true;
    
    //Display information
    output::app_name();
    
    while (cont) {
        char c {' '};
        
        cont = input::capture(operation);
        output::again();
        cin >> c;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if ( c == 'n' || c == 'N')
            cont = false;
    }
    
    return 0;
}
