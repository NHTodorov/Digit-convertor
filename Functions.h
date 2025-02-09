#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

#include "Flags.h"

// function converting decimal num to binary
void DecimalToBinary() {
    std::string num;
    std::cin.ignore();
    getline(std::cin, num);

    if (!Empty(num)) {
        return;
    }
    if (!NumbersOnly(num)) { // check if flag true or false
        return;
    }

    long long int converted = stoll(num); //string num becomes int
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
    std::cin.ignore();
    getline(std::cin, num);

    if (!Empty(num)) {
        return;
    }

    if (!NumbersOnly(num)) { // check if flag true or false
        return;
    }

    long long int converted = stoll(num);
    std::string hexadecimal = "";
    long long int remainder;

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
    std::cin.ignore();
    getline(std::cin, num);

    if (!Empty(num)) {
        return;
    }
    if (!NumbersOnly(num)) {
        return;
    }
    if (!BinaryDigit(num)) {
        return;
    }

    long long int decimal = 0;
    if (num == "0") { // if binary num is 0, answer is 0
        std::cout << "Decimal value: " << decimal << std::endl;
        return;
    }

    int exponent = num.length() - 1; // highest exponent in the binary num
    for (int i = 0; i < num.length(); i++) {
        int bit = num[i] - '0'; // char - string            
        decimal += bit * pow(2, exponent); // convert it to decimal using: digit(0 or 1) * 2^(position of the digit)
        exponent--; // reduce exponent by 1 with every loop 
    }
    std::cout << "Decimal value: " << decimal << std::endl;
}

// function converting binary to hexadecimal number
void BinaryToHexadecimal() {
    std::string num;
    std::cin.ignore();
    getline(std::cin, num);

    if (!Empty(num)) {
        return;
    }
    if (!NumbersOnly(num)) {
        return;
    }
    if (!BinaryDigit(num)) {
        return;
    }

    long long int converted = stoll(num);
    std::string hexadecimal = "";

    if (converted == 0) { // if digit is 0 answer is 0
        hexadecimal = "0";
        std::cout << "Hexadecimal value: " << hexadecimal << std::endl;
        return;
    }
    else {
        while (num.length() % 4 != 0) {
            num = "0" + num; // add 0 in front of num
        }
        for (int i = 0; i < num.length(); i+= 4) {
            int fourbits = std::stoll(num.substr(i, 4), nullptr, 2); // take 4 digits and the value of them to be decimal
            // now case knows and automatically converts the binary digits to decimal (1-15) and then to hexadecimal
            switch (fourbits) {
            case 0: hexadecimal += "0"; break; // 0000 binary = 0 decimal
            case 1: hexadecimal += "1"; break; // 0001 binary = 1 decimal
            case 2: hexadecimal += "2"; break; // 0010 binary = 2 decimal
            case 3: hexadecimal += "3"; break; // and so on
            case 4: hexadecimal += "4"; break;
            case 5: hexadecimal += "5"; break;
            case 6: hexadecimal += "6"; break;
            case 7: hexadecimal += "7"; break;
            case 8: hexadecimal += "8"; break;
            case 9: hexadecimal += "9"; break;
            case 10: hexadecimal += "A"; break;
            case 11: hexadecimal += "B"; break;
            case 12: hexadecimal += "C"; break;
            case 13: hexadecimal += "D"; break;
            case 14: hexadecimal += "E"; break;
            case 15: hexadecimal += "F"; break;
            }
        }
        std::cout << "Hexadecimal value: " << hexadecimal << std::endl;
    }
}

// function converting hexadecimal to decimal digit
void HexadecimalToDecimal() {
    std::string num;
    std::cin.ignore();
    getline(std::cin, num);

    if (!Empty(num)) {
        return;
    }
    if (!ValidHexa(num)) {
        return;
    }

    int decimalvalue = 0; // end result
    int exponent = num.length() - 1;

    for (int i = 0; i < num.length(); i++) {
    int bit = 0;

        if (num[i] >= '0' && num[i] <= '9') {
            bit = num[i] - '0'; // char - string
        } else {
            switch (num[i]) {
            case 'A': bit = 10; break;
            case 'B': bit = 11; break;
            case 'C': bit = 12; break;
            case 'D': bit = 13; break;
            case 'E': bit = 14; break;
            case 'F': bit = 15; break;
            }
        }
        decimalvalue += bit * pow(16, exponent); 
        exponent--;
    }
    std::cout << "Decimal value: " << decimalvalue << std::endl;
}

//function to convert hexadecimal to binary digit
void HexadecimalToBinary() {
    std::string num;
    std::cin.ignore();
    getline(std::cin, num);

    if (!Empty(num)) {
        return;
    }
    if (!ValidHexa(num)) {
        return;
    }

    if (num.length() == 0) {
        std::cout << "Binary value: " << "0" << std::endl;
        return;
    }

    std::string binaryvalue = "";
    for (int i = 0; i < num.length(); i++) {
        switch (num[i]) {
        case '0': binaryvalue += "0000"; break; // represent each binary digit as string
        case '1': binaryvalue += "0001"; break;
        case '2': binaryvalue += "0010"; break;
        case '3': binaryvalue += "0011"; break;
        case '4': binaryvalue += "0100"; break;
        case '5': binaryvalue += "0101"; break;
        case '6': binaryvalue += "0110"; break;
        case '7': binaryvalue += "0111"; break;
        case '8': binaryvalue += "1000"; break;
        case '9': binaryvalue += "1001"; break;
        case 'A': binaryvalue += "1010"; break;
        case 'B': binaryvalue += "1011"; break;
        case 'C': binaryvalue += "1100"; break;
        case 'D': binaryvalue += "1101"; break;
        case 'E': binaryvalue += "1110"; break;
        case 'F': binaryvalue += "1111"; break;
        }
        // stack the result to the end of the string
        // do it while num.length() > 0
    }
    // value of the binary digits of the stacked string
    std::cout << "Binary value: " << binaryvalue << std::endl;
}