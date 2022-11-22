#include <iostream>

int main()
{
    int x, y;

    std::cout << "Type in your x location :" << std::endl;
    std::cin >> x;

    std::cout << "Type in your y location :" << std::endl;
    std::cin >> y;

    if ((x < -10) || (x > 10) || (y < -5) || (y > 5))
        std::cout << "You're out of reach!" << std::endl;

    else
        std::cout << "You are completely surrounded. Don't move!" << std::endl;    

    return 0;
}