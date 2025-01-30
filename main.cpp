#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

#include "Flags.h"

// function converting decimal num to binary
void DecimalToBinary() {
    std::string num;
    std::cin.ignore();
    getline(std::cin, num);

    if (!NumbersOnly(num)) { // check if flag true or false
        return;
    }
    int converted = stoi(num); //string num becomes int
    std::string binary = "";
    if (converted == 0) {
        binary = "0";
        std::cout << "Binary value: " << binary << std::endl;
        return;
    }
    else {
        while (converted > 0) {
            binary = std::to_string(converted % 2) + binary;
            converted /= 2;
        }
    }
    std::cout << "Binary value: " << binary << std::endl;
}

// function converting decimal num to hexadecimal
void DecimalToHexadecimal() {
    std::string num;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, num);

    if (!NumbersOnly(num)) { // check if flag true or false
        return;
    }

    int converted = stoi(num);
    std::string hexadecimal = "";
    int remainder;

    if (converted == 0) { // if digit is 0 answer is 0
        hexadecimal = "0";
        std::cout << "Hexadecimal value: " << hexadecimal << std::endl;
        return;
    }
    else {
        while (converted > 0) {
            remainder = converted % 16;
            converted /= 16;

            switch (remainder) {
            case 10: hexadecimal = "A" + hexadecimal; break;
            case 11: hexadecimal = "B" + hexadecimal; break;
            case 12: hexadecimal = "C" + hexadecimal; break;
            case 13: hexadecimal = "D" + hexadecimal; break;
            case 14: hexadecimal = "E" + hexadecimal; break;
            case 15: hexadecimal = "F" + hexadecimal; break;
            default: hexadecimal = std::to_string(remainder) + hexadecimal; // add digits between 0-9
            }
        }
    }
    std::cout << "Hexadecimal value: " << hexadecimal << std::endl;
}

// function converting binary num to decimal
void BinaryToDecimal() {
    std::string num;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, num);

    if (!NumbersOnly(num)) {
        return;
    }
    if (!BinaryDigit(num)) {
        return;
    }

    int decimal = 0;
    if (num == "0") { // if binary num is 0, answer is 0
        std::cout << "Decimal value: " << decimal << std::endl;
        return;
    }

    int exponent = num.length() - 1; // highest exponent in the binary num
    for (int i = 0; i < num.length(); i++) {
        int bit = num[i] - '0';
        decimal += bit * pow(2, exponent); // convert it to decimal using: digit(0 or 1) * 2^(position of the digit)
        exponent--; // reduce exponent by 1 with every loop 
    }
    std::cout << "Decimal value: " << decimal << std::endl;
}

int main() {
    int choice;

    while (true) {
        std::cout << "Choose an option from below: " << std::endl;
        std::cout << " 1. Decimal to binary " << std::endl;
        std::cout << " 2. Decimal to hexadecimal " << std::endl;
        std::cout << " 3. Binary to decimal " << std::endl;
        std::cout << " 4. Binary to hexadecimal " << std::endl;
        std::cout << " 5. Hexadecimal to decimal " << std::endl;
        std::cout << " 6. Hexadecimal to binary " << std::endl;
        std::cout << " 0. Exit program" << std::endl;
        std::cin >> choice;

        switch (choice) {
        default:
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice! Choose a valid option between: 0 and 6." << std::endl;
            break;
        case 1:
            std::cout << "Insert number: " << std::endl;
            DecimalToBinary();
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Insert number: " << std::endl;
            DecimalToHexadecimal();
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Insert number: " << std::endl;
            BinaryToDecimal();
            std::cout << std::endl;
            break;
        case 4:
            std::cout << "No implementation yet, Coming soon..." << std::endl;
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "No implementation yet, Coming soon..." << std::endl;
            std::cout << std::endl;
            break;
        case 6:
            std::cout << "No implementation yet, Coming soon..." << std::endl;
            std::cout << std::endl;
            break;
        case 0:
            std::cout << "Exiting program..." << std::endl;
            exit(0);
        }
    }

    return 0;
}