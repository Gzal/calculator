//
//  main.cpp
//  Calculator
//
//  Created by Jose Gabriel Gonzalez Belmontes on 12/13/17.
//  Copyright © 2017 Jose Gabriel Gonzalez Belmontes. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string app_name = "Calculator v1.0";
    string input;
    
    cout << app_name << "\n";
    cout << "\n";
    cout << "Enter operation: ";
    getline(cin, input);
    cout << "\n";
    cout << input;
    
    return 0;
}
