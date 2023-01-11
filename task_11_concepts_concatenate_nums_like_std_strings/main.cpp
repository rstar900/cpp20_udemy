#include <iostream>
#include <concepts>
#include <string>

// Concepts only work on c++20 onwards
template <typename T>
concept ConvertibleToStdString = requires (T a)
{
    std::to_string(a);
};

template <ConvertibleToStdString T>
std::string concatenate(T a, T b)
{
    return std::to_string(a) + std::to_string(b);
}

int main()
{
    // Test with integers
    auto result1 = concatenate(22,33);
    std::cout << "result : " << result1 << std::endl;

    // Test with doubles
    auto result2 = concatenate(22.22,33.33);
    std::cout << "result : " << result2 << std::endl;

    // Should fail on std::strings
    //auto result3 = concatenate(std::string("Ma"),std::string("Mee"));
    //std::cout << "result : " << result3 << std::endl;

    return 0;
}