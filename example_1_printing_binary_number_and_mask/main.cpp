#include <iostream>
#include <iomanip>
#include <bitset>

int main()
{
    int number {5}; // 0101 (32 bits) in binary

    // Show the base of numbers;
    std::cout << std::showbase << std::endl;

    // Print 5 in decimal, hexadecimal, octal and binary
    std::cout << std::setw(30) << "The number in decimal :  " << std::dec << std::setw(10) << number << std::endl;
    std::cout << std::setw(30) << "The number in hexadecimal :  " << std::hex << std::setw(10) << number << std::endl;
    std::cout << std::setw(30) << "The number in octal :  " << std::oct << std::setw(10) << number << std::endl;
    std::cout << std::setw(30) << "The number in binary :  " << std::setw(10) << std::bitset<8>(number) << std::endl; // Print 8 bits

    // Make masks for 4 bits
    unsigned char bit_0_mask {0b0001};
    unsigned char bit_1_mask {0b0010};
    unsigned char bit_2_mask {0b0100};
    unsigned char bit_3_mask {0b1000};

    //unset the previous settings
    std::cout.unsetf(std::ios::showbase | std::ios::oct);
    std::cout << std::endl;

    // Print the bits at first 4 bit positions 
    std::cout << std::setw(30) << "The bit at position 0 : " << std::setw(10) << ((number & bit_0_mask) >> 0) << std::endl;
    std::cout << std::setw(30) << "The bit at position 1 : " << std::setw(10) << ((number & bit_1_mask) >> 1) << std::endl;
    std::cout << std::setw(30) << "The bit at position 2 : " << std::setw(10) << ((number & bit_2_mask) >> 2) << std::endl;
    std::cout << std::setw(30) << "The bit at position 3 : " << std::setw(10) << ((number & bit_3_mask) >> 3) << std::endl;

    return 0;
}