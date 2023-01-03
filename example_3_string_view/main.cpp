#include <iostream>
#include <string_view>

int main()
{
    
    char char_array[] {'H', 'I', 'G', 'H'};
    std::string string1 {"Hello again!"};

    // Avoid making unnecessary copies of strings, can only observe strings using this and not edit directly
    std::string_view sv1 {"HELLO"};
    std::string_view sv2 {string1};
    std::string_view sv3 {char_array, std::size(char_array)};

    std::cout << sv1 << std::endl;
    std::cout << sv2 << std::endl;
    std::cout << sv3 << std::endl; // Although not recommended to print non terminating char arrays, but safe with string_view

    std::cout << std::endl;

    // read only actual const char* (not to be  used on modified view like after remove suffix)
    std::cout << "sv2.data() : " << sv2.data() << std::endl;

    // Use front() and back() methods to get first and last char
    std::cout << "Front of sv1: " << sv1.front() << " Back of sv1: " << sv1.back() << std::endl;

    // remove some letters from front and then back (The actual string stays unaffected)
    sv2.remove_prefix(6);
    sv2.remove_suffix(1);

    std::cout << std::endl;
    std::cout << "sv2 : " << sv2 << std::endl;
    std::cout << "string1 : " << string1 << std::endl;

    return 0;
}
