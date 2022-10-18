#include <iostream>

int main(){
    // variables
    std::string fullName;
    std::string country;

    // input / output
    std::cout << "Enter your full name" << std::endl;
    std::getline(std::cin, fullName);

    std::cout << "Where do you live?" << std::endl;
    std::cin >> country;

    std::cout << fullName << ", I've heard great things about " << country << ". I'd like to go sometime." << std::endl;
    return 0;
}
