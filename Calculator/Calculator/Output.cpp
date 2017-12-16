//
//  Output.cpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#include "Output.hpp"

using namespace std;

const float version = 1.0;

namespace output {
    
    void app_name () {
        cout
        << "\n"
        << "Calculator v" << version << endl;
    }
    
    void prompt(){
        cout
        << "\n"
        << "Enter operation: ";
    }
}
