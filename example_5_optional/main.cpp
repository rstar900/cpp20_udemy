#include <iostream>
#include <optional>

std::optional<int> find_character(std::string& str, std::optional<char> c = std::nullopt) // a char value is casted to std::optional
{

    // Assign a default value of 'z' if std::nullopt otherwise use the specified value to char_to_find
    char char_to_find = c.value_or('z');

    for (size_t i{}; i < str.size(); ++i)
    {
        if (str[i] == char_to_find)
        {
            return i;
        }
    }

    return {}; // return std::nullopt
}

int main()
{
    // std::optional was introduced in c++17
    // it can either contained the template specified type value or contain nothing (std::nullopt)
    std::optional<int> opt {}; // opt initialized with std::nullopt

    if (opt.has_value()) // Always check before accessing (otherwise runtime exception will be thrown)
    {
        std::cout << "The value of opt is : " << opt.value() << std::endl;
        //can also use *opt to access value
    }
    else 
    {
        std::cout << "opt is empty" << std::endl;
    }

    std::string str1 {"Hello world!"};
    std::string str2 {"Hello worldz!"};

    std::optional<int> index = find_character(str1);
    
    if (index.has_value())
    {
        std::cout << "(" << str1 << ") Found z at index : " << index.value() << std::endl;
    }
    else
    {
        std::cout << "(" << str1 << ") Could not find z" << std::endl;
    }

    index = find_character(str2);

    if (index.has_value())
    {
        std::cout << "(" << str2 << ") Found z at index : " << index.value() << std::endl;
    }
    else
    {
        std::cout << "(" << str2 << ") Could not find z" << std::endl;
    }

    index = find_character(str2, 'w');

    if (index.has_value())
    {
        std::cout << "(" << str2 << ") Found w at index : " << index.value() << std::endl;
    }
    else
    {
        std::cout << "(" << str2 << ") Could not find w" << std::endl;
    }

    return 0;
}