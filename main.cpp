#include <iostream>
#include <limits>

#include "Functions.h"

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

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! " << std::endl;
            std::cout << std::endl;
            continue;
        }

        if (choice < 0 || choice > 6) {
            std::cout << "Invalid choice! " << std::endl;
            std::cout << std::endl;
            continue;
        }

        switch (choice) {
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
            std::cout << "Insert number: " << std::endl;
            BinaryToHexadecimal();
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "Insert number: " << std::endl;
            HexadecimalToDecimal();
            std::cout << std::endl;
            break;
        case 6:
            std::cout << "Insert number: " << std::endl;
            HexadecimalToBinary();
            std::cout << std::endl;
            break;
        case 0:
            std::cout << "Exiting program..." << std::endl;
            return 0;
        }
    }

    return 0;
}
