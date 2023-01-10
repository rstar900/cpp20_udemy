#include <iostream>

int main()
{
    // Defining a lambda function itself doesn't do anything.
    // Either assign it to variable or execute it by putting () after it's definition

    [] () 
    {
        std::cout << "Hello Lambda!" << std::endl;
    } ();

    auto sayHello = [] () 
    {
        std::cout << "Hello Lambda!" << std::endl;
    };

    sayHello();


    // use capture list to capture outside variables by reference or by value(default)
    // use & to capture all by reference and = to capture all by value eg: [&]() {} and [=]() {}
    // When passed by value cannot be changed inside the function
    int a{10}, b{20}, c{30};

    [a, b] () 
    {
        std::cout << "Inside func1 : a -> " << a << " b -> " << b << std::endl;
    } ();

    [&a, &b] () 
    {
        ++a; ++b;
        std::cout << "Inside func2: a -> " << a << " b -> " << b << std::endl;
    } ();

    std::cout << "Outside func2: a -> " << a << " b -> " << b << std::endl;


    // Parameters can be passed as well and values can also be returned (auto by default)
    auto sayHello2 = [](int n)
    {
        for (int i{}; i < n; ++i)
        {
            std::cout << "\nHello again\n";
        }

        return n;
    };

    int val = sayHello2(3);

    std::cout << "Value returned from sayHello2() -> " << val << " size -> " << sizeof(val) << std::endl;



     // values can be returned by explicit type using ->  
    auto sayHello3_val = [](int n) -> double
    {
        for (int i{}; i < n; ++i)
        {
            std::cout << "\nHello again\n";
        }

        return n;
    }(3);

    std::cout << "Value returned from sayHello3() -> " << sayHello3_val << " size -> " << sizeof(sayHello3_val) << std::endl;


    // Finally templated lambda functions
    auto templateFunc = [] <typename T> (T& a, T& b)
    {
        return a + b;
    };

    std::string str_a {"Hola "};
    std::string str_b {"Amigos!"};

    std::cout << templateFunc(a, b) << std::endl;
    std::cout << templateFunc(str_a, str_b) << std::endl;
}