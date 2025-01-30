#pragma once
#include <cctype>
#include <string>
#include <iostream>

// FLAGS TO CHECK STATEMENTS IN FUNCTIONS
//
// flag to check if string empty and if string contains non digit characters
bool NumbersOnly(std::string input) {
    if (input.empty()) {
        std::cout << "Error, empty string! " << std::endl;
        return false;
    }

    for (char character : input) {
        if (!isdigit(character)) {
            std::cout << "Error, cannot convert characters! " << std::endl;
            return false;
        }
    }
    return true;
}

// flag to check if valid input of hexadecimal letter A-F
bool ValidInput(std::string input) {
    for (char pattern : input) {
        pattern = std::toupper(pattern); // become capital letter

        if (!isdigit(pattern) && (pattern < 'A' || pattern > 'F')) { // check if pattern is digit and between A-F 
            std::cout << "Error, no such a hexadecimal number! " << std::endl; // if not, error msg
            return false;
        }
    }
    return true;
}

//flag to check if valid input of binary num 
bool BinaryDigit(std::string input) {
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] != '0' && input[i] != '1') {
            std::cout << "Error, cannot convert non-binary digits! " << std::endl;
            return false;
        }
    }
    return true;
}