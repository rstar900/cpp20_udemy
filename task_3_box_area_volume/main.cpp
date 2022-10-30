#include <iostream>

int main()
{
    double length, width, height, area, volume;

    std::cout << "Welcome to box calculator. Please type in length, width, and height information : " << std::endl;
    
    std::cout << "length : ";
    std::cin >> length;
    std::cout << "width : ";
    std::cin >> width;
    std::cout << "height : ";
    std::cin >> height;

    area = width * length;
    volume = area * height;

    std::cout << "The base area is : " << area << std::endl;
    std::cout << "The volume is : " << volume << std::endl;

    return 0;
}
