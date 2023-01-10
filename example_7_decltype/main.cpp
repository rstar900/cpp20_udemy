/*
Thanks to this answer for clarity on the topic 
https://stackoverflow.com/questions/12084040/decltype-vs-auto#:~:text=decltype%20gives%20the%20declared%20type,type%20of%20the%20return%20value.
*/

#include <iostream>

// decltype can deduce type of the passed expression

// way 1 : cannot separate definition and declaration
decltype(auto) max_1(double& a, double& b)
{
    return ((a > b) ? a : b);
}

// way 2 : can separate definition and declaration
// use trailing return type (need to put auto as return type to make compiler happy)

auto max_2(double& a, double& b) -> decltype((a > b) ? a : b);

int main()
{
    double a {5.565}, b{5.891};

    double& res_1{ max_1(a, b)};
    ++res_1;
    std::cout << "a: " << a << " b: " << b << std::endl;

    double& res_2{ max_2(a, b)};
    ++res_2;
    std::cout << "a: " << a << " b: " << b << std::endl;
}

auto max_2(double& a, double& b) -> decltype((a > b) ? a : b)
{
    return ((a > b) ? a : b);
}