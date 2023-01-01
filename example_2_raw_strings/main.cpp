#include <iostream>
#include <string>

int main()
{
    // These type of strings are used to be formatted on print as formatted in the code 
    // prefix(optional) R"d-char-sequence(optional)(r-char-sequence(optional))d-char-sequence(optional)" 
    // (since C++11) from cppreference.com
    std::string raw_string_1 {R"(
    Let's go
    and have some
    "fun"
    )"};

    // can also assign char array or char pointer
    char char_array[100] {R"(
    This char array
    will be 
    "printed" 
    for sure
    )"};

    // Will give warning but will compile
    char* char_pointer {R"(
    This string literal
    will be 
    "printed" 
    for sure
    )"};

    // If same delimiter is used inside, then the starting and ending delimiters 
    // need to be different
    std::string raw_string_2 {R"--(
    Let's print ))
    "(THIS)"
    on the
    "(SCREEN)" ! 
    )--"};

    std::cout << raw_string_1 << std::endl;
    std::cout << char_array << std::endl;
    std::cout << char_pointer << std::endl;
    std::cout << raw_string_2 << std::endl;
}
