#include <string>
#include <iostream>
#include <fstream>
#include "InvalidInput.h"

using namespace std;

InvalidInput::InvalidInput(string input) {
    // print reason
    print_reason();
};