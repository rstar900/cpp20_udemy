#include <iostream>

struct Point 
{
    double x{}, y{};
};

int main()
{
    Point p;

    p.x = 10;
    p.y = 11;

    // With the help of structured bindings, copies of public members can be extracted 
    // in the order of their declaration
    auto [x, y] = p;

    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;

    // Capturing structured bindings only possible from C++20 onwards
    // works with & and = as well 
    [x, y] ()
    {
        std::cout << "\nInside Lambda Expression\n";
        std::cout << "x : " << x << std::endl;
        std::cout << "y : " << y << std::endl;
    }();

    return 0;

}