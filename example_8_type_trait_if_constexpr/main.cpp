#include <iostream>

// Type traits tell us more about a (templated) type
// using them with if constexpr allows conditional
// generation of branches during compilation
// Check the result at https://cppinsights.io/ to get a better idea

void func1 (int a, int b)
{
    std::cout << "Called by integral types, a -> " << a <<" b -> " << b << std::endl;
}

void func2 (double a, double b)
{
    std::cout << "Called by floating point types, a -> " << a <<" b -> " << b << std::endl;
}

template <typename T>
void call_func(T a, T b)
{
    if constexpr (std::is_integral_v<T>) // can otherwise use longer version std::is_integral<T>::value
    {
        func1(a, b);
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        func2(a,b);
    }
    else
    {
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>, "Please provide integral or floating point type!!");
    }
}

int main()
{
    call_func(3, 4);
    //call_func(4.56, 2.89);
    // call_func("Hola", "Amigos!"); // will fail during compilation
}
